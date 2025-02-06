#include <stdio.h>
#include <stdlib.h>

#include "./error.h"

void panic(char* message) {
    puts(message);
    exit(1);
}
