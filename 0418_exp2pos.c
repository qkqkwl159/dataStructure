#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EXPRESSION_LENGTH 100
#define MAX_STACK_SIZE 100

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;


void initialize(Stack *s) {
    s->top = -1;
}

// Function to check if the stack is empty
int isEmpty(Stack *s) {
    return (s->top == -1);
}

// Function to check if the stack is full
int isFull(Stack *s) {
    return (s->top == MAX_STACK_SIZE - 1);
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

// 연산자인지 확인하는 함수
int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
}

// 숫자인지 확인하는 함자
int isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

// 여는 괄호인지 확인하는 함수
int isOpeningParenthesis(char ch) {
    return (ch == '(');
}

// 닫는 괄호인지 확인하는 함수
int isClosingParenthesis(char ch) {
    return (ch == ')');
}

// 함수의 우선순위를 반환하는 함수
int getPrecedence(char ch) {
    if (ch == '+' || ch == '-')
        return 1;
    else if (ch == '*' || ch == '/')
        return 2;
    else
        return 0;
}

// 중위식을 후위식으로 변환하는 함수
void infixToPostfix(char* infixExpression, char* postfixExpression) {
    int postfixIndex = 0;

    Stack stack;
    initialize(&stack);

    // 중위식을 순회하면서 후위식으로 변환
    for (int i = 0; infixExpression[i] != '\0'; i++) {
        char ch = infixExpression[i];

        // 연산자일경우 
        if (isOperator(ch)) {
            // 스택이 비어있지 않고, 스택의 top에 있는 연산자의 우선순위가 더 높거나 같을때까지 스택에서 pop
            while (!isEmpty(&stack) && isOperator(stack.data[stack.top]) && getPrecedence(stack.data[stack.top]) >= getPrecedence(ch)) {
                postfixExpression[postfixIndex++] = stack.data[stack.top--];
            }
            // 현재 연산자를 스택에 push
            push(&stack, ch);
        // 여는 괄호일경우
        } else if (isOpeningParenthesis(ch)) {
            // 스택에 push
            push(&stack, ch);
        // 닫는 괄호일경우
        } else if (isClosingParenthesis(ch)) {
            // 스택의 top에 있는 연산자가 여는 괄호가 나올때까지 pop
            while(!isEmpty(&stack) && !isOpeningParenthesis(stack.data[stack.top])) {
                postfixExpression[postfixIndex++] = stack.data[stack.top--];
            }
            // 여는 괄호를 pop
            if( !isEmpty(&stack) && isOpeningParenthesis(stack.data[stack.top])) {
                stack.top--;
            }
        // 숫자일경우
        } else if(isDigit(ch)){
            // 숫자를 후위식에 추가
            postfixExpression[postfixIndex++] = ch;
        }
    }

    // 스택에 남아있는 연산자들을 후위식에 추가
    while(!isEmpty(&stack)) {
        // postfixExpression[postfixIndex++] = stack.data[stack.top--];
        postfixExpression[postfixIndex++] = pop(&stack);
    }
    // 후위식의 끝을 표시
    // 표시하지 않으면 이후에 계산할때, 끝을 알 수 없음
    // \0 을 붙여주는 이유는 새로운 문자열을 만들었기 때문에 끝이 어디인지 알려주기 위함
    postfixExpression[postfixIndex] = '\0';
}

// 후위식을 계산하는 함수
int evaluatePostfix(char* postfixExpression) {
    // int stack[MAX_EXPRESSION_LENGTH];
    // int stackIndex = -1;

    Stack stack;
    initialize(&stack);

    for (int i = 0; postfixExpression[i] != '\0'; i++) {
    //for (int i = 0; i < postfixLength; i++) {
        char ch = postfixExpression[i];

        if (isDigit(ch)) {
            push(&stack, ch - '0');
            // stack[++stackIndex] = ch - '0';
        } else if(isOperator(ch)){

            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            // = stack[stackIndex--];
            // = stack[stackIndex--];

            switch (ch) {
                case '+':
                    push(&stack, operand1 + operand2);
                    // stack[++stackIndex] = operand1 + operand2;
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    // stack[++stackIndex] = operand1 - operand2;
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    // stack[++stackIndex] = operand1 * operand2;
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    // stack[++stackIndex] = operand1 / operand2;
                    break;
            }
        }
    }

    return pop(&stack);
    // return stack[stackIndex];
}

int main() {
    char infixExpression[MAX_EXPRESSION_LENGTH];
    char postfixExpression[MAX_EXPRESSION_LENGTH];


    while (1) {
        printf("다음과 같은 메뉴로 동작하는 프로그램입니다:\n");
        printf("1. 중위식 수식 입력 받음\n");
        printf("2. 중위식 수식을 후위식 수식으로 변환\n");
        printf("3. 후위식 수식을 계산\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("중위식 수식을 입력하세요: ");
                getchar(); // Clear the input buffer
                fgets(infixExpression, sizeof(infixExpression), stdin);
                // fgets(infix.data, sizeof(infix.data), stdin);
                // printf("%s\n", infix.data);
                break;
            case 2:
                infixToPostfix(infixExpression, postfixExpression);
                printf("후위식 수식: %s\n", postfixExpression);
                break;
            case 3:
                printf("계산 결과: %d\n", evaluatePostfix(postfixExpression));
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                exit(0);
            default:
                printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
                break;
        }
    }

    return 0;
}