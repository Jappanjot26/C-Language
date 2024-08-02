#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc !=3){
		printf("Incorrect Call!");
	}
	FILE *file = fopen(argv[1],"a");
	fprintf(file, "%s\n", argv[2]);

	fclose(file);
	
	return 0;
}
