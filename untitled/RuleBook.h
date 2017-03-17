//
// Created by Raphael on 3/10/2017.
//

#ifndef UNTITLED_RULEBOOK_H
#define UNTITLED_RULEBOOK_H


#include <vector>
#include <array>
#include "Move.h"
#include "BoardArray.h"
#include "Brain.h"
#include "Play.h"

class RuleBook
{
private:
    static std::vector<Play> addAllLegitMovesOneDice(BoardArray ba, Colors color, int dice, Play play);
    static vector<Play> increaseVectorWithNextPlay(BoardArray ba, Colors color, int dice, vector<Play> plays);
    static vector<Play> getAllExistingPlaysForOnePermutation(BoardArray ba, Colors color, std::vector<int> dices);
    static int getEndPosition(int startPosition, int dice, Colors color);
public:
    static bool isMoveLegal(BoardArray ba, Move move);
    static vector<Play> getAllLegalPlays(BoardArray ba, std::vector<int> dices, Colors color);
    static std::vector<std::vector<int>> getAllDicePermutation(std::vector<int> dices);

    static vector<Play> filterPlayBasedOnPlayScore(vector<Play> plays);
};


#endif //UNTITLED_RULEBOOK_H
