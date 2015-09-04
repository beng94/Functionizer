#ifndef NODE_HPP
#define NODE_HPP

#include <fstream>
#include <string>
#include <vector>

#include "data.hpp"

class Node
{
private:
    Data data;
    Node* rChild;
    Node* lChild;

    double calc_operation(double, double);

public:
    Node(int, int);
    std::string write_dot(std::ofstream&);
    double eval_node(std::vector<double>);
};

#endif
