#include <stdlib.h>
#include <unistd.h>

char *ptr = NULL;

int main() {
    for (size_t i = 0; i < 100; i++)
    {
        ptr = malloc(100);
        free(ptr);
    }

    return 0;
}