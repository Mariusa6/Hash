#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <random>
#include <algorithm>
#include <fstream>
#include <sstream>

struct byt32 {
    uint8_t byte[32];
};

byt32 hashFunction(std::string input) {
    byt32 hash = {};

    std::string bitwise = input;

    // Convert string characters into unsigned integers
    std::vector<unsigned int> seed_data(input.begin(), input.end());

    // Feed them into seed_seq
    std::seed_seq seed(seed_data.begin(), seed_data.end());

    // Initialize engine with that seed
    std::mt19937 rng(seed);

    // Shuffle string reproducibly
    std::shuffle(input.begin(), input.end(), rng);

    // std::cout << "Shuffled input: " << input << std::endl;

    for(char c : input) {
        for(char& b : bitwise) {
            b ^= c;
        }
        for(char& b : bitwise) {
            b = (b*c ^ (b+c));
        }
    }

    // std::cout << "Bitwise XOR result: " << bitwise << std::endl;

    int product = 1;
    for (char c : bitwise) {
        product *= c;
    }
    srand(product);

    for (int i = 0; i < 32; ++i) {
        hash.byte[i] = rand();
        for (char c : bitwise) {
            hash.byte[i] += rand();
        }
    }
    return hash;
}

std::string intToHex(byt32 number) {
    std::stringstream ss;
    for (int i = 0; i < 32; ++i) {
        ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(number.byte[i]);
    }
    return ss.str();
}
    
int main(int argc, char* argv[]) {
    std::istream* input;
    std::ifstream file;
    std::string sinput, output;

    if (argc > 1) {
        file.open(argv[1]);
        if (!file) {
            std::cerr << "Nepavyko atidaryti failo: " << argv[1] << "\n";
            return 1;
        }
        input = &file;
    } else {
        std::cout << "Įveskite duomenis: ";
        input = &std::cin;
    }

    std::getline(*input, sinput);

    byt32 hash = hashFunction(sinput);
    output = intToHex(hash);

    std::cout << "Hash: " << output << std::endl;
    return 0;
}