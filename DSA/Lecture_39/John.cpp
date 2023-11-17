#include <stdio.h>

unsigned int hashCalc(char *key, int tableSize) {
    unsigned int hashVal = 0;
    
    for (int i = 0; key[i] != '\0'; i++) {
        hashVal = 37 * hashVal + key[i];
    }

    return hashVal % tableSize;
}

int main() {
    char text[102];
    int tSize;
    scanf("%s", text);
    scanf("%d", &tSize);
    printf("%u", hashCalc(text, tSize));
    return 0;
}
