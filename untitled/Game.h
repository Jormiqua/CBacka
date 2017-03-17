//
// Created by Raphael on 3/14/2017.
//

#ifndef UNTITLED_GAME_H
#define UNTITLED_GAME_H


#include "Player.h"

class Game
{
public:
    Game(Player *playerWhite, Player *playerBlack);
    std::string diceToString(std::vector<int>, Colors color);

    Player *playerWhite;
    Player *playerBlack;
    BoardArray ba;
    bool log;

    std::tuple<Colors, int, std::vector<BoardArray>> startGame();
    std::vector<int> diceGenerator();
};


#endif //UNTITLED_GAME_H
