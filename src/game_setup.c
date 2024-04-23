#include "game_logic.h"
#include <stdlib.h>

Node* setupGame() {
    static Node startNode = {
        "You wake up in a strange, dimly lit room with three doors.",
        {
            {"Open the left door", "You find a library filled with ancient books.", {5, 0, 0}, NULL},
            {"Open the middle door", "You enter a dark hallway. At the end is a flickering light.", {0, 5, 0}, NULL},
            {"Open the right door", "You discover a room full of mechanical devices.", {0, 0, 5}, NULL}
        }
    };
    static Node libraryNode = {
        "You are in the library. There's a desk with a mysterious book on it.",
        {
            {"Read the book", "The book reveals secrets of the arcane.", {0, 2, 0}, NULL},
            {"Leave the book", "You leave the book untouched and head back.", {0, -1, 0}, &startNode},
            {"", "", {0}, NULL}
        }
    };
    static Node hallwayNode = {
        "The hallway leads you to an underground lab.",
        {
            {"Explore the lab", "You find notes on experiments with time.", {0, 0, 1}, NULL},
            {"Return", "Feeling uneasy, you decide to return to the room.", {0, 0, -1}, &startNode},
            {"", "", {0}, NULL}
        }
    };
    static Node deviceRoomNode = {
        "The room's machines whir quietly.",
        {
            {"Examine machines", "You find a device that appears to control elements.", {1, 0, 0}, NULL},
            {"Leave the room", "You exit the room, pondering its purpose.", {0, 0, 0}, &startNode},
            {"", "", {0}, NULL}
        }
    };

    startNode.choices[0].next = &libraryNode;
    startNode.choices[1].next = &hallwayNode;
    startNode.choices[2].next = &deviceRoomNode;

    libraryNode.choices[0].impact = (Attributes){0, 2, 0}; 
    libraryNode.choices[1].impact = (Attributes){0, -1, 0}; 

    hallwayNode.choices[0].impact = (Attributes){0, 0, 1}; 
    hallwayNode.choices[1].impact = (Attributes){0, 0, -1}; 

    deviceRoomNode.choices[0].impact = (Attributes){1, 0, 0}; 
    deviceRoomNode.choices[1].impact = (Attributes){0, 0, 0}; 

    return &startNode; 
}
