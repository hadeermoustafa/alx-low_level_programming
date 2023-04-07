#include <stdio.h>
#include "main.h"

unsigned int binary_to_uint(const char *b) {
    unsigned int result = 0;

    if (b == NULL) {
        return 0;
    }

    // Loop through each character in the string
    for (; *b != '\0'; ++b) {
        if (*b != '0' && *b != '1') {
            return 0;
        }
        // Shift the current result to the left by one bit and add the current bit
        result = (result << 1) + (*b - '0');
    }

    return result;
}
