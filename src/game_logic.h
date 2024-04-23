#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "character.h"

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

void playGame(Node *startNode, Attributes *player);
Node* setupGame();
void push(NodeStack *stack, Node *node);
Node* pop(NodeStack *stack);

#endif