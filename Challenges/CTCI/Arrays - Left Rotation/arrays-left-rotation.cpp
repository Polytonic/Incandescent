#include <vector>
#include <iostream>

int main() {
    int n = 0;
    int rotations = 0;
    std::vector<int> numbers;

    int temp = 0;
    std::cin >> n >> rotations;
    while (std::cin >> temp) {
        numbers.push_back(temp);
    }

    for (unsigned int i = 0; i < numbers.size(); ++i) {
        std::cout << numbers[(i + rotations) % numbers.size()] << " ";
    }

    std::cout << std::endl;
    return 0;
}
