#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // Declare Variables
    size_t array_size = 0;
    unsigned int number = 0;
    unsigned int sum = 0;
    std::vector<int> numbers;

    // Read Input Parameters
    std::cin >> array_size;
    while (std::cin >> number) {
        numbers.push_back(number);
    }

    // See Also: std::valarray::sum()
    // Compute the Sum
    for (const auto& number : numbers) {
        sum += number;
    }

    // Print the Sum
    std::cout << sum;
    return 0;
}
