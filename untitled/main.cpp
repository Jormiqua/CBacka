#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>
#include <cmath>
#include "BoardArray.h"
#include "ColorManagement.h"
#include "RuleBook.h"
#include "AutoPlayer.h"
#include "Game.h"


int main()
{
/////Test
//    BoardArray ba = BoardArray();
//    ba.set_value(22, 0, 1);
//    ba.set_value(23, 0, 5);
//    ba.set_value(24, 0, 7);
//    ba.set_value(25, 0, 2);
//
//    ba.set_value(0, 1, 4);
//    ba.set_value(1, 1, 2);
//    ba.set_value(2, 1, 2);
//    ba.set_value(3, 1, 7);
//
//    ba.print();
//
//    auto plays = RuleBook::getAllLegalPlays(ba, vector<int>({4, 4, 4, 4}), Colors::WHITE);
////
//    for (int i = 0; i < plays.size(); i++)
//    {
//        plays[i].print();
//    }


///// Game
    AutoPlayer whitePlayer = AutoPlayer();
    AutoPlayer blackPlayer = AutoPlayer();

    Game game = Game((Player *) &whitePlayer, (Player *) &blackPlayer);

    game.log = true;

    auto bb = game.startGame();

/// Test

//BoardArray ba = BoardArray();
//ba.initializeArray();
//std::cout << (char) (48 + 3) << std::endl;
//std::cout << std::to_string( (int) 'A') << std::endl;
//std::cout << BoardArray::to_hex(8) << std::endl;
//std::cout << BoardArray::from_hex('B') << std::endl;
//std::cout << ba.array_to_code() << std::endl;
//ba.setArrayFromCode(ba.array_to_code());
//std::cout << ba.array_to_code() << std::endl;


//std::cout << std::exp(0) << std::endl;

///Debug

//BoardArray ba = BoardArray();
//ba.setArrayFromCode("04_07_04_00_00_00_00_10_00_00_00_00_00_00_00_00_00_00_00_00_00_00_00_10_D0_00_");
//std::vector<int> dices({3, 5});
//
//auto plays = RuleBook::getAllLegalPlays(ba, vector<int>(dices), Colors::WHITE);
//for (int i = 0; i < plays.size(); i++)
//{
//    plays[i].print();
//}
//
//std::cout << "Picked play" << std::endl;
//AutoPlayer player;
//auto playAndScore = player.play(ba, RuleBook::getAllLegalPlays(ba, dices, Colors::WHITE), Colors::WHITE);
//playAndScore.first.print();


    return 0;
}