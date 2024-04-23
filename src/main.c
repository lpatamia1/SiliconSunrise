// main.c
#include <stdio.h>
#include "game_logic.h"
#include "character.h"

int main() {
    HogwartsStudent player = createStudent(5, 5, 5, 1, 1, 1);
    Node* startNode = setupGame();
    playGame(startNode);
    return 0;
}