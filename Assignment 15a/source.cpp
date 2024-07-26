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

