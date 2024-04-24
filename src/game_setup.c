#include "game_logic.h"
#include <stdio.h>
#include <stdlib.h>

Node* setupGame() {
    static Node startNode, hermioneNode, ronNode, nevilleNode, duelNode, flyingNode, saveHermioneNode, teachersAidNode, fluffyNode, focusStudiesNode, confrontQuirrellNode, reasonQuirrellNode, houseCupNode;

    Attributes intellectImpact = {0, 5, 0}; // Boost intellect
    Attributes braveryImpact = {5, 0, 0}; // Boost bravery
    Attributes loyaltyImpact = {0, 0, 5}; // Boost loyalty

    startNode = (Node){
            "\nYou arrive at Hogwarts and board the Hogwarts Express as a new student. You have just purchased your school supplies including a personalized wand. Who will you sit next to on the train?\n"
            "        ___                               ____\n"
            "   ___  \\ /  ___         ,'\\_            | .-. \\        /|\n"
            "   \\ /  | |,'__ \\  ,'\\_  |   \\           | | | |      ,' |_   /|\n"
            " _ | |  | |\\/  \\ \\ |   \\ | |\\_|    __    | |_| |   _ '-. .-',' |_\n"
            "// | |  | |____| | | |\\_|| |__    / /    |     | ,'_`. | | '-. .-',__ ,'\\_\n"
            "\\\\_| |_,' .-, _  | | |   | |\\ \\  / /    .| |\\_/ | / \\ || |   | | / |\\  \\|   \\\n"
            " `-. .-'| |/ / | | | |   | | \\ \\/ /     |  |    | | | || |   | | | |_\\ || |\\_|\n"
            "   | |  | || \\_| | | |   /_\\  \\  /      | |`    | | | || |   | | | .---'| |\n"
            "   | |  | |\\___,_\\ /_\\ _      / /       | |     | \\_/ || |   | | | |  /\\| |\n"
            "   /_\\  | |           //____ / /       .||`      `._,' | |   | | \\ `-' /| |\n"
            "        /_\\           `-------'         \\|              `.\\   `.\\ `._,' /_\\\n"
            "           A N D   T H E   S O R C E R E R ' S   S T O N E\n",

            {
                    {"Sit by Hermione.", &hermioneNode, intellectImpact},
                    {"Sit by Ron.", &ronNode, loyaltyImpact},
                    {"Sit by yourself and meet Neville.", &nevilleNode, braveryImpact}
            }
    };

    hermioneNode = (Node){
        "\nAfter choosing to sit by Hermione, you quickly realize her vast knowledge. Her guidance helps you understand the magical world better, preparing you for upcoming challenges.\n",
        {
            {"Continue to Duel with Malfoy.", &duelNode, {0, 0, 0}},
            {"Focus on your studies.", &focusStudiesNode, {0, 2, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    ronNode = (Node){
        "\nChoosing Ron as your companion on the train, you find a loyal friend. His courage and loyalty will prove invaluable in the adventures that lie ahead.\n",
        {
            {"Continue to Duel with Malfoy.", &duelNode, {0, 0, 0}},
            {"Focus on your studies.", &focusStudiesNode, {0, 0, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    nevilleNode = (Node){
        "\nOpting to sit alone, you meet Neville. His genuine kindness and growing courage provide unique support throughout your journey at Hogwarts.\n",
        {
            {"Continue to Duel with Malfoy.", &duelNode, {0, 0, 0}},
            {"Focus on your studies.", &focusStudiesNode, {0, 0, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    duelNode = (Node){
        "\nMalfoy's taunt during a flying lesson challenges your bravery. How you handle this could set the tone for your reputation at Hogwarts.\n",
        {
            {"Confront Malfoy.", &confrontQuirrellNode, braveryImpact},
            {"Ignore and focus on flying.", &flyingNode, {0, 3, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

        flyingNode = (Node){
        "\nChoosing to ignore Malfoy and focus on the lesson, your flying skills improve significantly under Madam Hooch's guidance.\n",
        {
            {"Continue...", &saveHermioneNode, {0, 0, 0}},
            {"", NULL, {0, 0, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    saveHermioneNode = (Node){
        "\nYou come across Hermione struggling with a troll. You can save her or find a teacher to help.\n",
        {
            {"Help Hermione defeat the troll.", &teachersAidNode, braveryImpact},
            {"Find a teacher to help.", &teachersAidNode, intellectImpact},
            {"", NULL, {0, 0, 0}}
        }
    };

    teachersAidNode = (Node){
        "\nYou and Ron team up to defeat the troll, earning Hermione's gratitude.\n",
        {
            {"Continue to your next adventure...", &fluffyNode, {0, 0, 0}},
            {"", NULL, {0, 0, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    fluffyNode = (Node){
        "\nYou encounter Fluffy guarding a trapdoor. What will you do?\n",
        {
            {"Focus on the Sorcerer's Stone.", &reasonQuirrellNode, intellectImpact},
            {"Confront Quirrell.", &confrontQuirrellNode, braveryImpact},
            {"", NULL, {0, 0, 0}}
        }
    };

    focusStudiesNode = (Node){
        "\nYou dedicate yourself to your studies, impressing professors and gaining valuable knowledge.\n",
        {
            {"Continue to your next adventure...", &fluffyNode, {0, 0, 0}},
            {"", NULL, {0, 0, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    confrontQuirrellNode = (Node){
        "\nConfronting Quirrell, you discover his sinister plot to steal the Sorcerer's Stone. You must act quickly to save Hogwarts!\n",
        {
            {"Reason with Quirrell.", &reasonQuirrellNode, intellectImpact},
            {"Duel with Quirrell.", &houseCupNode, braveryImpact},
            {"", NULL, {0, 0, 0}}
        }
    };

    reasonQuirrellNode = (Node){
        "\nUsing your intellect, you uncover Quirrell's deception and prevent him from stealing the Sorcerer's Stone. Hogwarts is safe, and you are hailed as a hero!\n",
        {
            {"Congratulations! You've won the game!", NULL, {0, 0, 0}},
            {"", NULL, {0, 0, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    houseCupNode = (Node){
        "\nDueling Quirrell, you display great bravery but ultimately fall short. However, your courage inspires others, and Gryffindor wins the House Cup!\n",
        {
            {"Congratulations! You've won the game!", NULL, {0, 0, 0}},
            {"", NULL, {0, 0, 0}},
            {"", NULL, {0, 0, 0}}
        }
    };

    return &startNode;
}