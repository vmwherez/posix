#include <stdio.h>

int main() {
    char* strings[] = {"Hello", "World", "C"};
    char** doublePointer = strings;

    for (int i = 0; i < 3; ++i) {
        printf("%s\n", *doublePointer);
        ++doublePointer;
    }

    return 0;
}
