// main.c
#include <stdio.h>
#include "game_logic.h" 

int main() {
    Node *startNode = setupGame();
    playGame(startNode); 
    return 0;
}