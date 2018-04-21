#include "common.h"

#define SIZE 10

void printArr(int *arr, int n);
int* bubble(int *arr, int n);

int main() 
{
    int arr[SIZE] = {1, 88, 3, 66, 2, 10, 15, 1, 0, 88};
    int n = sizeof(arr)/sizeof(arr[0]);
    int *sortedArr = bubble(arr, n);
    printArr(sortedArr, n);
    return 0;
}

void printArr(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* bubble(int *arr, int n)
{
    int swapped = 1;
    int end = n;
    while (swapped) {
        swapped = 0;
        for (int current = 0; current < end; current++) {
            if (arr[current] > arr[current+1]) {
                int tmp = arr[current];
                arr[current] = arr[current+1];
                arr[current+1] = tmp;
                swapped = 1;
            }
        }
        end--;
    }
    return arr;
}