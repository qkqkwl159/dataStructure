#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int items[MAX_SIZE];
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

int eval(char* expression) {

    //fgets 로 입력받은 expression 을 순회 하는 방법 

    for (int i = 0; expression[i] != '\0'; i++) {
        printf("expression : %c\n",  expression[i]);
        if(숫자 일경우){
            
        }
        else if(연산자 일경우){
            
        }
        /* else (공백일 경우) -> else를 사용하게되면 공백을 따로 처리하기 때문에, 
        else를 사용하지 않는다.*/
    }

    return 결과값;
}

int main() {
    // 배열의 크기를 MAX_SIZE 으로 설정 
    char expression[MAX_SIZE];
    int result;

    printf("postfix Expression: ");
    // 표준 입력으로부터 expression 을 입력받음
    fgets(expression, sizeof(expression), stdin);
    evaluatePostfix(expression);

    // evaluatePostfix 함수를 호출하여 결과를 출력
    // result = evaluatePostfix(expression);
    // printf("Result: %d\n", result);

    return 0;
}