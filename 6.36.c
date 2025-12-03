#include <stdio.h>
#include <stdlib.h>

void stringReverse(const char *s);

int main() {
    char input[100];
    printf("請輸入字串：");
    fgets(input, sizeof(input), stdin);

    printf("反向輸出：");
    stringReverse(input);
    printf("\n");

    return 0;
}

void stringReverse(const char *s) {
    if (*s == '\0')
        return;

    stringReverse(s + 1);
    putchar(*s);
}

