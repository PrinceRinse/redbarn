#include <stdlib.h>
#include <string.h>
#include "../include/utils.h"

int Utils_min(int a, int b) {
    return (a < b) ? a : b ; // ternary operator cooler than if...else
}

// Single-line solution that handles src-dest size mismatch, null termination,
// no unnecessary reads, no padding.
// via https://nrk.neocities.org/articles/not-a-fan-of-strlcpy
char *Utils_strcpy_trunc(char *dst, char *src, size_t dst_size) {
    if (src == NULL)
        return NULL ;
    else if (memccpy(dst, src, '\0', dst_size) == NULL)
        dst[dst_size - 1] = '\0' ;
    return dst ;
}
