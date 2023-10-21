//
// Calculator
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100
#define MAX_STR_SIZE   4096

typedef char element;
typedef struct {
    element stack[MAX_STACK_SIZE];
    int top;
}StackType;
void init_stack(StackType* s)
{
    s->top = -1;
}

int is_empty(StackType *s)
{
    return(s->top == -1);

// 프로그램 4.3 
// 스택 동작 관련 함수들
// . . .

// 프로그램 4.6
int check_matching(char* in)
{
}

// 프로그램 4.7
int eval(char exp[])
{
    // % 연산자 추가
}

// 프로그램 4.8
int prec(char op)
{
    // % 연산자 추가

}
void infix_to_postfix(char exp[], char post[])  // 입력(infix): exp[],  결과(postfix): post[]
{
    // % 연산자 추가
    // printf 대신 sprintf 사용하여 배열 post로 저장
}


void main()
{
    // 사용자 입력

    // 괄호 검사

    // infix에서 postfix로 변환

    // postfix 수식 계산
