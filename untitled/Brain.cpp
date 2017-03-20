//
// Created by Raphael on 3/17/2017.
//

#include "Brain.h"

void Brain::turnBoardIntoInput(BoardArray ba, Colors playerColor, float *input)
{
    int counter = 0;
    for (int column = 0; column <= 1; column ++)
    {
        for (int threshold = 0; threshold <4; threshold++)
        {
            for (int position = 0; position < ba.array_lenght[0]; position++)
            {
                if (threshold != 3)
                    input[counter] = (int) ba.get_value(position, column) > threshold;

                if (threshold == 3)
                    input[counter] = max(((float)(ba.get_value(position, column) - 3) / 2), (float) 0);

                counter++;
            }
        }
    }

    input[counter] = playerColor == Colors::WHITE;
    input[counter + 1] = playerColor == Colors::BLACK;

}

float Brain::getScore(BoardArray ba, Colors playerColor)
{
    float **input;
    turnBoardIntoInput(ba, playerColor, *input);
    return NN.computeScore(*input);
}

std::pair<Play, float> Brain::pickBestPlay(BoardArray ba, Colors playerColor, std::vector<Play> plays)
{
    float probabilityOfVictory = -1;
    Play bestPlay;
    float probabilityOfVictoryIfPlay;
    BoardArray futureBoard;

    for (int i = 0; i < plays.size(); i++)
    {
        futureBoard = ba.playPlay(plays[i]);
        probabilityOfVictoryIfPlay = 1 - getScore(futureBoard, ColorManagement::otherColor(playerColor));

        if (probabilityOfVictory < probabilityOfVictoryIfPlay)
        {
            probabilityOfVictory = probabilityOfVictoryIfPlay;
            bestPlay = plays[i];
        }
    }

    return std::make_pair(bestPlay, probabilityOfVictoryIfPlay);
}

std::string Brain::whatAmI()
{
    return "A basic brain";
}

