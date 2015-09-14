#ifndef DATA_HPP
#define DATA_HPP

#include <string>

enum Types { Num = 0, Sum, Sub, Div, Mult };

class Data
{
private:
    int arg_id;
    Types type;

public:
    Data(const Data&);
    Data(int, int);

    std::string get_str_type();
    Types get_type() { return type; }
    int get_arg_id() { return arg_id; }

    Data operator=(Data&);
};

#endif
