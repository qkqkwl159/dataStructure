#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Stack structure
typedef struct {
    int data[MAX_SIZE];
    int top;
} Stack;

// Function to initialize the stack
void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Function to push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack overflow!\n");
        exit(1);
    }
    s->data[++s->top] = value;
}

// Function to pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack underflow!\n");
        exit(1);
    }
    return s->data[s->top--];
}

// Function to evaluate the arithmetic expression
int evaluateExpression(char *expression) {
    Stack stack;
    initialize(&stack);

    int i, result, operand1, operand2;

    for (i = 0; expression[i] != '\0'; i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            push(&stack, expression[i] - '0');
        } else if (expression[i] == '(') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')') {
            operand2 = pop(&stack);
            result = pop(&stack);
            operand1 = pop(&stack);
            pop(&stack); // Pop the opening parenthesis

            switch (result) {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        // 만약 연산자라면 push 해준다.
        // 해주지 않으면 연산자가 빠져서 연산이 되지 않는다.
        } else if (expression[i] == '+' || expression[i] == '-' || expression[i] == '*' || expression[i] == '/') {
            push(&stack, expression[i]);
        }
    }

    return pop(&stack);
}

int main() {
    char expression[MAX_SIZE];

    printf("Enter an arithmetic expression: ");
    fgets(expression, sizeof(expression), stdin);

    int result = evaluateExpression(expression);
    printf("Result: %d\n", result);

    return 0;
}