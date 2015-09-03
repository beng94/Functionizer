#ifndef DATA_HPP
#define DATA_HPP

enum Types { Num = 0, Sum, Sub, Div, Mult };

class Data
{
private:
    int arg_id;
    Types type;

public:
    Data(int, int);
    Types get_type() { return type; }
    int get_arg_id() { return arg_id; }
    double get_num() { return num; }
};

#endif
