#include <iostream>

#include "data.hpp"

Data::Data(int level, int args)
{
    double prob = level / (double) args;

    //Must be less(<) otherwise it could generate 0 and
    //generate a variable at the 0th level
    if((std::rand() / (double) RAND_MAX) < prob)
    {
        //generate a variable
        this->num = std::rand() % args;
        this->type = Num;
    }
    else
    {
        //generate an operand
        this->num = -1.0;
        this->type = static_cast<Types>((std::rand() % 4) + 1);
    }
}
