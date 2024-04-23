#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "character.h"

typedef struct Node {
    char description[1024];
    struct Choice {
        char text[256];
        char outcome[256];
        Attributes impact;
        struct Node* next;
    } choices[3];
} Node;

typedef struct {
    Node* items[100];
    int top;
} NodeStack;

// Function Prototypes
void playGame(Node *startNode, HogwartsStudent *player);
void push(NodeStack *stack, Node *node);
Node* pop(NodeStack *stack);
Node* setupGame();
int loadScenes(const char* filename);

#endif