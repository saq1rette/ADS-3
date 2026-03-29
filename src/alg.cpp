#include <cstdint>
#include <algorithm>
#include "alg.h"
uint64_t collatzMaxValue(uint64_t num) {
    uint64_t max_val = num;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) {
                return max_val;
            }
            num = 3 * num + 1;
        }
        if (num > max_val) {
            max_val = num;
        }
    }
    return max_val;
}
unsigned int collatzLen(uint64_t num) {
    unsigned int length = 1;
    while (num != 1) {
        if (num % 2 == 0) {
            num = num / 2;
        } else {
            if (num > (UINT64_MAX - 1) / 3) {
                return length + 1;
            }
            num = 3 * num + 1;
        }
        length++;
    }
    return length;
}
unsigned int seqCollatz(unsigned int *maxlen,
                        uint64_t lbound,
                        uint64_t rbound) {
    unsigned int best_num = lbound;
    unsigned int max_length = 0;
    for (uint64_t num = lbound; num <= rbound; num++) {
        unsigned int current_length = collatzLen(num);
        if (current_length > max_length) {
            max_length = current_length;
            best_num = num;
        }
    }
    if (maxlen != nullptr) {
        *maxlen = max_length;
    }
    return best_num;
}
