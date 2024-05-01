#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 5
typedef int element;
typedef struct { // 큐 타입
	element  data[MAX_QUEUE_SIZE];
	int  front, rear;
} QueueType;

// 오류 함수
void error(char *message)
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}


void init_queue(QueueType *q) {
    q->front = q->rear = 0;
}

int is_empty(QueueType *q) {
    return q->front == q->rear;
}

int is_full(QueueType *q) {
    return (q->rear + 1) % MAX_QUEUE_SIZE == q->front;
}

void enqueue(QueueType *q, element item) {
    if (is_full(q)) {
        printf("큐가 포화상태입니다. 원소를 삽입할 수 없습니다.\n");
        // error("큐가 포화상태입니다.");
    }
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
    q->data[q->rear] = item;
}

element dequeue(QueueType *q) {
    if (is_empty(q)) {
        printf("큐가 공백상태입니다. 원소를 삭제할 수 없습니다.\n");
        // error("큐가 공백상태입니다."); 
    }
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
    return q->data[q->front];
}

void print_queue(QueueType *q) {
    int i = q->front;
    do {
        i = (i + 1) % MAX_QUEUE_SIZE;
        printf("%d ", q->data[i]);
        if (i == q->rear) {
            break;
        }
    } while (i != q->front);
    printf("\n");
}

int main() {
    QueueType queue;
    int choice, item;

    init_queue(&queue);

    while (1) {
        printf("1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                exit(0);
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}