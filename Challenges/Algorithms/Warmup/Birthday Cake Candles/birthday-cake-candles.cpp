#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n = 0;
    int number = 0;

    std::vector<int> numbers;
    int max_value = 0;
    int count = 0;

    std::cin >> n;
    while (std::cin >> number) {
        numbers.push_back(number);
        if (number > max_value)
            max_value = number;
    }

    for (const auto& i : numbers) {
        if (i == max_value)
            count++;
    }

    std::cout << count;
    return 0;
}
