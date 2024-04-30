#include <stdio.h>
#include <stdlib.h>

#define MAX_EXPRESSION_LENGTH 100


int main(int argc, char* argv[]){
    char infixExpression[MAX_EXPRESSION_LENGTH];
    char postfixExpression[MAX_EXPRESSION_LENGTH];

    while (1) {
        printf("다음과 같은 메뉴로 동작하는 프로그램입니다:\n");
        printf("1. 중위식을 입력 받음\n");
        printf("2. 중위식을 후위식으로 변환\n");
        printf("3. 후위식을 계산\n");
        printf("4. 종료\n");
        printf("메뉴를 선택하세요: ");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("중위식 입력하세요: ");
                // 입력 버퍼를 비우기 위해 getchar() 호출
                getchar(); 
                fgets(infixExpression, sizeof(infixExpression), stdin);
                printf("입력된 중위식 : %s\n", infixExpression);
                break;
            case 2:
                // 코드 작성
                break;
            case 3:
                // 코드 작성
                break;
            case 4:
                // 코드 작성
                printf("프로그램을 종료합니다.\n");
                exit(0);
            // switch문의 else 역할을 하는 default문
            default:
                printf("잘못된 메뉴 선택입니다. 다시 선택하세요.\n");
                break;
        }
    }
    return 0;
}