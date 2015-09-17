#include <cstdlib>
#include <ctime>
#include <iostream>

#include "entitycontainer.hpp"
#include "test.hpp"

int main()
{
    std::srand(std::time(0));

    Test tst;
    EntityContainer ent_container(tst.get_cases());

    for(int i = 0; i < GENERATION_COUNT; i++)
    {
         ent_container.evolve();
         std::cout << "Generation: " << i + 1 << std::endl;
    }

    return 0;
}
