#include "character.h"

HogwartsStudent createStudent() {
    // Initialize the student with default values
    HogwartsStudent newStudent = {5, 5, 5, 1, 1, 1};
    return newStudent;
}

void updateAttributes(HogwartsStudent *student, int bravery, int intellect, int loyalty) {
    // Update student attributes based on choices made in the game
    student->bravery += bravery;
    student->intellect += intellect;
    student->loyalty += loyalty;
}
