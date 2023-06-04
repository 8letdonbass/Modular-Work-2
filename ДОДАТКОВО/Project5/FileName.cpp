

#include <iostream>
#include <string>

std::string convertToInitials(const std::string& name) {
    std::string initials;

    // Find the index of the space separating the two words
    size_t spaceIndex = name.find(' ');

    // Check if a space is found and the name consists of two words
    if (spaceIndex != std::string::npos && spaceIndex + 1 < name.length()) {
        // Get the first letter of the first word and add it to the initials
        initials += std::toupper(name[0]);
        initials += ". ";

        // Get the first letter of the second word and add it to the initials
        initials += std::toupper(name[spaceIndex + 1]);
        initials += ".";
    }

    return initials;
}

int main() {
    std::string name;
    char choice = 'y';

    while (choice == 'y' || choice == 'Y') {
        std::cout << "Enter a name: ";
        std::getline(std::cin, name);

        std::string initials = convertToInitials(name);
        std::cout << "Initials: " << initials << std::endl;

        std::cout << "Do you want to enter another name? (Y/N): ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return 0;
}

