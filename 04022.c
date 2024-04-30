#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

struct term{
	float coef;
	int expon;
}terms[MAX_TERMS] = { 
	{7.0, 6} , {5.0, 3} , {9.0 , 2}, {1.0, 0},
  {5.0 , 3} , {2.0, 2} , {1.0, 1}, {10.0, 0}
//	{4.0, 3} , {3.0, 2} , {2.0 , 1}, {1.0, 0},
//	{3.0 , 2} , {2.0, 1} , {8.0, 0} 
};
int avail = 8;
//int avail = 7;

char compare(int a, int b)
{
	if( a>b ) return '>';
	else if( a==b ) return '=';
	else return '<';
}

void attach(float coef, int expon){
	if( avail >= MAX_TERMS){
		fprintf(stderr, "lots of terms...\n");
		exit(1);
	}
	terms[avail].coef=coef;
	terms[avail++].expon=expon;
}

void print_poly(int s , int e){
	for(int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d + \n", terms[e].coef, terms[e].expon);
}


void poly_multiply(int startA, int finishA, int startB, int finishB, int *startC , int *finishC) {
    struct term temp[MAX_TERMS];
    int tempIndex = 0;
    *startC = avail;

    // 곱셈 결과를 임시 배열에 저장
    for (int i = startA; i <= finishA; i++) {
        for (int j = startB; j <= finishB; j++) {
            float coef = terms[i].coef * terms[j].coef;
            int expon = terms[i].expon + terms[j].expon;
            // 임시 배열에 추가
            temp[tempIndex].coef = coef;
            temp[tempIndex++].expon = expon;
        }
    }

    // 임시 배열을 지수에 따라 정렬 (단순 버블 정렬 사용)
    for (int i = 0; i < tempIndex - 1; i++) {
        for (int j = 0; j < tempIndex - i - 1; j++) {
            if (temp[j].expon < temp[j + 1].expon) {
                struct term t = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = t;
            }
        }
    }

    // 정렬된 배열을 순회하며 같은 지수의 항을 합칩니다.
    for (int i = 0; i < tempIndex; i++) {
        float coef = temp[i].coef;
        int expon = temp[i].expon;
        while (i + 1 < tempIndex && temp[i].expon == temp[i + 1].expon) {
            coef += temp[i + 1].coef;
            i++;
        }
        // 최종적으로 합쳐진 결과를 terms 배열에 추가
        attach(coef, expon);
    }

    *finishC = avail - 1;
}

int main(int argc, char* argv[]){

	int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
//	int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;
	poly_multiply(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("------------------------\n");
	print_poly(Cs, Ce);
    print_poly(As, Ae);


	return 0;
}

