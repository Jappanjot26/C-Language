#include <stdio.h>
#include <assert.h>

int add(int a, int b){
	return a + b;
}

void testAdd(){
	assert(add(1, 2) == 3);
	assert(add(-1, 2) == 1);
	assert(add(-1, -1) == -2);
	assert(add(0, 0) == 0);
	printf("All Test Cases Passed!\n");
}

int main(){
	testAdd();
	return 0;
}
