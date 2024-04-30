#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define MAX_STACK_SIZE 5

typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;

// 스택이 비어있는지 확인하는 함수
int isEmpty() {
    return top == -1;
}

// 스택이 가득 찼는지 확인하는 함수
int isFull() {
    return top == MAX_STACK_SIZE - 1;
}

// 스택의 top을 증가시키고 top 위치에 원소를 삽입
void push(element item) {
    if (isFull()) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

// 스택의 top에 있는 원소를 반환하고 top을 감소시킴
element pop() {
    if (isEmpty()) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

// stack의 현재 top 값을 반환
element peek() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack[top];
}

// 스택의 모든 원소를 출력
void print_stack() {
    if (isEmpty()) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements: ");
    for (int i = 0; i <= top; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {

    srand(time(NULL));   // 난수 발생을 위한 시드 설정, 한번만 하면 됨
    int rand_num = 0;

    for(int i =0; i<30; i++){       // 30번 반복
        rand_num = rand() % 100 + 1;	// 난수를 1부터 100까지 범위로 한정

        if( (rand_num % 2) == 0){
            printf("current rand_num : %d | Even\n", rand_num);   // rand_num 출력
            if(!isFull()){
                push(rand_num);                                         // 짝수의 경우 push
                printf("Push : %d \n", rand_num);                     
            }
            else
                push(rand_num);                                         //  stack이 가득 차있는 경우 "stack overflow" 출력

            print_stack();  // stack의 모든 원소 출력
            printf("\n");
        } // 짝수
        else{ 
            printf("current rand_num : %d | Odd\n", rand_num);   // rand_num 출력
            int pop_data = pop();                       // 홀수의 경우 pop
            if(pop_data != -1)                      // stack이 비어있지 않은 경우 pop_data 출력
                printf("Pop : %d \n", pop_data);    // stack이 비어있는 경우 "stack underflow" 출력
            print_stack();  // stack의 모든 원소 출력
            printf("\n");
        } // 홀수
    }

    printf("-------------------------------------- \n");
    print_stack();  // stack의 모든 원소 출력

    return 0;
}