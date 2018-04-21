#include "common.h"

void swap(int *a, int *b);
int pivot(int *arr, int low, int high);
void quick(int *arr, int low , int high);

int main()
{
	int arr[] = {1, 198, 56, 77, 5678, 0, 1, 2, 2, 3, 34, 1};
	int high = sizeof(arr) / sizeof(arr[0]);
	quick(arr, 0, high-1);
	printArr(arr, high);
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int pivot(int *arr, int low, int high)
{
	int pivot = arr[high];
	int end = high - 1;
	int smallPos = low - 1;
	for (int i = low; i <= end; i++) {
		if (arr[i] < pivot) {
			smallPos++;
			swap(&arr[smallPos], &arr[i]);
		}
	}
	int pivotPos = smallPos + 1;
	swap(&arr[high], &arr[pivotPos]);
	
	return pivotPos;
}

void quick(int *arr, int low , int high)
{
	if (low < high) {
		int pivotPos = pivot(arr, low, high);
		quick(arr, low, pivotPos-1);
		quick(arr, pivotPos+1, high);
	}
}




