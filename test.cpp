#include "header.h"

int main() {
    auto now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
    std::tm currentYearTM = *std::localtime(&now);
    int currentYear = currentYearTM.tm_year + 1900;
    std::cout << "Year: " << currentYear;
};
