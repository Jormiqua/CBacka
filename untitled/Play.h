//
// Created by Raphael on 3/12/2017.
//

#ifndef UNTITLED_PLAY_H
#define UNTITLED_PLAY_H


#include <vector>
#include "Move.h"
#include <string>


class Play
{
private:
    std::vector<Move> moves;
    int numberOfMoves;
    int higherDice;
    float ruleScore;
public:
    Play();

public:
    const std::vector<Move> &getMoves() const;
    void setMoves(const std::vector<Move> &moves);
    int getNumberOfMoves() const;
    void setNumberOfMoves(int numberOfMoves);
    int getHigherDice() const;
    void setHigherDice(int higherDice);
    float getRuleScore() const;
    void setRuleScore(float ruleScore);
    void addMove(Move move);
    Play copyAndAddMove(Move move);
    void updateScore();
    std::string to_string();
    void print();
};


#endif //UNTITLED_PLAY_H
