//
// Created by Raphael on 3/10/2017.
//

#include <algorithm>
#include "RuleBook.h"
#include "ColorManagement.h"

bool RuleBook::isMoveLegal(BoardArray ba, Move move)
{
    return !(\
    (!ba.thereIsATokenThere(move.getOld_position(), move.getColumn())) || \
     (ba.thereIsAtLeastTwoToken(move.getNew_position(), ColorManagement::otherColumn(move.getColumn()))) || \
        (ba.thereIsATokenInJail(move.getColumn()) && !move.isLeavingJail()) || \
            (move.isGoingHome() && !ba.allTokensAreInSafeArea(move.getColumn())) || \
                (move.isLeavingHome()) || \
                    (move.isGoingHome() &&
                     ba.thereIsATokenInHigherPosition(move.getColumn(), move.getOld_position()) &&\
                       move.getDice() != move.getDistance()) \
);
}

std::vector<std::vector<int>> RuleBook::getAllDicePermutation(std::vector<int> dices)
{
    vector<vector<int>> perms;

    perms.push_back(dices);

    if (dices[0] == dices[1])
    {
        return perms;
    }

    while (std::next_permutation(&dices[0], &dices[0] + 2))
    {
        perms.push_back(dices);
    }

    return perms;
}

int RuleBook::getEndPosition(int startPosition, int dice, Colors color)
{
    return ColorManagement::sign(color) * min(startPosition * ColorManagement::sign(color) + dice, ColorManagement::homePosition(color));
}


std::vector<Play> RuleBook::addAllLegitMovesOneDice(BoardArray ba, Colors color, int dice, Play play)
{
    ba = ba.playPlay(play);
    std::vector<Play> plays;
    std::vector<int> startPosition = ba.allNonEmptyPositions(ColorManagement::column(color));

    for (int i = 0; i < startPosition.size(); i++)
    {
        Move move = Move(startPosition[i], getEndPosition(startPosition[i], dice, color), ColorManagement::column(color), dice);
        if (isMoveLegal(ba, move))
        {
            plays.push_back(play.copyAndAddMove(move));
        }
    }
    return plays;
}

std::vector<Play> RuleBook::increaseVectorWithNextPlay(BoardArray ba, Colors color, int dice, std::vector<Play> plays)
{
    vector<Play> increasedPlays;
    increasedPlays.push_back(Play());

    for (int pi = 0; pi <plays.size(); pi++)
    {
        auto oneIncreasedPlays = addAllLegitMovesOneDice(ba, color, dice, plays[pi]);
        increasedPlays.insert(increasedPlays.end(), oneIncreasedPlays.begin(), oneIncreasedPlays.end());
    }

    return  increasedPlays;
}

std::vector<Play> RuleBook::getAllExistingPlaysForOnePermutation(BoardArray ba, Colors color, std::vector<int> dices)
{

    std::vector<Play> plays;
    plays.push_back(Play());
    std::vector<int> nonEmptyPositions = ba.allNonEmptyPositions(ColorManagement::column(color));

    for (int di = 0; di < dices.size(); di++)
    {
        plays = increaseVectorWithNextPlay(ba, color, dices[di], plays);
    }

    return  plays;
}

std::vector<Play> RuleBook::getAllLegalPlays(BoardArray ba, std::vector<int> dices, Colors color)
{
    std::vector<std::vector<int>>  perms = RuleBook::getAllDicePermutation(dices);
    std::vector<Play> plays;

    for (int pi; pi < perms.size(); pi++)
    {
        auto playsFromOnePermutation = getAllExistingPlaysForOnePermutation(ba, color, perms[pi]);
        plays.insert(plays.end(), playsFromOnePermutation.begin(), playsFromOnePermutation.end());
    }

    return RuleBook::filterPlayBasedOnPlayScore(plays);
}

std::vector<Play> RuleBook::filterPlayBasedOnPlayScore(std::vector<Play> plays)
{
    float max = 0;

    for (int i = 0; i < plays.size(); i++)
    {
        if (plays[i].getRuleScore() > max)
        {
            max = plays[i].getRuleScore();
        }
    }

    std::vector<Play> filteredPlays;

    for (int i = 0; i < plays.size(); i++)
    {
        if (plays[i].getRuleScore() == max)
        {
            filteredPlays.push_back(plays[i]);
        }
    }

    return  filteredPlays;

}




