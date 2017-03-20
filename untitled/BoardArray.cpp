//
// Created by Raphael on 3/8/2017.
//

#include <iostream>
#include "BoardArray.h"
#include "ColorManagement.h"

void BoardArray::print()
{

    std::cout << "This tokensArray is " + std::to_string(sizeof(this->tokensArray)) + " long " << std::endl;

    for (int i = 0; i < this->array_lenght[0]; i++ )
    {
        BoardArray::print_line(i);
    }
}

void BoardArray::move_token(int oldPosition, int newPosition, int column)
{
    BoardArray::remove_one_token(oldPosition, column);
    BoardArray::add_one_token(newPosition, column);

    if ((get_value(newPosition, ColorManagement::otherColumn(column)) == 1) && newPosition != 0 && newPosition != 25)
        move_token_to_jail(newPosition, ColorManagement::otherColumn(column));
}

void BoardArray::move_token_to_jail(int position, int column)
{
    BoardArray::remove_one_token(position, column);
    BoardArray::add_one_token(ColorManagement::jailPosition(ColorManagement::getColor(column)), column);
}

void BoardArray::set_value(int position, int column, int value)
{
    this->tokensArray[position][column] = value;
}

int BoardArray::get_value(int position, int column)
{
    return this->tokensArray[position][column];
}

void BoardArray::remove_one_token(int position, int column)
{
    this->tokensArray[position][column] --;
}

void BoardArray::add_one_token(int position, int column)
{
    this->tokensArray[position][column] ++;
}

void BoardArray::print_line(int position)
{
    std::string allignement_char = "  ";
    if (position > 9)
        allignement_char = " ";
    std::cout << "Line " + std::to_string(position) + allignement_char + " :  [" + std::to_string(this->tokensArray[position][0]) + ", " + std::to_string(this->tokensArray[position][1]) + "]"   << std::endl;

}

void BoardArray::move_token(Move move)
{
    BoardArray::move_token(move.getOld_position(), move.getNew_position(), move.getColumn());
}

bool BoardArray::thereIsATokenThere(int position, int column)
{
    return this->get_value(position, column) != 0;
}

bool BoardArray::thereIsAtLeastTwoToken(int position, int column)
{
    return this->get_value(position, column) > 1;
}

bool BoardArray::thereIsATokenInJail(int column)
{
    return get_value(ColorManagement::jailPosition(ColorManagement::getColor(column)), column) != 0;
}

bool BoardArray::allTokensAreInSafeArea(int column)
{
    int homePosition = ColorManagement::homePosition(ColorManagement::getColor(column));
    int sign = ColorManagement::sign(ColorManagement::getColor(column));

    return !thereIsATokenInHigherPosition(column, homePosition - 6 * sign);
}

bool BoardArray::thereIsATokenInHigherPosition(int column, int position)
{
    position -= ColorManagement::sign(ColorManagement::getColor(column));

    while (!(position == ColorManagement::jailPosition(Colors::WHITE) || position == ColorManagement::jailPosition(Colors::BLACK)))
    {
        if (get_value(position, column) != 0)
            return true;
        position -= ColorManagement::sign(ColorManagement::getColor(column));
    }

    return false;

}

std::vector<int> BoardArray::allNonEmptyPositions(int column)
{
    std::vector<int> nonEmptypy;

    for (int i = 0; i < 26; i++)
    {
        if (get_value(i, column) != 0)
            nonEmptypy.push_back(i);
    }
    return  nonEmptypy;
}

BoardArray BoardArray::playPlay(Play play)
{
    BoardArray ba = BoardArray(*this);
    for (int i = 0; i < play.getMoves().size(); i++)
    {
        ba.move_token(play.getMoves()[i]);
    }
    return ba;
}

bool BoardArray::gameIsOver(int column)
{
    return get_value(ColorManagement::homePosition(ColorManagement::getColor(column)), column) ==  15;
}

int* BoardArray::getArray()
{
    return *(this->tokensArray);
}

void BoardArray::initializeArray()
{
    this->tokensArray[1][0] = 2;
    this->tokensArray[6][1] = 5;
    this->tokensArray[8][1] = 3;
    this->tokensArray[12][0] = 5;
    this->tokensArray[13][1] = 5;
    this->tokensArray[17][0] = 3;
    this->tokensArray[19][0] = 5;
    this->tokensArray[24][1] = 2;
}

std::string BoardArray::array_to_code()
{
    std::string string;

    for (int i = 0; i < 26; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            string = string + to_hex(tokensArray[i][j]);
        }

        string = string + "_";
    }

    return string;
}
//
char BoardArray::to_hex(int i)
{
   return (char) (i < 10 ? i + 48 : 55 + i);
}

int BoardArray::from_hex(char c)
{
    int converted = (int) c;
    return (converted < 58 ? converted - 48: converted - 55);
}

void BoardArray::setArrayFromCode(std::string string)
{
    int position = 0;
    for (int i = 0; i < string.size(); i = i + 3)
    {
        this->set_value(position, 0, from_hex(string[i]));
        this->set_value(position, 1, from_hex(string[i  + 1]));
        position++;
    }
}

