#ifndef CHARACTER_H
#define CHARACTER_H

typedef struct {
    int bravery;
    int intellect;
    int loyalty;
    int spellCasting;
    int potionMaking;
    int flying;
} Attributes;

Attributes createStudent(int bravery, int intellect, int loyalty, int spellCasting, int potionMaking, int flying);

void updateAttributes(Attributes *student, int bravery, int intellect, int loyalty);

void updateSkills(Attributes *student, int spellCasting, int potionMaking, int flying);

#endif
