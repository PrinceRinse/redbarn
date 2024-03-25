#ifndef UTILS_H
#define UTILS_H

#include <stdlib.h>

// Clear screen multiplatform, via https://stackoverflow.com/a/42500322
#ifdef _WIN32
#include <conio.h>
#else
#define clrscr() printf("\e[1;1H\e[2J")
#endif

// Text colors w/o format specifiers, via https://stackoverflow.com/a/23657072
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YLW   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

int Utils_min(int a, int b) ;
char *Utils_strcpy_trunc(char *dst, char *src, size_t dst_size) ;

#endif /* UTILS_H */