#include <stdio.h>
#include <string.h>

int add(int a, int b){
	return a + b;
}

int sub(int a, int b){
        return a - b;
}

int mul(int a, int b){
        return a * b;
}

int div(int a, int b){
        return a / b;
}

void performOperation(int (*operation)(int, int), int a, int b){
	printf("%d\n", operation(a, b));
} 

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
        performOperation(add, a, b);	
	performOperation(sub, a, b);  
	performOperation(mul, a, b);
	performOperation(div, a, b);  
	return 0;

}
