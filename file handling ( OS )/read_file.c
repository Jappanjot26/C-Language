#include <stdio.h>

int main(){
	
	FILE *file = fopen("file1.txt","r");
	if(!file) return 1;

	char buffer[100];
	while(fgets(buffer, sizeof(buffer), file) != NULL){
		printf("%s", buffer);
	}

	return 0;
}
