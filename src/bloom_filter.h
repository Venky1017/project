#ifndef BLOOM_FILTER_H
#define BLOOM_FILTER_H

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

typedef struct {
    uint8_t *bit_array;
    size_t size;
    size_t num_hashes;
} BloomFilter;

BloomFilter* bloom_filter_create(size_t size, size_t num_hashes);
void bloom_filter_add(BloomFilter *filter, const uint8_t *data, size_t len);
bool bloom_filter_check(const BloomFilter *filter, const uint8_t *data, size_t len);
void bloom_filter_destroy(BloomFilter *filter);

#endif
