#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {

    // Matrix State Variables
    unsigned int n = 0;
    std::cin >> n;
    int sum_diagonal_primary = 0;
    int sum_diagonal_secondary = 0;
    int current_column_primary = 0;
    int current_column_secondary = n - 1;

    // In One Pass: Evaluate Numbers When Read
    unsigned int column_index = 0;
    int number = 0;
    while (std::cin >> number) {

        // Check the Primary Diagonal
        if (column_index == current_column_primary)
            sum_diagonal_primary += number;

        // Check the Secondary Diagonal
        if (column_index == current_column_secondary)
            sum_diagonal_secondary += number;

        // "Advance" to the Next Column
        column_index++;

        // "Advance" to the Next Row
        if (column_index >= n) {
            column_index = 0;
            current_column_primary += 1;
            current_column_secondary -= 1;
        }

    }

    std::cout << abs(sum_diagonal_primary - sum_diagonal_secondary);
    return 0;
}
