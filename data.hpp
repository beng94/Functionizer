#ifndef DATA_HPP
#define DATA_HPP

enum Types { Num = 0, Sum, Sub, Div, Mult };

class Data
{
private:
    double num;
    Types type;

public:
    Data(int, int);
    Types get_type() { return type; }
    double get_num() { return num; }
};

#endif
