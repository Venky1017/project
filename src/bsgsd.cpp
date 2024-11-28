#include <iostream>
#include <unordered_map>
#include <vector>
#include <cstring>
#include "ripemd160.h"

std::unordered_map<std::string, std::string> generate_bsgs_table(size_t limit) {
    std::unordered_map<std::string, std::string> table;
    for (size_t i = 0; i < limit; ++i) {
        uint8_t data[32];
        std::memset(data, i, sizeof(data));
        uint8_t hash[20];
        ripemd160(data, sizeof(data), hash);

        table[std::string((char*)hash, 20)] = std::string((char*)data, 32);
    }
    return table;
}

int main() {
    size_t limit = 1000;
    auto table = generate_bsgs_table(limit);

    uint8_t test[32] = {0x01, 0x02, 0x03};
    uint8_t hash[20];
    ripemd160(test, sizeof(test), hash);

    std::string key = std::string((char*)hash, 20);
    if (table.find(key) != table.end()) {
        std::cout << "Found public key in BSGS table!" << std::endl;
    } else {
        std::cout << "Key not found." << std::endl;
    }
    return 0;
}
