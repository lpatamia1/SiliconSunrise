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

// Function to create a new HogwartsStudent with initial values
HogwartsStudent createStudent();

// Function to update the student's attributes
void updateAttributes(HogwartsStudent *student, int bravery, int intellect, int loyalty);

// New function to update skills
void updateSkills(HogwartsStudent *student, int spellCasting, int potionMaking, int flying);

#endif
