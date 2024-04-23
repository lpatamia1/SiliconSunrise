#include "character.h"

Attributes createStudent(int bravery, int intellect, int loyalty, int spellCasting, int potionMaking, int flying) {
    Attributes newStudent = {bravery, intellect, loyalty, spellCasting, potionMaking, flying};
    return newStudent;
}

void updateAttributes(Attributes *student, int bravery, int intellect, int loyalty) {
    student->bravery += bravery;
    student->intellect += intellect;
    student->loyalty += loyalty;
}

void updateSkills(Attributes *student, int spellCasting, int potionMaking, int flying) {
    student->spellCasting += spellCasting;
    student->potionMaking += potionMaking;
    student->flying += flying;
