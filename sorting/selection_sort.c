#include <stdio.h>
#include <assert.h>
#include <time.h>

void selection_sort(int arr[], int n){
	for(int i=0; i<n; i++){
		int min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j] < arr[min]) min = j;
		}
		int temp = arr[i];
		arr[i] = arr[min];
		arr[min] = temp;  
	}
}

void printArr(int arr[],int n){
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}

int isArraysEqual(int arr1[], int arr2[2], int n){
	for(int i=0; i<n; i++){
		if(arr1[i] != arr2[i]) return 0;
	}
	return 1;
}

void timeTaken(clock_t st,clock_t end){
	double cpuTime = (double) ((st-end)/CLOCKS_PER_SEC);
	printf("Time taken: %f s\n",cpuTime);
}

void testCases(){
	int arr1[] = {1, 3, 6, 7, 3, 8, 4};
	int sorted1[] = {1, 3, 3, 4, 6, 7, 8};
	selection_sort(arr1,7);
	assert(isArraysEqual(arr1,sorted1,7));

	int arr2[] = {9, 4, 7, 3, 8, 2};
	int sorted2[] = {2, 3, 4, 7, 8, 9};
	selection_sort(arr2, 6);
	assert(isArraysEqual(arr2, sorted2, 6));

	int arr3[] = {1, 5, 2, 8, 7, 3, 4, 6};
	int sorted3[] = {1, 2, 3, 4, 5, 6, 7, 8};
	selection_sort(arr3, 8);
	assert(isArraysEqual(arr3, sorted3, 8));

	int arr4[] = {-1, -5, 0, 2, -3, 4, 1};
	int sorted4[] = {-5, -3, -1, 0, 1, 2, 4};
	selection_sort(arr4, 7);
	assert(isArraysEqual(arr4, sorted4, 7));

	int arr5[] = {50, 30, 20, 10, 60, 40, 70, 80};
	int sorted5[] = {10, 20, 30, 40, 50, 60, 70, 80};
	selection_sort(arr5, 8);
	assert(isArraysEqual(arr5, sorted5, 8));
	printf("All Test Cases Passed!\n");
}

int main(){
	clock_t st, end;
	st = clock();
	testCases();
	end = clock();
	timeTaken(st,end);
	return 0;
}

