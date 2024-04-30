
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    float coef;
    int expon;
} PolynomialTerm;

void read_poly(PolynomialTerm** poly, int* n) {
    printf("다항식의 총 항의 수를 입력하시오? ");
    scanf("%d", n);
    *poly = (PolynomialTerm*)malloc(*n * sizeof(PolynomialTerm));
    for (int i = 0; i < *n; i++) {
        printf("[%d번째 계수, 차수] ", i + 1);
        scanf("%f %d", &((*poly)[i].coef), &((*poly)[i].expon));
    }
}

void print_poly(PolynomialTerm* poly, int n) {
    for (int i = 0; i < n; i++) {
        printf("%3.1fx^%d ", poly[i].coef, poly[i].expon);
        if (i < n - 1) printf("+ ");
    }
    printf("\n");
}

PolynomialTerm* poly_add(PolynomialTerm* A, int An, PolynomialTerm* B, int Bn, int* Cn) {
    PolynomialTerm* tempC = (PolynomialTerm*)malloc((An + Bn) * sizeof(PolynomialTerm));
    int i = 0, j = 0, k = 0;

    while (i < An && j < Bn) {
        if (A[i].expon > B[j].expon) {
            tempC[k++] = A[i++];
        } else if (A[i].expon < B[j].expon) {
            tempC[k++] = B[j++];
        } else { // A[i].expon == B[j].expon
            tempC[k].coef = A[i].coef + B[j].coef;
            tempC[k].expon = A[i].expon;
            i++; j++; k++;
        }
    }

    // 남은 항들을 결과 다항식에 추가
    while (i < An) tempC[k++] = A[i++];
    while (j < Bn) tempC[k++] = B[j++];

    *Cn = k; // 결과 다항식의 항 개수를 설정
    PolynomialTerm* C = (PolynomialTerm*)realloc(tempC, k * sizeof(PolynomialTerm)); // 메모리 크기 조정
    return C;
}
void merge_and_sort_poly(PolynomialTerm** poly, int* n) {
    // 임시 배열을 동적 할당
    PolynomialTerm* temp = (PolynomialTerm*)malloc((*n) * sizeof(PolynomialTerm));
    int tempIndex = 0;
    for (int i = 0; i < *n; i++) {
        if ((*poly)[i].coef == 0) continue; // 계수가 0인 항은 무시
        for (int j = i + 1; j < *n; j++) {
            // 동일 차수의 항을 찾아 계수를 합침
            if ((*poly)[i].expon == (*poly)[j].expon) {
                (*poly)[i].coef += (*poly)[j].coef;
                (*poly)[j].coef = 0; // 합친 항은 제외
            }
        }
        temp[tempIndex++] = (*poly)[i]; // 임시 배열에 저장
    }
    *n = tempIndex; // 새로운 항의 개수 업데이트
    free(*poly); // 원래 배열 메모리 해제
    *poly = temp; // 임시 배열을 원래 배열 포인터에 연결
}

PolynomialTerm* poly_mul(PolynomialTerm* A, int An, PolynomialTerm* B, int Bn, int* Cn) {
    *Cn = An * Bn;
    PolynomialTerm* C = (PolynomialTerm*)malloc(*Cn * sizeof(PolynomialTerm));
    int k = 0;
    for (int i = 0; i < An; i++) {
        for (int j = 0; j < Bn; j++) {
            C[k].coef = A[i].coef * B[j].coef;
            C[k].expon = A[i].expon + B[j].expon;
            k++;
        }
    }
    // 여기서 결과 다항식 C의 정리(항 병합 및 정렬) 로직을 추가할 수 있습니다.
		merge_and_sort_poly(&C, Cn);
    return C;
}

int main() {
    PolynomialTerm *A, *B, *C;
    int An, Bn, Cn;

    printf("첫 번째 다항식 입력\n");
    read_poly(&A, &An);
    printf("입력된 다항식은 다음과 같습니다: ");
    print_poly(A, An);

    printf("두 번째 다항식 입력\n");
    read_poly(&B, &Bn);
    printf("입력된 다항식은 다음과 같습니다: ");
    print_poly(B, Bn);

    C = poly_mul(A, An, B, Bn, &Cn);
    //C = poly_add(A, An, B, Bn, &Cn);
    printf("A * B = ");
    //printf("A + B = ");
    print_poly(C, Cn);

    free(A);
    free(B);
    free(C);

    return 0;
}
