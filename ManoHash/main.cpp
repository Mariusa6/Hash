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

    output = hashFunction(sinput);

    std::cout << "Hash: " << output << std::endl;
    return 0;
}