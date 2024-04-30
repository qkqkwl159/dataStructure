#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_STACK_SIZE 100

typedef struct {
    int top;
    int* stackArray;
} Stack;

Stack* createStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    stack->stackArray = (int*)malloc(MAX_STACK_SIZE * sizeof(int));
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

int isFull(Stack* stack) {
    return stack->top == MAX_STACK_SIZE - 1;
}

void push(Stack* stack, int item) {
    if (isFull(stack)) {
        printf("Stack Overflow\n");
        return;
    }
    stack->stackArray[++stack->top] = item;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->stackArray[stack->top--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int eval(char* expression) {
    Stack* stack = createStack();
    int i, operand1, operand2, result;

    for (i = 0; expression[i] != '\0'; i++) {
        if (isDigit(expression[i])) {
            push(stack, expression[i] - '0');
        } else if (isOperator(expression[i])){
            operand2 = pop(stack);
            operand1 = pop(stack);

            switch (expression[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            push(stack, result);
        }
    }

    result = pop(stack);
    free(stack->stackArray);
    free(stack);
    return result;
}

int main() {
    // 배열의 크기를 MAX_SIZE 으로 설정
    char expression[MAX_STACK_SIZE];
    int result; 


    // 표준 입력으로부터 expression 을 입력받음
    printf("postfix Expression: ");
    fgets(expression, sizeof(expression), stdin);

    // eval 함수를 호출하여 결과를 출력
    result = eval(expression);
    printf("Result: %d\n", result);

    return 0;
}