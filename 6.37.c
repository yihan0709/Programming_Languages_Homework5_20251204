#include <stdio.h>
#include <stdlib.h>

int recursiveMaximum(const int arr[], int size);

int main() {
    int size, arr[100];
    printf("請輸入陣列大小：");
    scanf("%d", &size);
    printf("請輸入陣列：");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int max_val = recursiveMaximum(arr, size);

    printf("最大值為：%d\n", max_val);
    //printf("max=%d\n", max_val);
    return 0;
}

int recursiveMaximum(const int arr[], int size) {
    if (size == 1)
        return arr[0];

    int max_rest = recursiveMaximum(arr + 1, size - 1);
    if (arr[0] > max_rest)
        return arr[0];
    else
        return max_rest;
}