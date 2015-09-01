#ifndef DATA_HPP
#define DATA_HPP

enum Types { Num, Sum, Sub, Div, Mult };

class Data
{
private:
    double num;
    Types type;
public:
    Types get_type() { return type; }
    double get_num() { return num; }
};

#endif
