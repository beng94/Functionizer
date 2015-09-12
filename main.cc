#include <cstdlib>
#include <ctime>

#include "entity.hpp"
#include "test.hpp"

int main()
{
    std::srand(std::time(0));

    Test tst;
    EntityContainer ent_container(tst.get_cases());
    ent_container.evolve();

    return 0;
}
