//
// Created by Raphael on 3/14/2017.
//

#include <iostream>
#include <ctime>
#include <tuple>
#include "Game.h"
#include "RuleBook.h"
#include "AutoPlayer.h"

std::tuple<Colors, int, std::vector<BoardArray>> Game::startGame()
{

    int numberOfTurn = 0;
    playerWhite->whatAmI();
    bool gameIsOver = false;
    Player *activePlayer = playerWhite;
    std::vector<BoardArray> boards;
    boards.push_back(this->ba);

    while (!gameIsOver)
    {
        numberOfTurn++;
        Colors activeColor = activePlayer->getColor();
        auto dices = diceGenerator();
        std::vector<Play> plays = RuleBook::getAllLegalPlays(ba, dices, activeColor);
        std::pair<Play, float> playAndScore = activePlayer->play(ba, activeColor, plays);
        ba = ba.playPlay(playAndScore.first);

        if (this->log)
        {
            std::cout << diceToString(dices, activePlayer->getColor()) << std::endl;
            playAndScore.first.print();
            std::cout << ba.array_to_code() << std::endl;
        }

        gameIsOver = ba.gameIsOver(ColorManagement::column(activeColor));

        if (gameIsOver && this->log)
        {
            std::cout<<" Player " + ColorManagement::name(activeColor) + " wins in " + std::to_string(numberOfTurn) + " turns."<<std::endl;
        }

        if (playerWhite->getColor() == activeColor)
        {
            activePlayer = playerBlack;
        } else
        {
            activePlayer = playerWhite;
        }

    }

    return std::make_tuple(activePlayer->getColor(), numberOfTurn, boards);
}

std::vector<int> Game::diceGenerator()
{
    std::vector<int> dices;
    dices.push_back(rand() % 6 + 1);
    dices.push_back(rand() % 6 + 1);

    if (dices[0] == dices[1])
    {
        dices.push_back(dices[0]);
        dices.push_back(dices[0]);
    }

    return dices;
}

std::string Game::diceToString(std::vector<int> dices, Colors color)
{
    string string1 = "Player " + ColorManagement::name(color) + " rolled [";
    for (int i = 0; i< dices.size(); i++)
    {
        string1 = string1 + to_string(dices[i]);
        if (i == dices.size() - 1)
        {
            string1 = string1 + "]";
        }else
        {
         string1 = string1 + ", ";
        }
    }

    return string1;
}

Game::Game(Player *playerWhite, Player *playerBlack) : playerWhite(playerWhite), playerBlack(playerBlack)
{
    srand ((unsigned int) time(NULL));
    playerWhite->setColor(Colors::WHITE);
    playerBlack->setColor(Colors::BLACK);
    this->ba.initializeArray();
}
