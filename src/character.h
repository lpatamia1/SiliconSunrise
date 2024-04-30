#ifndef CHARACTER_H
#define CHARACTER_H

// Attributes structure represents various skills and qualities of a student character in a game.
typedef struct {
    int bravery;        // Represents courage and boldness.
    int intellect;      // Represents cognitive ability and knowledge.
    int loyalty;        // Represents faithfulness and allegiance.
    int spellCasting;   // Skill in casting spells.
    int potionMaking;   // Skill in brewing potions.
    int flying;         // Skill in flying, e.g., on a broomstick.
} Attributes;

// Function to create a new student with specified attributes and skills.
Attributes createStudent(int bravery, int intellect, int loyalty, int spellCasting, int potionMaking, int flying);

// Function to update the personal attributes of a student.
void updateAttributes(Attributes *student, int bravery, int intellect, int loyalty);

// Function to update the magical skills of a student.
void updateSkills(Attributes *student, int spellCasting, int potionMaking, int flying);

#endif // CHARACTER_H

