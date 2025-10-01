#ifndef BCHAIN_H
#define BCHAIN_H

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
#include <chrono>

struct byt32 {
    uint8_t byte[32] = {0};
};

std::string hashFunction(std::string input);

#endif  // BCHAIN_H