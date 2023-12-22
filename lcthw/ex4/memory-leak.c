#include <stdio.h>
#include <stdlib.h>

int main() {
    // Allocate memory without freeing it
    int* data = (int*)malloc(10 * sizeof(int));

    // Access the allocated memory
    for (int i = 0; i < 10; ++i) {
        data[i] = i;
    }

    // Memory leak: forgetting to free the allocated memory
    // free(data);

    return 0;
}
