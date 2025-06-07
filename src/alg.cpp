// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        ++length;
    }
    return length;
}

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxVal = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num /= 2;
        } else {
            num = 3 * num + 1;
        }
        if (num > maxVal)
            maxVal = num;
    }
    return maxVal;
}

unsigned int seqCollatz(unsigned int *maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int longest = 0;
    uint64_t bestNum = 0;

    for (uint64_t n = lbound; n <= rbound; ++n) {
        unsigned int len = collatzLen(n);
        if (len > longest) {
            longest = len;
            bestNum = n;
        }
    }

    *maxlen = longest;
    return static_cast<unsigned int>(bestNum);
}

