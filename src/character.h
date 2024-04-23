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

void updateSkills(HogwartsStudent *student, int spellCasting, int potionMaking, int flying);

#endif
