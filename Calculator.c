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

// ���α׷� 4.3 
// ���� ���� ���� �Լ���
// . . .

// ���α׷� 4.6
int check_matching(char* in)
{
}

// ���α׷� 4.7
int eval(char exp[])
{
    // % ������ �߰�
}

// ���α׷� 4.8
int prec(char op)
{
    // % ������ �߰�

}
void infix_to_postfix(char exp[], char post[])  // �Է�(infix): exp[],  ���(postfix): post[]
{
    // % ������ �߰�
    // printf ��� sprintf ����Ͽ� �迭 post�� ����
}


void main()
{
    // ����� �Է�

    // ��ȣ �˻�

    // infix���� postfix�� ��ȯ

    // postfix ���� ���
