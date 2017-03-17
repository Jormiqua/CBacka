//
// Created by Raphael on 3/13/2017.
//

#include "AutoPlayer.h"

std::pair<Play, float> AutoPlayer::pickBestPlay(BoardArray ba, Colors playerColor, std::vector<Play> plays)
{
    float min_score_for_other_player = 1;
    Play best_play = Play();

    for (int i = 0; i < plays.size(); i++)
    {
        if (this->brain.scoreBoard(ba.playPlay(plays[i]), ColorManagement::otherColor(playerColor)) < min_score_for_other_player)
        {
            best_play = plays[i];
            min_score_for_other_player = this->brain.scoreBoard(ba.playPlay(plays[i]), ColorManagement::otherColor(playerColor));
        }
    }
    std::pair<Play, float> to_return (best_play, (float) 1 - min_score_for_other_player);
    return to_return;

}
