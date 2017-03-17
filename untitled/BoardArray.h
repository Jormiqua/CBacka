//
// Created by Raphael on 3/8/2017.
//

#ifndef UNTITLED_BOARDARRAY_H
#define UNTITLED_BOARDARRAY_H


#include <vector>
#include "Move.h"
#include "Play.h"

class BoardArray
{
private:
    int array [26][2] = {0};
public:
    int* getArray();
    void print();
    void print_line(int position);
    int array_lenght [2] = {26, 2};
    void set_value(int position, int column, int value);
    void move_token(int oldPosition, int newPosition, int column);
    void move_token(Move move);
    int get_value(int position, int column);
    void remove_one_token(int position, int column);
    void add_one_token(int position, int column);
    void move_token_to_jail(int position, int column);
    bool thereIsATokenThere(int position, int column);
    bool thereIsAtLeastTwoToken(int position, int column);
    bool thereIsATokenInJail(int column);
    bool allTokensAreInSafeArea(int column);
    bool thereIsATokenInHigherPosition(int column, int position);
    std::vector<int> allNonEmptyPositions(int column);
    BoardArray playPlay(Play play);
    bool gameIsOver(int column);
    void initializeArray();
    std::string array_to_code();
    void setArrayFromCode(std::string);

    static char to_hex(int i);
    static int from_hex(char c);

};


#endif //UNTITLED_BOARDARRAY_H
