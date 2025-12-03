#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int i;
    int die1, die2, sum;
    int freq[13] = {0};

    srand((unsigned)time(NULL));

    const int N_ROLLS = 36000;

    for (i = 0; i < N_ROLLS; i++) {
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        sum = die1 + die2;
        freq[sum]++;
    }

    printf("點數\t次數\t機率\n");
    for (sum = 2; sum <= 12; sum++) {
        printf("%2d\t%5d\t%.4f\n",
                sum, freq[sum],(double)freq[sum] / N_ROLLS);
    }

    return 0;
}
