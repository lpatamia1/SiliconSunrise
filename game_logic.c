#include "character.h"
#include <stdio.h>

void playGame(Node *startNode) {
    NodeStack gameStack;
    gameStack.top = -1;  // initializing stack
    push(&gameStack, startNode);  // starting the game with the initial node

    Node *currentNode;
    int choice;

    while (gameStack.top != -1) {
        currentNode = pop(&gameStack);
        printf("%s\n", currentNode->description);

        for (int i = 0; i < 3; i++) {
            if (currentNode->choices[i].text != NULL) {
                printf("%d. %s\n", i + 1, currentNode->choices[i].text);
            }
        }

        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice >= 1 && choice <= 3 && currentNode->choices[choice - 1].text != NULL) {
            push(&gameStack, currentNode->choices[choice - 1].next);
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    }

    printf("The game has ended. Reflect on your journey!\n");
}
