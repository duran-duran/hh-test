#include "shared.h"

namespace math
{
    bool isPrime(long n)
    {
        if (n < 2)
            return false;

        for (long i = 2; i * i <= n; ++i)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    std::vector<long> getPrimesNotGreaterThan(long n)
    {
        std::vector<long> primes;
        std::vector<std::pair<long, bool>> numbers;
        for (long i = 2; i <= n; ++i)
            numbers.push_back(std::make_pair(i, true));
        for (size_t i = 0; i < numbers.size(); ++i)
        {
            bool prime = numbers[i].second;
            if (!prime)
                continue;
            long num = numbers[i].first;
            primes.push_back(num);

            long tmp = i + num;
            while (tmp < numbers.size())
            {
                numbers[tmp].second = false;
                tmp += num;
            }
        }
        return primes;
    }

    FactForm getFactors(long n)
    {
        return getFactors(n, getPrimesNotGreaterThan(n));
    }

    FactForm getFactors(long n, const std::vector<long> &primes)
    {
        FactForm factors;
        while (n > 1)
        {
            long prime = *std::find_if(primes.begin(), primes.end(), [n](long prime)
            {
                return (n % prime) == 0;
            });
            ++factors[prime];
            n /= prime;
        }
        return factors;
    }

    long reverseNum(long n)
    {
        long result = 0;
        while (n > 0)
        {
            long remainder = n % 10;
            result = result * 10 + remainder;
            n /= 10;
        }
        return result;
    }

}

namespace util
{
    bool isPalindrome(const std::string &str)
    {
        size_t len = str.size();
        for (size_t i = 0; i < len / 2; ++i)
        {
            if (str[i] != str[len - i - 1])
                return false;
        }
        return true;
    }
}
