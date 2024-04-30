#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10
typedef int element;
typedef struct {
	// element data[MAX_STACK_SIZE];
	element *data;
	int capacity;
	int top;
} StackType;

// Stack initialization
void init_stack(StackType* s) {
	s->top = -1;
}

int is_empty(StackType* s) {
	return (s->top == -1);
}

int is_full(StackType* s) {
	return (s->top == (MAX_STACK_SIZE - 1));
}

void push(StackType* s, element item) {
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->data[++(s->top)] = item;
}

int pop(StackType* s) {
	int item;
	if (is_empty(s)) {
		printf("스택 공백 에러\n");
		return 0;
	}
	else{
		item = s->data[(s->top)--];
		return item;
	}
}

int main(int argc, char* argv[]) {
	StackType s;
	init_stack(&s);

	srand(time(NULL)); // Seed the random number generator with current time

	int i;
	for (i = 0; i < 30; i++) {
		int randomNum = rand() % 101; // Generate random number between 0 and 100
		if (randomNum % 2 == 0) {

			push(&s, randomNum); // Push even number to stack
			printf("%d : %d \n", i, randomNum);
		} else {
			printf("%d\n", pop(&s)); // Pop odd number from stack
		}
	}

	return 0;
}
