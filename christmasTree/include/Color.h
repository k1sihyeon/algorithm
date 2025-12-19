#pragma once

#include <string>
#include <vector>

namespace color {
    const std::string RESET = "\033[0m";
    const std::string GREEN = "\033[32m";
    const std::string BROWN = "\033[38;5;94m";
    const std::string YELLOW = "\033[93m";
    const std::string WHITE = "\033[97m";
    const std::string RED   = "\033[91m";
    
    const std::vector<std::string> LEDS = {
        "\033[91m", "\033[93m", "\033[94m", "\033[95m", "\033[96m", "\033[97m"
    };
}