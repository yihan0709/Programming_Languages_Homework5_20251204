#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int recursiveBinarySearch(int arr[], int low, int high, int key);

int main(void) {
    int i;
    int die1, die2, sum;
    int arr[13] = {0};

    srand((unsigned)time(NULL));

    const int N_ROLLS = 36000;

    for (i = 0; i < N_ROLLS; i++) {
        die1 = rand() % 6 + 1;
        die2 = rand() % 6 + 1;
        sum = die1 + die2;
        arr[sum]++;
    }

    int size = sizeof(arr) / sizeof(arr[0]);
    int key;

    printf("輸入要搜尋的數字：");
    scanf("%d", &key);

    int pos = recursiveBinarySearch(arr, 0, size - 1, key);

    if (pos == -1)
        printf("找不到 %d\n", key);
    else
        printf("找到 %d，在索引位置 %d。\n", key, pos);

    return 0;
}


int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (arr[mid] == key)
        return mid;
    else if (key < arr[mid])
        return recursiveBinarySearch(arr, low, mid - 1, key);
    else
        return recursiveBinarySearch(arr, mid + 1, high, key);
}