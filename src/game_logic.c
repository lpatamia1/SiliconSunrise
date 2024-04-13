#include "character.h"
#include "game_logic.h"

#include <stdio.h>

void gameLoop(HogwartsStudent *student) {
    int choice;
    while (1) {  // Simple loop for demonstration, replace with actual game end conditions
        printf("Choose an action:\n1. Explore the castle\n2. Study in the library\n3. Visit Hagrid\nEnter choice: ");
        scanf("%d", &choice);
        handleDecision(choice, student);
        if (choice == 0) break;  // Assume 0 is quit for simplicity
    }
}

void handleDecision(int choice, HogwartsStudent *student) {
    switch (choice) {
        case 1:
            exploreCastle(student);
            break;
        case 2:
            studyInLibrary(student);
            break;
        case 3:
            visitHagrid(student);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
    }
}
