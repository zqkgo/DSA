#include "common.h"

void merge(int arr[], int low, int mid, int high);

void mergeSort(int arr[], int left, int right);

int main() {
    int arr[] = {1, 198, 56, 77, 5678, 0, 1, 2, 10, 3, 555, 4444};
    int len = sizeof(arr) / sizeof(arr[0]);
    mergeSort(arr, 0, len - 1);
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid - 1);
        mergeSort(arr, mid, right);
        merge(arr, left, mid, right);
    }
}

/**
 *  
 */
void merge(int arr[], int low, int mid, int high) {
    int leftArrLen = mid - low + 1;
    int rightArrLen = high - mid;
    int leftArr[leftArrLen];
    int rightArr[rightArrLen];

    for (int i = 0; i < leftArrLen; i++) {
        leftArr[i] = arr[i];
    }
    for (int j = 0; j < rightArrLen; j++) {
        rightArr[j] = arr[leftArrLen + j];
    }

    // int mergedArr[leftArrLen+rightArrLen]; // 归并数组
    int mergedPos = low; // 指向归并数组
    int leftPos = 0; // 指向左数组
    int rightPos = 0; // 指向右数组

    while (leftPos < leftArrLen && rightPos < rightArrLen) {
        if (leftArr[leftPos] < rightArr[rightPos]) {
            arr[mergedPos++] = leftArr[leftPos++];
        } else {
            arr[mergedPos++] = rightArr[rightPos++];
        }
    }

    if (leftPos < leftArrLen) {
        while (leftPos < leftArrLen) {
            arr[mergedPos++] = leftArr[leftPos++];
        }
    }
    if (rightPos < rightArrLen) {
        while (rightPos < rightArrLen) {
            arr[mergedPos++] = rightArr[rightPos++];
        }
    }
}