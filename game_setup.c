#include "character.h"
#include "game_logic.h"

// defining nodes for different scenarios
static Node startGame, endGame, discoveringMagic, halloweenTroll;

Node* setupGame() {
    // initializing nodes with story and choices
    startGame.description = "You're on the Hogwarts Express, about to begin your first year at Hogwarts.";
    startGame.choices[0].text = "Sit with Ron Weasley";
    startGame.choices[0].outcome = "Ron becomes a loyal friend.";
    startGame.choices[0].next = &discoveringMagic;
    startGame.choices[0].attributeImpact = (Attributes){1, 0, 0};

    // add more nodes here after but see if it works first
    
    return &startGame;
}
