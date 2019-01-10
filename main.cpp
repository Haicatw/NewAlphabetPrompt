#include <iostream>

void printAlphabet(char* str);

int main(int argc, char** argv) {

    std::cout << "You entered the word: ";

    for (int i = 1; i < argc; ++i) {
        printAlphabet(argv[i]);
    }

    return 0;
}

void printAlphabet(char* str) {
    int capitalMask = 0b100000000000000000000000000; //mask to detect if it is capital letter
    int var = std::stoi(str);
    bool capital = false;
    int number = 0;

    if (var & capitalMask) {                         //check if it is capitalized
        capital = true;
        var ^= capitalMask;                          //flip the capital sign bit
    }

    while (var >>= 1) {                              //use shift to see what is the character
        number += 1;
    }

    if (capital) {                                   //use ascii to print out the character
        std::cout << char(65 + number);
    } else {
        std::cout << char(97 + number);
    }
}

