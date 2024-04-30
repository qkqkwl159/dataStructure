#include <stdio.h>
#define MAX_TERMS 101

void print_poly(int s, int e);
void poly_multi(int As, int Ae, int Bs, int Be, int* Csp, int* Cep);

struct term {
	float coef;
	int expon;
} terms[MAX_TERMS] = /*결과 조건 1*/ { {4.0,3},{3.0,2},{2.0,1},{1.0,0}, {3.0,2},{2.0,1},{8.0,0} };
					 /*결과 조건 2*/ //{{7.0,6},{5.0,3},{9.0,2},{1.0,0}, {5.0,3},{2.0,2},{1.0,1},{10.0,0}};

int avail = 7; //결과 조건 1
//int avail = 8; //결과 조건 2

int main() {
	int Cs, Ce;

	/**/
	//결과 조건 1
	printf("A = ");
	print_poly(0, 3);
	printf("B = ");
	print_poly(4, 6);

	poly_multi(0, 3, 4, 6, &Cs, &Ce);
	printf("A*B = ");
	print_poly(Cs, Ce);
	
	/* 
	//결과 조건 2
	printf("A = ");
	print_poly(0, 3);
	printf("B = ");
	print_poly(4, 7);

	poly_multi(0, 3, 4, 7, &Cs, &Ce);
	printf("A*B = ");
	print_poly(Cs, Ce);
	*/
	return 0;
}

void poly_multi(int As, int Ae, int Bs, int Be, int* Csp, int* Cep) {
	int Cs = avail;
	int c = avail;
	for (int i = As; i <= Ae; i++) {
		for (int j = Bs; j <= Be; j++) {
			int same_e = 0;
			for (int k = Cs; k < c; k++) {
				if (terms[k].expon == terms[i].expon + terms[j].expon) {
					terms[k].coef += terms[i].coef * terms[j].coef;
					same_e++;
					break;
				}
				else if (terms[k].expon < terms[c].coef) {
					for (int m = c - 1; m > k; m--) {
						terms[m].expon = terms[m + 1].expon;
						terms[m].coef = terms[m + 1].coef;
						same_e++;
					}
					terms[c].expon = terms[i].expon + terms[j].expon;
					terms[c].coef = terms[i].coef * terms[j].coef;
					c++;
					break;
				}
			}
			if (same_e == 0) {
				terms[c].expon = terms[i].expon + terms[j].expon;
				terms[c].coef = terms[i].coef * terms[j].coef;
				c++;
			}
		}
	}
	int Ce = c - 1;
	*Csp = Cs;
	*Cep = Ce;
	avail = c;
}

void print_poly(int s, int e) {
	for (int i = s; i < e; i++) {
		printf("%3.1fX^%d + ", terms[i].coef, terms[i].expon);
	}
	printf("%3.1f\n", terms[e].coef);
}