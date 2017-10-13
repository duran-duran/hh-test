#include "shared.h"
#include <iostream>

int main(int argc, char *argv[])
{
    const std::string cmd(argv[1]);
    long n = std::atol(argv[2]);

    if (cmd == "is_prime")
    {
        std::cout << (math::isPrime(n) ? "true" : "false") << std::endl;
    }
    else if (cmd == "primes")
    {
        std::vector<long> primes = math::getPrimesNotGreaterThan(n);
        for (long prime : primes)
            std::cout << prime << " ";
        std::cout << std::endl;
    }
    else if (cmd == "factors")
    {
        std::map<long, int> factors = math::getFactors(n);
        for (auto factor : factors)
            std::cout << factor.first << " " << factor.second << std::endl;
    }

    return 0;
}
