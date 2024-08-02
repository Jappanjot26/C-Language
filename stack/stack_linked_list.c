#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <limits.h>
#include "stack.h"

struct Node{
	int item;
	struct Node* next;
};

typedef struct Node Node;

Node* head = NULL;
int N = 0;

void push(int item){ // O(1)
	Node* oldHead = head;
	head = (Node *) malloc(sizeof(Node));
	head->item = item;
	head->next = oldHead;
	N++;	
}

int pop(){ // O(1)
	if(N == 0) return INT_MIN;
	int item = head->item;
	Node* temp = head;
	head = head->next;
	N--;
	free(temp);
	return item;
}

int size(){ // O(1)
	return N;
}

bool isEmpty(){
	return N == 0;
}

int testStack(){
	push(3);
	push(10);
	push(19);
	assert(size() == 3 );
	assert(pop() == 19);
	assert(size() == 2);
	assert(pop() == 10);
	assert(size() == 1);
	assert(pop() == 3);
	assert(size() == 0);
	assert(isEmpty());
}


int main(){
	testStack();
}

