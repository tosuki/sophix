#include <stdio.h>
#include <stdlib.h>

#include "./utils.h"

/**
 * panic utility function
 */
void panic(char* message) {
    puts(message);
    exit(1);
}