#include "randomuuid.h"
#include <iostream>

int main() {
    for (int i = 0; i <= 40; ++i) {
        std::cout << generate_random_id() << '\n';
    };
};
