#include <iostream>

#include "data.hpp"

Data::Data(const Data& d) : arg_id{d.arg_id}, type{d.type} {}

Data::Data(int level, int args)
{
    double prob = level / (double) args;

    //Must be less(<) otherwise it could generate 0 and
    //generate a variable at the 0th level
    if((std::rand() / (double) RAND_MAX) < prob)
    {
        //generate a variable
        this->arg_id = std::rand() % args;
        this->type = Num;
    }
    else
    {
        //generate an operand
        this->arg_id = -1;
        this->type = static_cast<Types>((std::rand() % 4) + 1);
    }
}

std::string Data::get_str_type()
{
    switch(this->type)
    {
        case Num: return std::to_string(this->arg_id);
        case Sum: return "+";
        case Sub: return "-";
        case Div: return "/";
        case Mult: return "*";
    };

    return "";
}

Data Data::operator=(const Data& rhs)
{
    this->arg_id = rhs.arg_id;
    this->type = rhs.type;

    return *this;
}
