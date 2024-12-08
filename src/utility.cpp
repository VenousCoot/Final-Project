#include "utility.h"
#include <iostream>
#include <thread>
#include <chrono>

void printLetterByLetter(const std::string& text, int delay) {
    for (char c : text) {
        std::cout << c;
        std::cout.flush(); // Flush the output buffer to ensure each character is printed immediately
        std::this_thread::sleep_for(std::chrono::milliseconds(delay)); // Add delay between characters
    }
    std::cout << std::endl; // Move to the next line after printing the text
}
