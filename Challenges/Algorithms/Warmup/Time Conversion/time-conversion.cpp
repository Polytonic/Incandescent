#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;


int main() {
    std::string s;
    std::cin >> s;

    int hours = std::stoi(s.substr(0, 2));
    int minutes = std::stoi(s.substr(3, 5));
    int seconds = std::stoi(s.substr(6, 8));
    std::string meridiem = s.substr(8, s.length());

    if (meridiem == "AM" && hours == 12) {
        hours = 0;
    }
    else if (meridiem == "PM" && hours < 12) {
        hours += 12;
    }

    fprintf(stdout, "%02d:%02d:%02d\n", hours, minutes, seconds);

    return 0;
}
