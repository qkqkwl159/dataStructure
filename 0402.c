#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

struct term{
	float coef;
	int expon;
}terms[MAX_TERMS] = { 
	{8.0, 3} , {7.0, 1} , {1.0 , 0},
	{10.0 , 3} , {3.0, 2} , {1.0, 0}
};
int avail = 6;

void print_poly(int s , int e){
	for(int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d + \n", terms[e].coef, terms[e].expon);
}

void attach(float coef, int expon){
	if( avail> MAX_TERMS){
		fprintf(stderr, "lots of terms...\n");
		exit(1);
	}
	terms[avail].coef=coef;
	terms[avail++].expon=expon;
}

void poly_multiply(int startA, int finishA, int startB, int finishB) {
    int startResult = avail;
    for (int i = startA; i <= finishA; i++) {
        for (int j = startB; j <= finishB; j++) {
            float coef = terms[i].coef * terms[j].coef;
            int expon = terms[i].expon + terms[j].expon;
            // 여기서 attach 함수를 사용하여 결과 다항식에 추가합니다.
            // 이 예제에서는 중복된 지수를 처리하지 않습니다.
            // 실제 구현에서는 중복된 지수를 합치는 로직이 필요합니다.
            attach(coef, expon);
        }
    }
    int finishResult = avail - 1;
    // 결과 다항식 출력
    print_poly(startResult, finishResult);
}

int main(int argc, char* argv[]){

	print_poly(0,2);
	print_poly(3,5);

	printf("---------------------\n");
	poly_multiply(0 , 2 , 3, 5);

	return 0;
}

