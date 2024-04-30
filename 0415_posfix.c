#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int* items;
} Stack;

void push(Stack* s, int value) {
    if (s->top == MAX_SIZE - 1) {
        printf("Stack Overflow\n");
        exit(1);
    }
    s->items[++(s->top)] = value;
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        exit(1);
    }
    return s->items[(s->top)--];
}

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int evaluatePostfix(char* expression) {
    Stack s;
    s.top = -1;
    s.items = (int*)malloc(MAX_SIZE * sizeof(int));

    for (int i = 0; expression[i] != '\0'; i++) {
        if (isDigit(expression[i])) {
            push(&s, expression[i] - '0');
            // printf("push: %d\n", expression[i] - '0');
        }
        else if (isOperator(expression[i])) {
            int operand2 = pop(&s);
            int operand1 = pop(&s);
            int result;

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
            }

            push(&s, result);
        }
    }

    int finalResult = pop(&s);
    free(s.items);
    return finalResult;
}

int main() {
    // 배열의 크기를 MAX_SIZE 으로 설정 
    char expression[MAX_SIZE];
    int result;

    printf("postfix Expression: ");
    // 표준 입력으로부터 expression 을 입력받음
    fgets(expression, sizeof(expression), stdin);

    // eval 함수를 호출하여 결과를 출력
    result = evaluatePostfix(expression);
    printf("Result: %d\n", result);

    return 0;
}