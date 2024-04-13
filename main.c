#include <stdio.h>
#include "character.h"

int main() {
    printf("Welcome to Hogwarts: The Adventure Begins!\n");
    HogwartsStudent player = createStudent();  // Function to initialize character stats
    gameLoop(&player);  // Main game loop to handle game progression
    return 0;
}

