#include <chrono>
#include <iostream>
#include <random>

#include "randomuuid.h"

uint32_t generate_random_id() {
    std::mt19937 mt{std::random_device{}()};
    std::uniform_int_distribution id{100000000, 999999999};
    return id(mt);
};
