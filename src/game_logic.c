#include "game_logic.h"
#include <stdio.h>
#include <stdlib.h>

// Function to add a node to the stack
void push(NodeStack *stack, Node *node) {
    if (stack->top < 99) {
        stack->items[++stack->top] = node;
    } else {
        fprintf(stderr, "Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
}

// Function to remove and return the top node from the stack
Node* pop(NodeStack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        fprintf(stderr, "Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
}

// The game's main play loop
void playGame(Node *startNode, Attributes *player) {
    NodeStack gameStack = {.top = -1};
    push(&gameStack, startNode);

    Node *currentNode;
    int choice;
    int validChoice;

    while ((currentNode = pop(&gameStack)) != NULL) {
        do {
            printf("%s\n", currentNode->description);
            for (int i = 0; i < 3 && currentNode->choices[i].text[0] != '\0'; ++i) {
                printf("%d. %s\n", i + 1, currentNode->choices[i].text);
            }

            printf("\nEnter your choice: ");
            scanf("%d", &choice);
            --choice;  // Adjust choice to be zero-indexed

            validChoice = (choice >= 0 && choice < 3 && currentNode->choices[choice].next != NULL);

            if (!validChoice) {
                printf("Invalid choice. Please try again.\n");
            }
        } while (!validChoice);

        push(&gameStack, currentNode->choices[choice].next);
    }

    printf("The game has ended. Reflect on your journey!\n");
}
