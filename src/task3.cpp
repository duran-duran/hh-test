#include "shared.h"
#include <iostream>

int main(int argc, char *argv[])
{
    const int64_t maxSize = std::atol(argv[1]),
                  sides = 4;

    int64_t size = 1;
    int64_t first = 1, last = 1;
    int64_t sum = 1;

    while (size < maxSize)
    {
        size += 2;
        first = last + (size - 1);
        last = size * size;

        sum += (first + last) * sides / 2;
    }

    std::cout << sum << std::endl;

    return 0;
}
