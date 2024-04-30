#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101
// struct {
// 	float coef;
// 	int expon;
// } terms[MAX_TERMS]={ {8,3}, {7,1}, {1,0}, {10,3}, {3,2},{1,0} };
// int avail=6;
struct term{
	float coef;
	int expon;
}terms[MAX_TERMS] = { 
	{7.0, 6} , {5.0, 3} , {9.0 , 2}, {1.0, 0},
  {5.0 , 3} , {2.0, 2} , {1.0, 1}, {10.0, 0}
	// {4.0, 3} , {3.0, 2} , {2.0 , 1}, {1.0, 0},
	// {3.0 , 2} , {2.0, 1} , {8.0, 0} 
};
int avail = 8;
// int avail = 7;

// 두 개의 정수를 비교
char compare(int a, int b)
{
	if( a>b ) return '>';
	else if( a==b ) return '=';
	else return '<';
}

// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if( avail>MAX_TERMS ){
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef=coef;
	terms[avail++].expon=expon;
}
// C = A + B
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce) 
{	
	float tempcoef;
	*Cs = avail;
	while( As <= Ae && Bs <= Be )
	 switch(compare(terms[As].expon,terms[Bs].expon)){ 
	 case '>': 	// A의 차수 > B의 차수
		attach(terms[As].coef, terms[As].expon);
		As++;			break;
	 case '=': 	// A의 차수 == B의 차수
		tempcoef = terms[As].coef + terms[Bs].coef;
		if( tempcoef ) 
		 attach(tempcoef,terms[As].expon);
		As++; Bs++;		break;
	 case '<': 	// A의 차수 < B의 차수
		attach(terms[Bs].coef, terms[Bs].expon);
		Bs++;			break;
	}
	// A의 나머지 항들을 이동함
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	// B의 나머지 항들을 이동함
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}

void poly_multi(int As, int Ae, int Bs, int Be, int *Csp, int *Cep)
{
	int Cs = avail;
	//불필요 변수
	// float coef;
	// int expon;

   
	for (int i = As; i <= Ae; i++) {
		for (int j = Bs; j <= Be; j++) {
			for(int k = Cs; k < avail; k++){
				if(terms[k].expon == terms[i].expon + terms[j].expon){
					terms[k].coef += terms[i].coef * terms[j].coef;
					break;
				}
				Cs++;
			}
			// terms[Cs].coef = terms[i].coef * terms[j].coef;
			// terms[Cs].expon = terms[i].expon + terms[j].expon;

			
			// terms[k].coef = coef;
			// terms[k].expon = expon;
		}
	}

	
	*Csp = avail;
	*Cep= Cs - 1;

	avail = Cs;
}

void print_poly(int s, int e)
{
	for (int i = s; i < e; i++)
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon);
	printf("%3.1fx^%d\n", terms[e].coef, terms[e].expon);
}

//
int main(void)
{
	int As = 0, Ae = 3, Bs = 4, Be = 7, Cs, Ce;
	// int As = 0, Ae = 3, Bs = 4, Be = 6, Cs, Ce;
	// int As = 0, Ae = 2, Bs = 3, Be = 5, Cs, Ce;
	// poly_add2(As, Ae, Bs, Be, &Cs, &Ce);
	poly_multi(As, Ae, Bs, Be, &Cs, &Ce);
	print_poly(As, Ae);
	print_poly(Bs, Be);
	printf("-----------------------------------------------------------------------------\n");
	// print_poly(Cs, Ce);
	print_poly(8, 24);
	return 0;
}


