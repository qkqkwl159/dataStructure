#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

ListNode* insert_first(ListNode *head, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if (!p) error("메모리 할당 오류");
    p->data = value;
    p->link = head;
    return p;
}

ListNode* insert(ListNode *head, ListNode *pre, element value) {
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    if (!p) error("메모리 할당 오류");
    p->data = value;
    p->link = pre->link;
    pre->link = p;
    return head;
}

ListNode* delete_first(ListNode *head) {
    if (head == NULL) return NULL;
    ListNode *removed = head;
    head = head->link;
    free(removed);
    return head;
}

ListNode* delete(ListNode *head, ListNode *pre) {
    if (pre == NULL || pre->link == NULL) return head;
    ListNode *removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

void print_list(ListNode *head) {
    for (ListNode *p = head; p != NULL; p = p->link) {
        printf("%d -> ", p->data);
    }
    printf("NULL\n");
}

int main() {
    ListNode *head = NULL;
    int choice, value, position, count;
    ListNode *pre;

    while (1) {
        printf("메뉴:\n");
        printf("1. 숫자를 위치에 삽입\n");
        printf("2. 위치에서 숫자 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택하세요: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("삽입할 숫자를 입력하세요: ");
                scanf("%d", &value);
                printf("삽입할 위치를 입력하세요: ");
                scanf("%d", &position);
                
                if (position == 0) {
                    head = insert_first(head, value);
                    count = 1;
                } else {
                    pre = head;
                    count = 1;
                    for (int i = 1; i < position - 1 && pre != NULL; i++) {
                        count++;
                        pre = pre->link;
                    }
                    if (pre == NULL) {
                        printf("유효하지 않은 위치입니다!\n");
                        continue;
                    }
                    head = insert(head, pre, value);
                    count++;
                }
                printf("삽입시 링크를 따라 이동한 횟수: %d\n", count);
                break;
            case 2:
                printf("삭제할 위치를 입력하세요: ");
                scanf("%d", &position);
                
                if (position == 0) {
                    head = delete_first(head);
                    count = 1;
                } else {
                    pre = head;
                    count = 1;
                    for (int i = 1; i < position - 1 && pre != NULL; i++, count++) {
                        pre = pre->link;
                    }
                    if (pre == NULL || pre->link == NULL) {
                        printf("유효하지 않은 위치입니다!\n");
                        continue;
                    }
                    head = delete(head, pre);
                    count++;
                }
                printf("삭제시 링크를 따라 이동한 횟수: %d\n", count);
                break;
            case 3:
                print_list(head);
                break;
            case 0:
                exit(0);
            default:
                printf("유효하지 않은 선택입니다!\n");
        }
    }

    return 0;
}
