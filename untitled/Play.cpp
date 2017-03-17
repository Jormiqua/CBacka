//
// Created by Raphael on 3/12/2017.
//

#include <iostream>
#include "Play.h"

const std::vector<Move> &Play::getMoves() const
{
    return moves;
}

void Play::setMoves(const std::vector<Move> &moves)
{
    Play::moves = moves;
}

int Play::getNumberOfMoves() const
{
    return numberOfMoves;
}

void Play::setNumberOfMoves(int numberOfMoves)
{
    Play::numberOfMoves = numberOfMoves;
}

int Play::getHigherDice() const
{
    return higherDice;
}

void Play::setHigherDice(int higherDice)
{
    Play::higherDice = higherDice;
}

float Play::getRuleScore() const
{
    return ruleScore;
}

void Play::setRuleScore(float ruleScore)
{
    Play::ruleScore = ruleScore;
}

void Play::addMove(Move move)
{
    this->moves.push_back(move);
    this->numberOfMoves++;

    if (this->higherDice < move.getDice())
    {
        this->higherDice = move.getDice();
    }

    this->updateScore();

}

void Play::updateScore()
{
    if (this->ruleScore == 0)
    {
        this->ruleScore = (float) this-> higherDice / 10;
    }
    else
    {
        this->ruleScore = this->numberOfMoves;
    }
}

Play::Play()
{
    this->ruleScore = 0;
    this->higherDice = 0;
    this->ruleScore = 0;
    this->numberOfMoves = 0;
    this->moves = std::vector<Move>();
}

Play Play::copyAndAddMove(Move move)
{
    Play  play = Play(*this);
    play.addMove(move);
    return play;

}

std::string Play::to_string()
{
    std::string string = "Play: \n";

    for (int i = 0; i < this->moves.size(); i++)
    {
        std::string start_char(2 * i,' ');
        string = string + start_char + "Token " + std::to_string((this->moves)[i].getOld_position()) + " moves to " + std::to_string((this->moves)[i].getNew_position()) + " with dice " + std::to_string((this->moves)[i].getDice()) + " \n" ;
    }

    return string;

}

void Play::print()
{
    std::cout << this->to_string() << std::endl;
}




