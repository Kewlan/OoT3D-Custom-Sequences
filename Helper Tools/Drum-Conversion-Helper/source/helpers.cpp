#include "helpers.hpp"

bool StrIsInt(std::string str) {
    char* p;
    auto x = strtol(str.c_str(), &p, 10);
    return !(*p);
}
