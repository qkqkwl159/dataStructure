
#include <stdio.h>
#define MAX_DEGREE 101

typedef struct { 
    int degree;
    float coef[MAX_DEGREE];
} polynomial;

// 두 다항식을 곱하는 함수
polynomial poly_mult(polynomial a, polynomial b) {
    polynomial c; // 결과 다항식
    c.degree = a.degree + b.degree; // 결과 다항식의 최대 차수 계산

    // 결과 다항식의 계수 초기화
    for(int i = 0; i <= c.degree; i++) {
        c.coef[i] = 0;
    }

    // 두 다항식의 각 항을 곱하여 결과 다항식의 계수 계산
    for(int i = 0; i <= a.degree; i++) {
        for(int j = 0; j <= b.degree; j++) {
            c.coef[i + j] += a.coef[i] * b.coef[j];
        }
    }

    return c;
}

void print_poly(polynomial p) {
    for (int i = p.degree; i>0; i--)
        printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
    printf("%3.1f \n", p.coef[p.degree]);
}

int main(void) {
    polynomial a = { 3, { 4, 3, 2, 1} };
    polynomial b = { 2, {3, 2, 8} };
    polynomial c;
    
    print_poly(a);
    print_poly(b);
    
    c = poly_mult(a, b); // 다항식 곱셈 수행
    printf("-----------------------------------------------------------------------------\n");
    print_poly(c); // 결과 출력

    
    return 0;
}
