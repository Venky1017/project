#include "ripemd160.h"

// A basic implementation for RIPEMD-160
// Replace with a secure library for production code

void ripemd160(const uint8_t *msg, size_t len, uint8_t hash[20]) {
    // Simple stub function
    for (size_t i = 0; i < 20; i++) {
        hash[i] = (i < len) ? msg[i] : 0;
    }
}
