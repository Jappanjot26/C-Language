#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Pseudo Random Numbers as SEED is required to run
// as if seed is same , then numbers are also same
// this works on a deterministic algo based on seed

void printRandomNums(int lower, int upper, int count){
	for(int i=0; i<count; i++) {
		int num = (rand() % (upper - lower + 1) + lower);
		printf("%d ", num);
	} printf("\n");
}

int main(){
	int lower, upper, count;
	printf("Enter Range and Count: ");
	scanf("%d %d %d",&lower, &upper, &count);

	srand(time(NULL)); // current time AS seed in function
			   // as current time will act a different seed			 
	printRandomNums(lower, upper, count);

	return 0;

}
