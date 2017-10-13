#include "shared.h"
#include <iostream>

int main(int argc, char *argv[])
{
    long maxN = std::atol(argv[1]);
    int maxIt = std::atoi(argv[2]);

    int count = 0;
    for (long n = 1; n < maxN; ++n)
    {
        int tmp = n;
        bool palindromic = false;
        for (int it = 0; it < maxIt; ++it)
        {
            tmp = tmp + math::reverseNum(tmp);
            if (util::isPalindrome(std::to_string(tmp)))
            {
                palindromic = true;
                break;
            }
        }
        if (!palindromic)
            ++count;
    }

    std::cout << count << std::endl;

    return 0;
}
