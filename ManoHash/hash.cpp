#include "bchain.h"

std::string hashFunction(std::string input) {
    byt32 hash = {};

    std::string copy = input;

    // Convert string characters into unsigned integers
    std::vector<unsigned int> seed_data(input.begin(), input.end());

    // Feed them into seed_seq
    std::seed_seq seed(seed_data.begin(), seed_data.end());

    // Initialize engine with that seed
    std::mt19937 rng(seed);

    // Shuffle string reproducibly
    std::shuffle(input.begin(), input.end(), rng);

    // std::cout << "Shuffled input: " << input << std::endl;

    for(int i = 0; i < input.length(); ++i) {
        input[i] = input[i]+copy[i];

        input[i] = input[i]*copy[i];

        input[i] = input[i]^copy[i];

        input[i] = input[i]&copy[i];
    }

    std::cout << "Processed input: " << input << std::endl;

    int i = 0;

    for(int j = 0; j < 32; ++j) {
        hash.byte[j] = rng() % 256;
    }

    while(i < input.length()) {
        hash.byte[i % 32] = (hash.byte[i % 32] + input[i]) % 256;
        i++;
    }

    std::stringstream ss;
    for (int i = 0; i < 32; ++i) {
        ss << std::setw(2) << std::setfill('0') << std::hex << static_cast<int>(hash.byte[i]);
    }
    return ss.str();
}