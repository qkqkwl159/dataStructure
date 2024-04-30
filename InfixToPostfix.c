#include <stdio.h>
#include <time.h>
#include <stdlib.h> 
#include <string.h>

#define MAX_STACK_SIZE 10

typedef int element;
typedef struct Stacktype {
	// element data[];
	element* data;
	int capacity;
	int top;
} StackType;


// create : 이미 만들었음, StackType의 변수를 선언하면 만들어짐
// delete : 할수 없음

// init 
void init(StackType* sptr, int ofs) {
	sptr->data = (element*)malloc(sizeof(StackType) * ofs);
	sptr->top = -1;
	sptr->capacity = ofs;
}

// is_full
int is_full(StackType* sptr) {
	// printf("[is_full] top = %d, capacity = %d\n", sptr->top, sptr->capacity);
	if (sptr->top == sptr->capacity - 1) {
		sptr->capacity = sptr->capacity * 2;
		sptr->data = (element*)realloc(sptr->data, sptr->capacity * sizeof(element));

	}
	return 0;
}

int is_empty(StackType* sptr) {
	return (sptr->top == -1);
}

// push
void push(StackType* sptr, element item) {

	if (is_full(sptr)) {
		fprintf(stderr, "Stack is full\n");
		return;
	}
	else {
		sptr->top = sptr->top + 1;
		sptr->data[sptr->top] = item;
	}
}

element pop(StackType* sptr) {
	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		// r = sptr->stack[sptr->top];
		// sptr->top = sptr->top - 1;
		// return r;
		return (sptr->data[(sptr->top)--]);
	}
}

element peek(StackType* sptr) {

	element r;
	if (is_empty(sptr)) {
		fprintf(stderr, "stack is empty\n");
		return -1;
	}
	else {
		// r = stack[top];
		// top = top - 1;
		// return r;
		return (sptr->data[sptr->top]);
	}
}

void stack_print(StackType* sptr) {
	for (int i = sptr->top; i >= 0; i--) {
		printf("[%d]", sptr->data[i]);
	}
}

int eval(char expr[]) {
	int len;
	StackType s;

	init(&s, 20);
	len = strlen(expr);
	for (int i = 0; i < len; i++) {
		int ch = expr[i];
		int value;
		int op1, op2;

		printf("\nStep [%d] %c ", i, ch);
		if ((ch == '+') || (ch == '-')
			|| (ch == '*') || (ch == '/')) {
			op1 = pop(&s);
			op2 = pop(&s);
			/* if (ch == '+') {
				value = op1 + op2;
				push(&s, value);
			} else if (ch == '-') {
				value = op1 - op2;
				push(&s, value);
			} else if (ch == '*') {
				value = op1 * op2;
				push(&s, value);
			} else {
				value = op1 / op2;
				push(&s, value);
			}
			*/
			switch (ch) {
			case '+': push(&s, op2 + op1); break;
			case '-':push(&s, op2 - op1); break;
			case '*':push(&s, op2 * op1); break;
			case '/':push(&s, op2 / op1); break;
			default:;
			}
		}
		else if ((ch >= '0') && (ch <= '9')) {
			value = ch - '0';
			push(&s, value);
		}
		else {
			printf(" Abnomal character in expr\n");
		}
		printf(" Stack : ");
		stack_print(&s);
	}
	return (pop(&s));
}

int prec(char op) {
	switch (op) {
	case '(': case ')': return 0;
	case '+': case '-': return 1;
	case '*': case '/': return 2;
	}
	return -1;
}

void infix_to_postfix(char expr[]) {

	char top_op;
	int len = strlen(expr);
	StackType s;

	init(&s, MAX_STACK_SIZE);
	for (int i = 0; i < len; i++) {
		switch (expr[i]) {
		case '+':
		case '-':
		case '*':
		case '/':
			while (!is_empty(&s) && prec(expr[i]) <= prec((char)peek(&s))) {
				printf("<%c>", pop(&s));
			}
			push(&s, (int)expr[i]);
			break;
		case '(': push(&s, (int)expr[i]); break;
		case ')':
			top_op = (char)pop(&s);
			while (top_op != '(') {
				printf("%c", top_op);
				top_op = (char)pop(&s);
			}
			break;
		default: printf("<%c>", expr[i]);
			break;
		}
		/*printf(" Stack : ");
		stack_print(&s); */
	}
	while (!is_empty(&s)) {
		/* printf(" Stack : ");
		stack_print(&s); */
		printf("<%c>", (char)pop(&s));
	}
}

int main() {
	int result;

	printf(" 중위식 표기: 1+2*3-4/(1+1)+3\n 변환된 것:");
	infix_to_postfix("1+2*3-4/(1+1)+3");
	printf("\n후위식 수식: 123*+411+/-3+\n");
	result = eval("123*+411+/-3+");
	printf(" 계산 결과: %d\n", result);
}