#include "bloom_filter.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

static uint32_t hash(const uint8_t *data, size_t len, uint32_t seed) {
    uint32_t hash = seed;
    for (size_t i = 0; i < len; i++) {
        hash = (hash * 33) ^ data[i];
    }
    return hash;
}

BloomFilter* bloom_filter_create(size_t size, size_t num_hashes) {
    BloomFilter *filter = malloc(sizeof(BloomFilter));
    filter->size = size;
    filter->num_hashes = num_hashes;
    filter->bit_array = calloc((size + 7) / 8, sizeof(uint8_t));
    return filter;
}

void bloom_filter_add(BloomFilter *filter, const uint8_t *data, size_t len) {
    for (size_t i = 0; i < filter->num_hashes; i++) {
        uint32_t index = hash(data, len, i) % filter->size;
        filter->bit_array[index / 8] |= (1 << (index % 8));
    }
}

bool bloom_filter_check(const BloomFilter *filter, const uint8_t *data, size_t len) {
    for (size_t i = 0; i < filter->num_hashes; i++) {
        uint32_t index = hash(data, len, i) % filter->size;
        if (!(filter->bit_array[index / 8] & (1 << (index % 8)))) {
            return false;
        }
    }
    return true;
}

void bloom_filter_destroy(BloomFilter *filter) {
    free(filter->bit_array);
    free(filter);
}
