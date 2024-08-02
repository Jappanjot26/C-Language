#include <stdio.h>

int main(int argc, char *argv[]){
	
	if(argc != 3){
		printf("Incorrect Call!");
		return 0;
	}

	FILE *file1 = fopen(argv[1], "r");
	FILE *file2 = fopen(argv[2], "a");

	char buffer[100];
	while(fgets(buffer, sizeof(buffer),file1) != NULL){
		fprintf(file2,"%s\n",buffer);
	}

	fclose(file1);
	fclose(file2);

	return 0;
}
