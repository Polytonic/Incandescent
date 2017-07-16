#include <iostream>
#include "vector.h"

int main() {
    ist::vector<int> vec;
    for (unsigned int i = 0; i < 100; i++) {
        vec.push_back(i);
    }

    return 0;
}
