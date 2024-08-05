#include <stdio.h>
int main(){

	int arr[4] = {1, 2, 3, 4};
	int *ptr = arr;
	for(int i = 0; i < 5; i++){
		printf("%d, %d\n", arr[i], *(ptr+i));
	}
	return 0;
}
