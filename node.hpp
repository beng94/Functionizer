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
    Node(const Node*);
    Node(Data);
    Node(int, int);
    ~Node();
    std::string write_dot(std::ofstream&);
    double eval_node(std::vector<double>);
    Node* get_rand_root(Node* rhs);
    Node* get_rChild() { return rChild; }
    Node* get_lChild() { return lChild; }
    void set_rChild(Node* node) { rChild = node; }
    void set_lChild(Node* node) { lChild = node; }

    Node operator=(Node*);

    friend Node* get_rand_child(Node* lhs, Node* rhs);
};

#endif
