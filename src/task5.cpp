#include "shared.h"
#include <iostream>

int main(int argc, char *argv[])
{
    long minBase = std::atol(argv[1]),
         maxBase = std::atol(argv[2]);

    long minExp = std::atol(argv[3]),
         maxExp = std::atol(argv[4]);

    std::vector<long> primes = math::getPrimesNotGreaterThan(maxBase);

    using math::FactForm;
    using ValT = FactForm::value_type;
    std::vector<FactForm> factoredNumbers;

    for (long base = minBase + 1; base < maxBase; ++base)
    {
        for (long exp = minExp + 1; exp < maxExp; ++exp)
        {
            FactForm factNum = math::getFactors(base, primes);
            std::for_each(factNum.begin(), factNum.end(), [exp](ValT &el)
            {
                el.second *= exp;
            });

            auto searchFunc = [factNum](const FactForm &el) -> bool
            {
                if (factNum.size() != el.size())
                    return false;
                return std::equal(factNum.begin(), factNum.end(), el.begin());
            };
            if (std::find_if(factoredNumbers.begin(), factoredNumbers.end(), searchFunc) == factoredNumbers.end())
                factoredNumbers.push_back(factNum);
        }
    }

    std::cout << factoredNumbers.size() << std::endl;

    return 0;
}
