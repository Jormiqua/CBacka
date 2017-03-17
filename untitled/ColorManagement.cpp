//
// Created by Raphael on 3/10/2017.
//


#include "ColorManagement.h"

int ColorManagement::column(Colors colors)
{
    return colors == Colors::WHITE ? 0 : 1;
}

std::string ColorManagement::name(Colors colors)
{
    return (std::string) (colors == Colors::WHITE ? "WHITE" : "BLACK");
}

int ColorManagement::jailPosition(Colors colors)
{
    return colors == Colors::WHITE ? 0 : 25;
}

int ColorManagement::otherColumn(int column)
{
    return 1 - column;
}

Colors ColorManagement::getColor(int column)
{
    return column == 0 ? Colors::WHITE : Colors::BLACK;
}

Colors ColorManagement::otherColor(Colors color)
{
    return color == Colors::WHITE ? Colors::BLACK : Colors::WHITE;
}

int ColorManagement::sign(Colors colors)
{
    return colors == Colors::WHITE ? 1 : -1;
}

int ColorManagement::homePosition(Colors colors)
{
    return colors == Colors::WHITE ? 25: 0;
}
