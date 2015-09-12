#include <cstdlib>

#include "test.hpp"

/* It will generate random input args for the tests.
*  args will be smaller than 100.
*/
std::vector<double> Test::gen_input(int args)
{
    std::vector<double> input;
    for(int i = 0; i < args; i++)
    {
        input.push_back(std::rand() % 100);
    }

    return input;
}

Test::Test()
{
    for(int i = 0; i < TST_CASES; i++)
    {
        std::vector<double> input = this->gen_input(2);
        double a = input[0];
        double b = input[1];

        double result = a + b;

        std::pair<std::vector<double>, double> new_tst =
            {input, result};

        this->tst_cases.push_back(new_tst);
    }
}
