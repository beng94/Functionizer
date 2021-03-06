#include <algorithm>

#include "entitycontainer.hpp"

static bool compare(const Entity& a, const Entity& b)
{
    return a.get_fittness() < b.get_fittness();
}

void EntityContainer::sort()
{
    std::sort(this->container.begin(), this->container.end(), compare);
}

EntityContainer::EntityContainer(std::vector<std::pair<std::vector<double>, double>> tst_cases) :
                 tst_cases{tst_cases}
{
    this->container.reserve(POPULATION_SIZE);
    for(int i = 0; i < POPULATION_SIZE; i++)
    {
        Entity new_entity(tst_cases.at(0).first.size());
        new_entity.calc_fittness(tst_cases);
        this->container.push_back(new_entity);
    }
}

bool EntityContainer::found_solution()
{
    return this->container.front().get_fittness() == 0.0;
}

void EntityContainer::print_solutions()
{
    int i = 0;
    while(this->container.at(i).get_fittness() == 0.0)
    {
        this->container.at(i++).write_dot();
        if(i == this->container.size()) break;
    }

}

void EntityContainer::reduce_pop_size()
{
    this->container.erase(this->container.begin() + POPULATION_SIZE,
                          this->container.end());
}

void EntityContainer::evolve()
{
    this->sort();

    for(int i = 0; i < this->container.size(); i++)
    {
        this->container.at(i).mutate();
    }

    int size = this->container.size() * CROSS_OVER_LIMIT;
    for(int i = 0; i < size; i++)
    {
         for(int j = i + 1; j < size; j++)
         {
            Entity new_entity =
                this->container.at(i).cross_over(this->container.at(j));
            new_entity.calc_fittness(this->tst_cases);
            this->container.push_back(new_entity);
         }
    }

    this->sort();

    this->reduce_pop_size();

    if(this->found_solution())
        this->print_solutions();
}
