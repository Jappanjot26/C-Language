#include<stdio.h>
int main(){
	
	FILE *file = fopen("binaryFile.bin", "wb+");

	char input[100];
	fgets(input, sizeof(input), stdin);
	fprintf(file, "%s", input);
	
	rewind(file);

	char output[100];
	fgets(output, 100, file);

	printf("%s", output);

	fclose(file);
	return 0;
}
