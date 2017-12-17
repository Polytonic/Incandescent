#include <iostream>
#include <map>
#include <string>

int main() {

    unsigned int magazine_size = 0;
    unsigned int ransom_size = 0;
    std::map<std::string, int> magazine_words;
    std::map<std::string, int> ransom_words;

    std::string word;
    std::cin >> magazine_size >> ransom_size;
    for (unsigned int i = 0; i < magazine_size; ++i) {
        std::cin >> word;
        magazine_words[word]++;
    }
    for (unsigned int i = 0; i < ransom_size; ++i) {
        std::cin >> word;
        ransom_words[word]++;
    }

    // Remove the quantity of each word encountered in the ransom note
    // from the magazine, as if we were cutting each word out.
    for (const auto& word : ransom_words) {
        if (magazine_words.find(word.first) != magazine_words.end()) {
            magazine_words[word.first] -= word.second;
        }
    }

    // If any word has a negative count in the magazine, then we have
    // implicitly failed to construct the ransom from the magazine.
    for (const auto& word : magazine_words) {
        if (word.second < 0) {
            std::cout << "No";
            return 1;
        }
    }

    // Granted, this solution could be improved with some extra logic
    // to abort early at the cost of (probably unwarranted?) complexity.
    std::cout << "Yes";
    return 0;
}
