#ifndef RIPEMD160_H
#define RIPEMD160_H

#include <stdint.h>
#include <stddef.h>

void ripemd160(const uint8_t *msg, size_t len, uint8_t hash[20]);

#endif
