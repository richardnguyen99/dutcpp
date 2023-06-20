#include <iostream>
#include <vector>
#include <deque>
#include <initializer_list>

#include "include/vector.h"

int main(void)
{
    dutcpp::vector<int> v0(8);
    dutcpp::vector<int> v1(8, 9);

    dutcpp::vector<int> v2({ 1, 2, 3, 4});

    std::deque<int> stdvect({4,5,6,7});
    dutcpp::vector<int> v3(stdvect.begin(), stdvect.end());
    dutcpp::vector<int> v4(std::move(v3));

    return 0;
}
