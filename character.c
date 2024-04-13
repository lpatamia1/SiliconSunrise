#include <stdio.h>

typedef struct {
    int intelligence;
    int courage;
    int charisma;
    int spellCasting;
    int potionMaking;
    int flying;
} HogwartsStudent;

HogwartsStudent createStudent() {
    HogwartsStudent newStudent = {5, 5, 5, 1, 1, 1};
    return newStudent;
}
