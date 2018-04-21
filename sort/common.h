#include <stdio.h>
#include <stdlib.h>

void printArr(int *arr, int n)
{
	for (int i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}