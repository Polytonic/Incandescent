#include <iostream>
#include <string>
#include <map>

int main() {

    // Many solutions track an array of 26 letters, which is not Unicode
    // friendly and will fail if there are special characters: 💩❗

    unsigned int distance = 0;
    std::map<char, int> symbols;
    std::string a, b;
    std::cin >> a;
    std::cin >> b;

    // For each symbol in the first string, increment its "seen" count by one.
    for (const auto& s : a) {
        symbols[s] += 1;
    }

    // For each symbol in the second string, decrement its "seen" count by one.
    for (const auto& s : b) {
        symbols[s] -= 1;
    }

    // We end up with a map of symbols with values varying between +X and -X
    // where the sum of the absolute values of each symbol represents the
    // distance between the two strings (i.e. the number of transformations).
    for (const auto& s : symbols) {
        distance += abs(s.second);
    }

    std::cout << distance;
    return 0;
}
