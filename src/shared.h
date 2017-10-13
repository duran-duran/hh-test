#pragma once

#include <vector>
#include <map>
#include <string>
#include <algorithm>

namespace math
{
    bool isPrime(long n);
    std::vector<long> getPrimesNotGreaterThan(long n);
    std::map<long, int> getFactors(long n);
    std::map<long, int> getFactors(long n, const std::vector<long> &primes);
    long reverseNum(long n);
}

namespace util
{
    bool isPalindrome(const std::string &str);
}
