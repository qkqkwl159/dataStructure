
#include <stdio.h>

#define MAX_SIZE 100

void insertElement(int array[], int* size, int num, int position, int* move_count) {
    if (*size >= MAX_SIZE) {
        printf("리스트가 가득 찼습니다.\n");
        return;
    }

    if (position > *size) {
        position = *size;
    }

    *move_count = 0;
    for (int i = *size; i > position; i--) {
        array[i] = array[i - 1];
        (*move_count)++;
    }
    array[position] = num;
    (*size)++;
}

void deleteElement(int array[], int* size, int position, int* move_count) {
    if (position >= *size) {
        printf("유효하지 않은 위치입니다.\n");
        return;
    }

    *move_count = 0;
    for (int i = position; i < *size - 1; i++) {
        array[i] = array[i + 1];
        (*move_count)++;
    }
    (*size)--;
}

void printList(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int array[MAX_SIZE];
    int size = 0;
    int choice, num, position, move_count;

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
            printf("추가할 숫자: ");
            scanf("%d", &num);
            printf("위치: ");
            scanf("%d", &position);
            insertElement(array, &size, num, position, &move_count);
            printf("삽입 완료, 데이터 이동 횟수: %d\n", move_count);
            break;
        case 2:
            printf("삭제할 위치: ");
            scanf("%d", &position);
            deleteElement(array, &size, position, &move_count);
            printf("삭제 완료, 데이터 이동 횟수: %d\n", move_count);
            break;
        case 3:
            printf("리스트 내용:\n");
            printList(array, size);
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
