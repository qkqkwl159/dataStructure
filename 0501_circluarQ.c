#include <stdio.h>

#define MAX_SIZE 5

int front = -1, rear = -1;
int queue[MAX_SIZE];

int isFull() {
    if ((front == 0 && rear == MAX_SIZE - 1) || (rear == front - 1))
        return 1;
    else
        return 0;
}

int isEmpty() {
    if (front == -1)
        return 1;
    else
        return 0;
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert element.\n");
    } else {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        printf("Element %d inserted successfully.\n", item);
    }
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue is empty. Cannot remove element.\n");
    } else {
        int item = queue[front];
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        printf("Element %d removed successfully.\n", item);
    }
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
    } else {
        printf("Queue elements: ");
        int i = front;
        while (i != rear) {
            printf("%d ", queue[i]);
            i = (i + 1) % MAX_SIZE;
        }
        printf("%d\n", queue[rear]);
    }
}

int main() {
    int choice, item;
    
    do {
        printf("\nMenu:\n");
        printf("1. 원형큐에 원소 삽입\n");
        printf("2. 원형큐에서 원소 삭제\n");
        printf("3. 원형큐 출력\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}