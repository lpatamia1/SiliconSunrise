#include <stdio.h>
#include "game_logic.h"
#include "character.h"

int main() {
    Attributes player = createStudent(5, 5, 5, 1, 1, 1);
    Node* startNode = setupGame();
    playGame(startNode, &player);
    return 0;
}