#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "character.h" // Assumes this header defines Attributes

typedef struct Node {
    char description[1024];
    struct Choice {
        char text[256];
        struct Node* next;
        Attributes impact;
    } choices[3];
} Node;

typedef struct {
    Node* items[100];
    int top;
} NodeStack;

// Prototypes for functions that manage the game logic
void push(NodeStack *stack, Node *node);
Node* pop(NodeStack *stack);
void playGame(Node *startNode, Attributes *player);

// Declare setupGame function
Node* setupGame(void);  // Ensure this is only declared and not defined in game_logic.c

#endif // GAME_LOGIC_H
