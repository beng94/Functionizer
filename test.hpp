#ifndef TEST_HPP
#define TEST_HPP

#include <vector>
#include <utility>

const int TST_CASES = 10;

class Test
{
    private:
        std::vector<std::pair<std::vector<double>, double>> tst_cases;

        std::vector<double> gen_input(int);
    public:
        Test();
        std::vector<std::pair<std::vector<double>, double>> get_cases()
        { return tst_cases; }
};

#endif
