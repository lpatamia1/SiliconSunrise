#include "game_logic.h"
#include <stdio.h>

void push(NodeStack *stack, Node *node) {
    if (stack->top < 99) {
        stack->items[++stack->top] = node;
    } else {
        printf("Stack Overflow\n");
    }
}

Node* pop(NodeStack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    }
    printf("Stack Underflow\n");
    return NULL;
}

void playGame(Node *startNode) {
    NodeStack gameStack;
    gameStack.top = -1;
    push(&gameStack, startNode); 
    Node *currentNode;
    int choice;

    while (gameStack.top != -1) {
        currentNode = pop(&gameStack);
        printf("%s\n", currentNode->description);

        for (int i = 0; i < 3; i++) {
            if (currentNode->choices[i].text[0] != '\0') { 
                printf("%d. %s\n", i + 1, currentNode->choices[i].text);
            }
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3 && currentNode->choices[choice - 1].text[0] != '\0') {
            push(&gameStack, currentNode->choices[choice - 1].next);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("The game has ended. Reflect on your journey!\n");
}
