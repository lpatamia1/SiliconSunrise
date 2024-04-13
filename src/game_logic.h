#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include "character.h"

typedef struct {
    char background[1024];
    int numChoices;
    struct {
        char description[256];
        char outcome[256];
        Attributes impact;
        int nextSceneIndex;
    } choices[3];
} Scene;

int loadScenes(const char* filename);
void playGame();

#endif
