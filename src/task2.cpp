#include "shared.h"
#include <iostream>

long sFunc(long n, const std::vector<long> &primes)
{
    std::map<long, int> factors = math::getFactors(n, primes);
    using ValT = decltype(factors)::value_type;

    auto findFact = [](const ValT &val) -> long
    {
        long num = val.first;
        int cnt = val.second;

        int found = 0;
        long i;
        for (i = 2; ; ++i)
        {
            long tmp = i;
            while (tmp % num == 0)
            {
                ++found;
                tmp /= num;
            }
            if (found >= cnt)
                break;
        }
        return i;
    };

    auto comp = [findFact](const ValT &lhs, const ValT &rhs)
    {
        return findFact(lhs) < findFact(rhs);
    };

    auto it = std::max_element(factors.begin(), factors.end(), comp);
    return findFact(*it);
}

int main(int argc, char *argv[])
{
    long start = std::atol(argv[1]),
         end   = std::atol(argv[2]);

    auto primes = math::getPrimesNotGreaterThan(end);
    long sum = 0;
    for (long i = start; i <= end; ++i)
        sum += sFunc(i, primes);

    std::cout << sum << std::endl;

    return 0;
}
