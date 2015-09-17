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
    Data() {}
    Data(const Data&);
    Data(int, int);

    std::string get_str_type();
    Types get_type() const { return type; }
    int get_arg_id() const { return arg_id; }

    Data operator=(const Data&);
};

#endif
