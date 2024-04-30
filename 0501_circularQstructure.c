#include <stdio.h>
#include <stdlib.h>


#define MAX_QUEUE_SIZE 6
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
    if(is_full(q)) {
        // error("큐가 포화상태입니다.");
        printf("큐가 포화상태입니다.\n");
    }
    else {
        q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
        q->data[q->rear] = item;
    }
}

element dequeue(QueueType *q) {
    if(is_empty(q)) {
        // error("큐가 공백상태입니다.");
        printf("큐가 공백상태입니다.\n");
        return 0;
    }
    else {
        q->front = (q->front + 1) % MAX_QUEUE_SIZE;
        printf("큐에서 삭제된 원소: %d\n", q->data[q->front]);
        return q->data[q->front];
    }
}

void print_queue(QueueType *q) {
    int i = q->front;
    if(is_empty(q)) {
        printf("큐가 비어있습니다.\n");
        return;
    }
    else {
        do {
            i = (i + 1) % MAX_QUEUE_SIZE;
            printf("%d ", q->data[i]);
            if (i == q->rear) {
                break;
            }
        } while (i != q->front);
        printf("\n");
    }
}

int main() {
    QueueType queue;
    int choice, item;

    init_queue(&queue);

    while (1) {
        printf("\n");
        printf("1. 큐에 원소를 삽입\n");
        printf("2. 큐에서 원소를 삭제\n");
        printf("3. 큐의 원소를 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("큐에 삽입할 숫자를 입력하세요: ");
                scanf("%d", &item);
                enqueue(&queue, item);
                break;
            case 2:
                item = dequeue(&queue);
                break;
            case 3:
                printf("---------------------\n");
                printf("현재 큐의 상태: ");
                print_queue(&queue);
                printf("---------------------\n");
                break;
            case 4:
                exit(0);
            default:
                printf("잘못된 선택입니다.\n");
        }
    }

    return 0;
}