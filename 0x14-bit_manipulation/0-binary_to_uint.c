#include "main.h"

/**
 * binary_to_uint - Converts a binary number to an unsigned int
 * */

unsigned int binary_to_uint(const char *b) {
    unsigned int result = 0;

    if (b == NULL) {
        return 0;
    }

    // Loop through each character in the string
    for (int i = 0; b[i] != '\0'; i++) {
        if (b[i] == '0' || b[i] == '1') {
            result = result * 2 + (b[i] - '0');
        } else {
            return 0;
        }
    }
    return result;
}
