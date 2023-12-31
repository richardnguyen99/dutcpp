#include <deque>
#include <initializer_list>
#include <iostream>
#include <vector>

#include "include/vector.h"

int
main(void)
{
    dutcpp::vector<int> v0(8);
    dutcpp::vector<int> v1(8, 9);

    dutcpp::vector<int> v2({1, 2, 3, 4});

    std::vector<int> stdvect({4, 5, 6, 7});
    dutcpp::vector<int> v3(stdvect.begin(), stdvect.end());
    dutcpp::vector<int> v4(std::move(v3));

    dutcpp::vector<int> v5(v4);

    for (auto curr = v4.begin(); curr != v4.end(); curr++)
    {
        std::cout << *curr << " ";
    }
    std::cout << "\n";

    for (auto curr = v4.rbegin(); curr != v4.rend(); ++curr)
    {
        std::cout << *curr << " ";
    }
    std::cout << "\n";

    for (auto curr = v5.cbegin(); curr != v5.cend(); ++curr)
    {
        std::cout << *curr << " ";
    }
    std::cout << "\n";

    v5.insert(v5.begin(), 3);
    v5.insert(v5.begin(), 3);
    v5.insert(v5.begin(), 3);
    v5.insert(v5.begin(), 3);
    v5.insert(v5.begin(), 3);
    v5.insert(v5.begin(), 3);
    v5.insert(v5.begin(), 3);

    v5.insert(v5.begin() + 7, -1);

    for (auto curr = v5.cbegin(); curr != v5.cend(); ++curr)
    {
        std::cout << *curr << " ";
    }
    std::cout << "\n";

    return 0;
}
