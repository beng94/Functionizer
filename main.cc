#include <cstdlib>
#include <ctime>

#include "entity.hpp"

int main()
{
    std::srand(std::time(0));

    //Test: a + b
    std::vector<std::pair<std::vector<double>, double>> test_cases =
    {
        {{0,0}, 0},
        {{0,1}, 1},
        {{1,0}, 1},
        {{2,0}, 2},
        {{0,2}, 2},
        {{5, 4}, 9},
        {{4, 10}, 14}
    };

    EntityContainer ent_container(test_cases);
    ent_container.evolve();

    return 0;
}
