#include <mutex>
#include <cstdlib>
#include <ctime>
#include <iostream>

#include "data.hpp"

std::once_flag flag;

Data::Data(int level, int args)
{
    double prob = level / (double) args;

    //It's called only once, helps to generate a random num
    std::call_once(flag, []()
    {
        std::srand(std::time(0));
        std::cout << "Simple example: called once\n";
    });

    //Must be less(<) otherwise it could generate 0 and
    //generate a variable at the 0th level
    if((std::rand() / RAND_MAX) < prob)
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
