#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    // Track Staircase State
    unsigned int width = 0;
    std::cin >> width;
    unsigned int num_spaces = width - 1;
    unsigned int num_hashes = 1;

    // Iteratively Construct/Print Staircase
    for (unsigned int row = 0; row < width; row++) {
        // Print Spaces
        for (unsigned int i = 0; i < num_spaces; i++) {
            std::cout << " ";
        }
        num_spaces--;

        // Print Hashes
        for (unsigned int i = 0; i < num_hashes; i++) {
            std::cout << "#";
        }
        num_hashes++;

        // Advance to Next Row
        std::cout << std::endl;
    }

    return 0;
}
