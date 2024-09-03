#include <stdio.h>
#include <stdlib.h>

void* customCalloc(int nBytes){
	char* arr = (char*) malloc(nBytes);

        for(int i = 0; i < nBytes; i++){
                *(arr + i) = '\0';
                printf("%c ", *(arr + i));
        }

        return (void*) arr;
}

void print(char *arr, int n){
	int i = 0;
	while(--n > 0){
		printf("%c ", *(arr + (i++)));
	} printf("\n");
}

int main(){
	int nBytes;
	scanf("%d", &nBytes);

	char* arr = (char*) customCalloc(nBytes);

	print(arr, nBytes);

	return 0;

}
