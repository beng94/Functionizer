#include "entity.hpp"

class EntityContainer
{
private:
    std::vector<Entity> container;
    std::vector<std::pair<std::vector<double>, double>> tst_cases;

    void sort();
    bool found_solution();
    void print_solutions();

public:
    EntityContainer(std::vector<std::pair<std::vector<double>, double>>);
    void evolve();
};
