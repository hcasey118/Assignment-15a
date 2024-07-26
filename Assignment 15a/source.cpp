#include <iostream>
#include <stdexcept>

// Hunter Casey
// CIS 1202
// July 26 2024

// Custom exception for invalid character input
class invalidCharacterException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid character input!";
    }
};

// Custom exception for invalid range
class invalidRangeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Invalid character range!";
    }
};

// Function to calculate character offsets
char character(char start, int offset) {
    if (!((start >= 'A' && start <= 'Z') || (start >= 'a' && start <= 'z'))) {
        throw invalidCharacterException();
    }

    char result = start + offset;

    if ((start >= 'A' && start <= 'Z' && (result < 'A' || result > 'Z')) ||
        (start >= 'a' && start <= 'z' && (result < 'a' || result > 'z'))) {
        throw invalidRangeException();
    }

    return result;
}

int main() {
    try {
        std::cout << "character('a', 1) = " << character('a', 1) << std::endl; // should return 'b'
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('a', -1) = " << character('a', -1) << std::endl; // should throw invalidRangeException
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('Z', -1) = " << character('Z', -1) << std::endl; // should return 'Y'
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('?', 5) = " << character('?', 5) << std::endl; // should throw invalidCharacterException
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        std::cout << "character('A', 32) = " << character('A', 32) << std::endl; // should throw invalidRangeException
    }
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}