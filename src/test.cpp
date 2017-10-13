#include "shared.h"
#include <iostream>

int main(int argc, char *argv[])
{
    const std::string cmd(argv[1]);

    if (cmd == "is_prime")
    {
        long n = std::atol(argv[2]);
        std::cout << (math::isPrime(n) ? "true" : "false") << std::endl;
    }
    else if (cmd == "primes")
    {
        long n = std::atol(argv[2]);
        std::vector<long> primes = math::getPrimesNotGreaterThan(n);
        for (long prime : primes)
            std::cout << prime << " ";
        std::cout << std::endl;
    }
    else if (cmd == "factors")
    {
        long n = std::atol(argv[2]);
        std::map<long, int> factors = math::getFactors(n);
        for (auto factor : factors)
            std::cout << factor.first << " " << factor.second << std::endl;
    }
    else if (cmd == "reverse")
    {
        long n = std::atol(argv[2]);
        std::cout << math::reverseNum(n) << std::endl;
    }
    else if (cmd == "palindrome")
    {
        std::string str(argv[2]);
        std::cout << (util::isPalindrome(str) ? "true" : "false") << std::endl;
    }

    return 0;
}
