//
// Created by Raphael on 3/10/2017.
//

#pragma once
#include "../../../../MinGW/lib/gcc/mingw32/5.3.0/include/c++/string"

enum class Colors {WHITE, BLACK};

using namespace std;
class ColorManagement
{
public:
    static int column(Colors colors);
    static string name(Colors colors);
    static int jailPosition(Colors colors);
    static int homePosition(Colors colors);
    static int sign(Colors colors);
    static int otherColumn(int column);
    static Colors getColor(int column);
    static Colors otherColor(Colors colors);
};

