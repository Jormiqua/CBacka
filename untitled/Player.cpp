//
// Created by Raphael on 3/15/2017.
//

#include "Player.h"

Colors Player::getColor()
{
    return playerColor;
}

void Player::setColor(Colors color)
{
    playerColor = color;
}

string Player::whatAmI()
{
    return "A base player";
}

//Brain Player::getBrain()
//{
//    return Brain();
//}
