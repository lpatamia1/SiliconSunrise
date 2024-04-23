#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "character.h"

typedef struct {
    Node* items[100]; 
    int top;
} NodeStack;

// Function prototypes
void playGame(Node *startNode);
void push(NodeStack *stack, Node *node);
Node* pop(NodeStack *stack);
Node* setupGame();

#endif
