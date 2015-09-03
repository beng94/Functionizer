#include <cstdlib>
#include <sstream>

#include "node.hpp"

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
