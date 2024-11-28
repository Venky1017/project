#include "bloom_filter.h"
#include "ripemd160.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    // Example BSGS Bloom setup
    BloomFilter *filter = bloom_filter_create(1000000, 5);

    uint8_t test_key[32] = {0x01, 0x02, 0x03, 0x04}; // Simplified test key
    uint8_t hash[20];
    ripemd160(test_key, sizeof(test_key), hash);

    bloom_filter_add(filter, hash, sizeof(hash));

    if (bloom_filter_check(filter, hash, sizeof(hash))) {
        printf("Hash exists in Bloom filter.\n");
    } else {
        printf("Hash not found in Bloom filter.\n");
    }

    bloom_filter_destroy(filter);
    return 0;
}
