#include <cstdlib>
#include <sstream>
#include <stdexcept>

#include "node.hpp"

Node::Node(const Node* node)
{
    this->data = node->data;
    if(node->rChild != NULL)
        this->rChild = new Node(node->rChild);
    else this->rChild = NULL;
    if(node->lChild != NULL)
        this->lChild = new Node(node->lChild);
    else this->lChild = NULL;
}

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

    Node* choosen = prob < 0.5 ? lhs : rhs;
    Node* not_choosen = choosen == lhs ? rhs : lhs;

    Node *new_node = new Node(choosen->data);

    if(choosen->data.get_type() == Num)
    {
        new_node->lChild = NULL;
        new_node->rChild = NULL;
        return new_node;
    }

    if(not_choosen->data.get_type() == Num)
    {
        new_node->lChild = new Node(choosen->lChild);
        new_node->rChild = new Node(choosen->rChild);
        return new_node;
    }

    new_node->lChild = get_rand_child(lhs->lChild, rhs->lChild);
    new_node->rChild = get_rand_child(lhs->rChild, rhs->rChild);
    return new_node;
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
