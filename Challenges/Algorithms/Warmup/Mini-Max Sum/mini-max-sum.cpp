#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    long sum_min = 0;
    long sum_max = 0;
    long number = 0;
    std::vector<long> numbers;
    while (std::cin >> number) {
        numbers.push_back(number);
    }

    std::sort(numbers.begin(), numbers.end());
    for (unsigned int i = 0; i < numbers.size() - 1; i++) {
        sum_min += numbers[i];
        sum_max += numbers[i+1];
    }

    std::cout << sum_min << " " << sum_max << std::endl;
    return 0;
}
