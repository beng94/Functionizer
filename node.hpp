#ifndef NODE_HPP
#define NODE_HPP

#include <fstream>
#include <string>

#include "data.hpp"

class Node
{
private:
    Data data;
    Node* rChild;
    Node* lChild;

public:
    Node(int, int);
    std::string write_dot(std::ofstream&);
};

#endif
