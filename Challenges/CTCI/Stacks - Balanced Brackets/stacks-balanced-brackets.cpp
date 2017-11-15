#include <iostream>
#include <string>
#include <stack>

int main() {
    std::string s;
    int count = 0;
    std::cin >> count;

    auto compare = [](const std::string& str) {

        // Abort on Odd Strings
        if (str.length() % 2 != 0) return false;

        // Push Opening Symbol or Pop Closing Symbol
        std::stack<char> stack;
        for (const auto& symbol : str) {
            if      (symbol == '{') stack.push('}');
            else if (symbol == '[') stack.push(']');
            else if (symbol == '(') stack.push(')');

            // At this point we've reached a non-opening brace, so check if it
            // matches the last opening brace pushed onto the stack and pop it
            // off the stack if it matches.
            else if (stack.size() == 0 || symbol != stack.top())
                    return false;
            else
                stack.pop();
        }
        return stack.size() == 0;
    };

    while(std::cin >> s) {
        if (compare(s)) std::cout << "YES";
        else std::cout << "NO";
        std::cout << std::endl;
    }

    return 0;
}
