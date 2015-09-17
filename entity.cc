#include "entity.hpp"
#include "node.hpp"

static int SOLUTION_COUNT = 1;

//TODO: Somehow get args
Entity::Entity(Node* root) : root{root}, fittness{-1.0}, args{2} {}

Entity::Entity(int args) : fittness{-1.0}, args{args}
{
    root = new Node(0, args);
}

double Entity::eval_graph(std::vector<double> vars)
{
    return this->root->eval_node(vars);
}

void Entity::calc_fittness(std::vector<std::pair<std::vector<double>, double>> pairs)
{
    double fittness = 0.0;
    for(auto pair: pairs)
    {
        std::vector<double> vars = pair.first;
        double result = pair.second;
        double calc_result = this->eval_graph(vars);

        fittness += (result - calc_result) * (result - calc_result);
    }

    this->fittness = fittness;
}

Node* Entity::get_rand_node(int& level)
{
    Node *node = root;
    while(true)
    {
        double prob = std::rand() / (double) RAND_MAX;
        if(prob <= 0.5)
        {
            if(node->get_lChild() != NULL)
                node = node->get_lChild();
            else if(node->get_rChild() != NULL)
                node = node->get_rChild();
            else return node;
        }
        else
        {
            if(node->get_rChild() != NULL)
                node = node->get_rChild();
            else if(node->get_lChild() != NULL)
                node = node->get_lChild();
            else return node;
        }

        level++;

        if((std::rand() / (double)RAND_MAX) < level / (double) args)
        {
            return node;
        }
    }
}

void Entity::mutate()
{
    double prob = (std::rand() /(double) RAND_MAX);
    if(prob < MUTATION_RATE)
    {
        int level = 0;
        Node* rand_node = this->get_rand_node(level);
        *rand_node = *(new Node(level, args));
    }
}

Entity Entity::cross_over(Entity& rhs)
{
    Node* new_root = get_rand_child(this->root, rhs.root);
    return Entity(new_root);
}

void Entity::write_dot()
{
    std::ofstream file;
    file.open("./pictures/graph" + std::to_string(SOLUTION_COUNT++) + ".dot");
    file << "digraph A\n{\n";
    this->root->write_dot(file);
    file << "}";
    file.close();
}


