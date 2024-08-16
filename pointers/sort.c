#include <stdio.h>

void sort(int arr[], int size, int (*compare)(int, int)){
	for(int i = 0; i < size; i++){
		for(int j = i + 1; j < size; j++){
			if(compare(arr[i], arr[j]) > 0){
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int compareAsc(int a, int b){
	return a - b;
}

int compareDesc(int a, int b){
	return b - a;
}

void printArray(int arr[], int size){
	for(int i = 0; i < size; i++){
		printf("%d ",arr[i]);
	} printf("\n");
}

int main(){
	
	int size;
	scanf("%d", &size);

	int arr[size];
	for(int i = 0; i < size; i++){
		scanf("%d", &arr[i]);
	}
	printf("\nAscending Order : ");

	sort(arr, size, compareAsc);
	printArray(arr, size);

	printf("\nDescending Order : ");

	sort(arr, size, compareDesc);
	printArray(arr, size);

	return 0;
}
