#include <stdio.h>

// [1] 배열의 전역변수 사용
#define MAX_STACK_SIZE 5
typedef int element;
element stack[MAX_STACK_SIZE];
int top = -1;



int main(int argc, char* argv[]){

    srand(time(NULL));  
	 // 난수 발생을 위한 시드 설정, 한번만 하면 됨
	int rand_num = rand() % 100 + 1;	
    int data;
	// 난수를 1부터 100까지 범위로 한정
	if( (rand_num % 2) == 0) // 짝수
		push(rand_num);
	else 
		data = pop();
    return 0;
}


