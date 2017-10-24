#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int a0, a1, a2, b0, b1, b2;
    int score_alice = 0;
    int score_bob = 0;
    std::cin >> a0 >> a1 >> a2 >> b0 >> b1 >> b2;

    auto compare = [&score_alice, &score_bob](int a, int b) {
        if (a > b)
            score_alice += 1;
        else if (a < b)
            score_bob += 1;
    };

    compare(a0, b0);
    compare(a1, b1);
    compare(a2, b2);

    std::cout << std::to_string(score_alice) << " " << std::to_string(score_bob);
    return 0;
}
