//
// Created by Raphael on 3/10/2017.
//

#include "Move.h"
#include "ColorManagement.h"

int Move::getOld_position() const
{
    return old_position;
}

void Move::setOld_position(int old_position)
{
    Move::old_position = old_position;
}

int Move::getNew_position() const
{
    return new_position;
}

void Move::setNew_position(int new_position)
{
    Move::new_position = new_position;
}

int Move::getColumn() const
{
    return column;
}

void Move::setColumn(int column)
{
    Move::column = column;
}

bool Move::isGoingToJail()
{
    return this->getNew_position() == ColorManagement::jailPosition(ColorManagement::getColor(this->column));
}

bool Move::isGoingHome()
{
    return this->getNew_position() == ColorManagement::homePosition(ColorManagement::getColor(this->column));
}

bool Move::isLeavingJail()
{
    return this->getOld_position() == ColorManagement::jailPosition(ColorManagement::getColor(this->column));
}

bool Move::isLeavingHome()
{
    return this->getOld_position() == ColorManagement::homePosition(ColorManagement::getColor(this->column));
}

int Move::getDistance()
{
    return abs(this->getNew_position() - this->getOld_position());
}

int Move::getDice() const
{
    return dice;
}

void Move::setDice(int dice)
{
    Move::dice = dice;
}

Move::Move(int oldPosition, int newPosition, int column, int dice)
{
    this->old_position = oldPosition;
    this->new_position = newPosition;
    this->column = column;
    this->dice = dice;
}


