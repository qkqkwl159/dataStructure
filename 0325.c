#include <stdio.h>
#define MAX_DEGREE 7

typedef struct {
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

polynomial mult(polynomial A, polynomial B)
{
    polynomial C;
    int i, j;

    for (i = 0; i < A.degree + B.degree + 1; i++) C.coef[i] = 0;
    C.degree = A.degree + B.degree;

    for (i = 0; i < A.degree + 1; i++)
        for (j = 0; j < B.degree + 1; j++)
            C.coef[i + j] += A.coef[i] * B.coef[j];

    return C;
}
int main(){
    polynomial a = {4, {0, 0, 2, 2, 3, 0, 0}};
    polynomial b = {2, {7, 3, 4, 0, 0, 0, 0}};
    polynomial c;
    int i;

    c = mult(a, b);
    printf("%d차 ", c.degree);
    for (i = 0; i < c.degree + 1; i++)
        printf("%.0f ", c.coef[i]); // float 형이므로 %f를 사용하고, 정수처럼 출력하기 위해 .0을 추가합니다.

    return 0;
}
