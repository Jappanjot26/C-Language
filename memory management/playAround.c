#include <stdio.h>
#include <stdlib.h>

int main(){
	int size = 5;
	// scanf("%d", &size);
	// char* str = "Hello World";
	
	// gives segmentation fault
	// str[0] = '#';
	
	char str[size];
	str = "Hello";

	printf("%s\n", str);

	return 0;
}
