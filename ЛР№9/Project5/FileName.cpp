#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

std::string myReplace(const std::string& str, size_t pos, size_t len, const char* s, size_t n) {
    std::string result = str;
    result.replace(pos, len, s, n);
    return result;
}

int countLatinAndCyrillicLetters(const std::string& str) {
    int count = 0;
    for (char c : str) {
        if (isalpha(c) && (islower(c) || isupper(c))) {
            count++;
        }
    }
    return count;
}

bool checkConditions(const std::string& str) {
    bool hasLatinLetter = false;
    bool hasCyrillicLetter = false;

    for (char c : str) {
        if (isalpha(c) && islower(c)) {
            hasLatinLetter = true;
        }
        else if (isalpha(c) && isupper(c)) {
            hasLatinLetter = true;
        }
        else if ((c >= '\xC0' && c <= '\xFF') || (c >= '\xD0' && c <= '\xD1')) {
            hasCyrillicLetter = true;
        }

        if (hasLatinLetter && hasCyrillicLetter) {
            return true;
        }
    }

    return false;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);

    std::string str;
    std::cout << "Enter a string: ";
    std::getline(std::cin, str);

    size_t pos = 0;
    size_t len = 0;
    char s[100];
    size_t n = 0;

    std::cout << "Enter the value for pos: ";
    std::cin >> pos;
    std::cout << "Enter the value for len: ";
    std::cin >> len;
    std::cout << "Enter the string s: ";
    std::cin.ignore();
    std::cin.getline(s, 100);
    std::cout << "Enter the value for n: ";
    std::cin >> n;

    std::string replacedStr = myReplace(str, pos, len, s, n);
    std::cout << "Replaced string: " << replacedStr << std::endl;

    int letterCount = countLatinAndCyrillicLetters(str);
    std::cout << "Total count of Latin and Cyrillic letters: " << letterCount << std::endl;

    bool conditionsMet = checkConditions(str);
    if (conditionsMet) {
        std::cout << "The string meets the conditions." << std::endl;
    }
    else {
        std::cout << "The string does not meet the conditions." << std::endl;
    }

    std::ofstream outputFile("output.txt");
    if (outputFile.is_open()) {
        outputFile << "String: " << str << std::endl;
        outputFile << "Replaced string: " << replacedStr << std::endl;
        outputFile << "Total count of Latin and Cyrillic letters: " << letterCount << std::endl;

        if (conditionsMet) {
            outputFile << "The string meets the conditions." << std::endl;
        }
        else {
            outputFile << "The string does not meet the conditions." << std::endl;
        }

        outputFile.close();
        std::cout << "Results successfully written to the output.txt file." << std::endl;
    }
    else {
        std::cout << "Error opening the file." << std::endl;
    }

    return 0;
}
