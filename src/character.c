#include "character.h"

HogwartsStudent createStudent(int bravery, int intellect, int loyalty, int spellCasting, int potionMaking, int flying) {
    HogwartsStudent newStudent = {bravery, intellect, loyalty, spellCasting, potionMaking, flying};
    return newStudent;
}

void updateAttributes(HogwartsStudent *student, int bravery, int intellect, int loyalty) {
    student->bravery = (student->bravery + bravery >= 0) ? student->bravery + bravery : 0;
    student->intellect = (student->intellect + intellect >= 0) ? student->intellect + intellect : 0;
    student->loyalty = (student->loyalty + loyalty >= 0) ? student->loyalty + loyalty : 0;
}

void updateSkills(HogwartsStudent *student, int spellCasting, int potionMaking, int flying) {
    student->spellCasting = (student->spellCasting + spellCasting >= 0) ? student->spellCasting + spellCasting : 0;
    student->potionMaking = (student->potionMaking + potionMaking >= 0) ? student->potionMaking + potionMaking : 0;
    student->flying = (student->flying + flying >= 0) ? student->flying + flying : 0;
}

