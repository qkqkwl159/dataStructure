#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 6
#define MAX_STACK_SIZE 100



typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

typedef struct {
    int data[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack* stack, int item) {
    if (stack->top >= MAX_STACK_SIZE - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack->data[++(stack->top)] = item;
}

int pop(Stack* stack) {
    if (stack->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack->data[(stack->top)--];
}

void enqueue(QueueType* queue, int item) {
    if ((queue->rear + 1) % MAX_QUEUE_SIZE == queue->front) {
        printf("Queue Overflow\n");
        return;
    }
    queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    queue->data[queue->rear] = item;
}

int dequeue(QueueType* queue) {
    if (queue->front == queue->rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    return queue->data[queue->front];
}

int isPalindrome(char* str) {
    Stack stack;
    QueueType queue;
    stack.top = -1;
    queue.front = queue.rear = 0;

    // Remove non-alphabetic characters and convert to lowercase
    int i = 0;
    while (str[i]) {
        if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')) {
            char c = tolower(str[i]);
            printf("%c\n", c);
            push(&stack, c);
            enqueue(&queue, c);
        }
        i++;
    }

    // Check if the characters in stack and queue are the same
    while (stack.top != -1) {
        if (pop(&stack) != dequeue(&queue)) {
            return 0; // Not a palindrome
        }
    }

    return 1; // Palindrome
}

int main() {
    int choice;
    char str[100];

    while (1) {
        printf("1. 회문 입력\n");
        printf("2. 회문 검사\n");
        printf("3. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("회문을 입력하세요: ");
                scanf("%s", str);
                break;
            case 2:
                if (isPalindrome(str)) {
                    printf("회문입니다.\n");
                } else {
                    printf("회문이 아닙니다.\n");
                }
                break;
            case 3:
                return 0;
            default:
                printf("잘못된 메뉴 선택\n");
                break;
        }
    }
}