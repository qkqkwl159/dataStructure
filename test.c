#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef int element;
typedef struct {
    element array[MAX_SIZE];
    int size;
} ArrayListType;

void error(char *message) {
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void init(ArrayListType *L) {
    L->size = 0;
}

int is_empty(ArrayListType *L) {
    return L->size == 0;
}

int is_full(ArrayListType *L) {
    return L->size == MAX_SIZE;
}

element get_entry(ArrayListType *L, int pos) {
    if (pos < 0 || pos >= L->size) {
        error("위치 오류");
    }
    return L->array[pos];
}

void print_list(ArrayListType *L) {
    int i;
    for (i = 0; i < L->size; i++) {
        printf("%d -> ", L->array[i]);
    }
    printf("NULL\n");
}

void insert_last(ArrayListType *L, element item, int *move_count) {
    if (is_full(L)) {
        error("리스트 오버플로우");
    }
    L->array[L->size++] = item;
    *move_count += 1;
}

void insert(ArrayListType *L, int pos, element item, int *move_count) {
    if (!is_full(L) && (pos >= 0) && (pos <= L->size)) {
        for (int i = L->size - 1; i >= pos; i--) {
            L->array[i + 1] = L->array[i];
            (*move_count)++;
        }
        L->array[pos] = item;
        L->size++;
    } else {
        error("리스트 오버플로우 또는 위치 오류");
    }
}

element delete(ArrayListType *L, int pos, int *move_count) {
    if (pos < 0 || pos >= L->size) {
        error("위치 오류");
    }
    element item = L->array[pos];
    for (int i = pos; i < L->size - 1; i++) {
        L->array[i] = L->array[i + 1];
        (*move_count)++;
    }
    L->size--;
    return item;
}

int main() {
    ArrayListType list;
    init(&list);
    int choice, num, position, move_count = 0;

    while (1) {
        printf("\n메뉴:\n");
        printf("1. 리스트에 추가\n");
        printf("2. 리스트에서 삭제\n");
        printf("3. 리스트 출력\n");
        printf("0. 프로그램 종료\n");
        printf("선택: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (is_full(&list)) {
                printf("리스트가 꽉 찼습니다.\n");
            } else {
            }
            break;
        case 2:
            if (is_empty(&list)) {
                printf("리스트가 비어있습니다.\n");
            } else {
            }
            break;
        case 3:
            break;
        case 0:
            printf("프로그램 종료\n");
            return 0;
        default:
            printf("잘못된 선택입니다. 다시 시도하세요.\n");
        }
    }

    return 0;
}

