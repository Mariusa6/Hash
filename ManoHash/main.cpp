#include "bchain.h"
#include "hash.cpp"

std::string hashFunction(std::string input);
    
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

    // Get starting timepoint
    auto start = std::chrono::high_resolution_clock::now();

    output = hashFunction(sinput);

    // Get ending timepoint
    auto end = std::chrono::high_resolution_clock::now();

    // Calculate the duration in milliseconds
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Hash: " << output << std::endl;
    
    std::cout << "Hashing time: " << duration.count() << " ms" << std::endl;
    return 0;
}