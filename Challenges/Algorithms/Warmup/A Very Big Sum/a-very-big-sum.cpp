#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    unsigned int n = 0;
    std::vector<long> numbers;

    std::cin >> n;
    while (n > 0) {
        long temp = 0;
        std::cin >> temp;
        numbers.push_back(temp);
        n--;
    }

    long sum = 0;
    for (const auto& n : numbers)
        sum += n;

    std::cout << sum;
    return 0;
}
