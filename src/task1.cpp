#include <iostream>
#include <algorithm>

int main()
{
    for (int n = 1; ; ++n)
    {
        const std::string firstNum = std::to_string(2 * n),
                          secondNum = std::to_string(4 * n);
        if (firstNum.size() != secondNum.size())
            continue;

        if (std::is_permutation(firstNum.begin(), firstNum.end(), secondNum.begin()))
        {
            std::cout << n << std::endl;
            break;
        }
    }

    return 0;
}
