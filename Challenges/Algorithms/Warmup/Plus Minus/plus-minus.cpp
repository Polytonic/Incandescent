#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    unsigned int n = 0;
    unsigned int zeroes = 0;
    unsigned int positives = 0;
    unsigned int negatives = 0;

    std::cin >> n;
    int number = 0;
    while (std::cin >> number) {
        if (number < 0)
            negatives += 1;
        else if (number > 0)
            positives += 1;
        else if (number == 0)
            zeroes += 1;
    }

    std::cout << static_cast<float>(positives) / n << std::endl;
    std::cout << static_cast<float>(negatives) / n << std::endl;
    std::cout << static_cast<float>(zeroes) / n << std::endl;
    return 0;
}
