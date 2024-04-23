#include "game_logic.h"
#include <stdio.h>

void push(NodeStack *stack, Node *node) {
    if (stack->top < (sizeof(stack->items) / sizeof(Node*) - 1)) {
        stack->items[++stack->top] = node;
    } else {
        printf("Stack Overflow\n");
    }
}

Node* pop(NodeStack *stack) {
    if (stack->top >= 0) {
        return stack->items[stack->top--];
    } else {
        printf("Stack Underflow\n");
        return NULL;
    }
}

Node* setupGame() {
    static Node startNode = {
        "You find yourself at the entrance of a mysterious cave.",
        {
            {"Enter the cave", "You step into the darkness...", {0}, NULL},
            {"Walk away", "You decide to return another day...", {0}, NULL},
            {"", "", {0}, NULL}
        }
    };
    static Node caveNode = {
        "Inside the cave, you see two paths.",
        {
            {"Take the left path", "The path leads to a dead end.", {0}, NULL},
            {"Take the right path", "You find a small chest.", {0}, NULL},
            {"Go back", "You head back to the entrance.", {0}, &startNode}
        }
    };
    startNode.choices[0].next = &caveNode;
    return &startNode;
}

void playGame(Node *startNode) {
    NodeStack gameStack = {.top = -1};
    push(&gameStack, startNode);

    Node *currentNode;
    int choice;

    while ((currentNode = pop(&gameStack)) != NULL) {
        printf("%s\n", currentNode->description);
        for (int i = 0; currentNode->choices[i].text[0] != '\0'; ++i) {
            printf("%d. %s\n", i + 1, currentNode->choices[i].text);
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
        --choice;

        if (choice >= 0 && choice < 3 && currentNode->choices[choice].text[0] != '\0') {
            if (currentNode->choices[choice].next) {
                push(&gameStack, currentNode->choices[choice].next);
            }
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("The game has ended. Reflect on your journey!\n");
}

int loadScenes(const char* filename) {
    return 0; 
}
