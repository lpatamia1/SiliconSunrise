#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int bravery;
    int intellect;
    int loyalty;
    int spellCasting;
    int potionMaking;
    int flying;
} HogwartsStudent;

HogwartsStudent createStudent();
void updateAttributes(HogwartsStudent *student, int bravery, int intellect, int loyalty);

#endif
