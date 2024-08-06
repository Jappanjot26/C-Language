#include <stdio.h>
#include <time.h>

void timeTaken(clock_t st, clock_t end ){
	double cpuTime = (double) (end - st)/CLOCKS_PER_SEC;
	printf("Time taken: %f s\n", cpuTime);
}


int main(){
	clock_t start,end;
	start = clock();
	
	int sum = 0;
	for(int i=0; i<1000000; i++) sum+=i;

	end = clock();

	timeTaken(start,end);
}
