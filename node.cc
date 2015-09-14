#include <cstdlib>
#include <sstream>
#include <stdexcept>

#include "node.hpp"

Node::Node(Data d) : data{d}, rChild{NULL}, lChild{NULL} {}

Node::Node(int level, int args) : data{level, args}
{
    if(this->data.get_type() != Num)
    {
        this->rChild = new Node(level + 1, args);
        this->lChild = new Node(level + 1, args);
    }
    else
    {
        //data.num will store the id of the variable in a std::vector
        this->rChild = NULL;
        this->lChild = NULL;
    }
}

std::string Node::write_dot(std::ofstream& file)
{
    std::ostringstream parent;
    parent << this->data.get_type() << this;
    file << "\"" << parent.str() << "\"" << "[label=\"" << this->data.get_str_type() << "\"]\n";

    if(this->rChild)
    {
        std::ostringstream srChild;
        srChild << this->rChild->write_dot(file) << this->rChild;
        file << "\"" << srChild.str() << "\"" << "[label=\"" << this->rChild->data.get_str_type() << "\"]\n";
        file << "\"" << parent.str() << "\"" << " -> " << "\"" << srChild.str() << "\"" << ";\n";
    }
    if(this->lChild)
    {
        std::ostringstream slChild;
        slChild << this->lChild->write_dot(file) << this->lChild;
        file << "\"" << slChild.str() << "\"" << "[label=\"" << this->lChild->data.get_str_type() << "\"]\n";
        file << "\"" << parent.str() << "\"" << " -> " << "\"" << slChild.str() << "\"" << ";\n";
    }

    return std::to_string(this->data.get_type());
}

double Node::calc_operation(double a, double b )
{
    switch(this->data.get_type())
    {
        case Num: throw std::invalid_argument("calc_operation received a Num");
        case Sum: return a + b;
        case Sub: return a - b;
        case Div: return (b == 0) ? (0) : a / b;
        case Mult: return a * b;
    };

    return -1.0;
}

double Node::eval_node(std::vector<double> vars)
{
    if(this->data.get_type() == Num)
        return vars[this->data.get_arg_id()];

    double rResult = this->rChild->eval_node(vars);
    double lResult = this->lChild->eval_node(vars);

    return this->calc_operation(rResult, lResult);
}

Node* get_rand_child(Node* lhs, Node* rhs)
{
    double prob = std::rand() / (double) RAND_MAX;

    Node* new_node;
    if(prob < 0.5)
    {
        if(lhs == NULL) return NULL;
        new_node = new Node(lhs->data);
    }
    else
    {
        if(rhs == NULL) return NULL;
        new_node = new Node(rhs->data);
    }

    new_node->rChild = get_rand_child(lhs ? lhs->rChild : NULL, rhs ? rhs->rChild : NULL);
    new_node->lChild = get_rand_child(lhs ? lhs->lChild : NULL, rhs ? rhs->lChild : NULL);

    return new_node;
}

Node* Node::get_rand_root(Node* rhs)
{
    double prob = std::rand() / (double) RAND_MAX;

    Data rand_data = prob < 0.5 ? this->data : rhs->data;
    return new Node(rand_data);
}

Node Node::operator=(Node* rhs)
{
    this->data = rhs->data;
    this->rChild = rhs->rChild;
    this->lChild = rhs->lChild;

    rhs->rChild = NULL;
    rhs->lChild = NULL;

    delete rhs;

    return *this;
}

Node::~Node()
{
    if(this->rChild) delete this->rChild;
    if(this->lChild) delete this->lChild;

    delete this;
}
