//
// Created by Raphael on 3/10/2017.
//

#ifndef UNTITLED_MOVE_H
#define UNTITLED_MOVE_H


class Move
{
private:
    int old_position;
    int new_position;
    int column;
    int dice;
public:
    int getDice() const;
    void setDice(int dice);


public:
    int getOld_position() const;
    void setOld_position(int old_position);
    int getNew_position() const;
    void setNew_position(int new_position);
    int getColumn() const;
    void setColumn(int column);
    bool isGoingToJail();
    bool isGoingHome();
    bool isLeavingJail();
    bool isLeavingHome();
    int getDistance();

    Move(int oldPosition, int newPosition, int column, int Dice);
};


#endif //UNTITLED_MOVE_H
