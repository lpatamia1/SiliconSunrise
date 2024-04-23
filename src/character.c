#include "character.h"

HogwartsStudent createStudent() {
    HogwartsStudent newStudent = {5, 5, 5, 1, 1, 1};
    return newStudent;
}

void updateAttributes(HogwartsStudent *student, int bravery, int intellect, int loyalty) {
    student->bravery += bravery;
    student->intellect += intellect;
    student->loyalty += loyalty;
}

void updateSkills(HogwartsStudent *student, int spellCasting, int potionMaking, int flying) {
    student->spellCasting += spellCasting;
    student->potionMaking += potionMaking;
    student->flying += flying;
}
