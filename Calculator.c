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

// ���α׷� 4.3 
// ���� ���� ���� �Լ���
// . . .                               
// ���� �ʱ�ȭ �Լ�
void init_stack(StackType *s)
{
    s->top = -1;            // ������ -1�� �ʱ�ȭ �������μ� ������·� ����
}
// ���� ���� ���� �Լ�
int is_empty(StackType *s)  // ������ ������¸� �����ϱ����� �Լ�
{
    return(s->top == -1);
}
// ��ȭ ���� ���� �Լ�
int is_full(StackType *s)           // ������ ������ ��Ÿ���� -1�� ��������
{
    return(s->top==(MAX_STACK_SIZE-1)); // ������ full ���¸� Ȯ���ϱ����� MAX_STACK_SIZE�� -1�� ����
}                                       // -1 �� ���ִ� ������ ó�� �����Ҷ� -1 ���� �����߱⶧���� ��������� -1 �� �������
/*
// �����Լ�
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return;
	}
	else s->stack[++(s->top)] = item;
	    // push 
	
}
// �����Լ�
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else 
	return s->stack[(s->top)--];
	    // pop
	    
}
// ��ũ�Լ�
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		exit(1);
	}
	else
	    return s->stack[s->top];
	    // peek
	    
}
*/
// (������ ���� �Լ�)
void push(StackType *s, element item) {
    if (is_full(s)) {
        printf("���� ��ȭ ����");
        return;
    } 
    else s->data[++(s->top)] = item;
}
// (������ ���� �Լ�)
element pop(StackType *s) {
    if(is_empty(s)) {
        printf("���� ���� ����");
        return 0;
    }
    else return s->data[(s->top)--]; // ���� ���°� �ƴ� ��� ���� ����
}
// (TOP Ȯ�� �Լ�)
element peek(StackType *s) {
    if (is_empty(s)) {
        printf("���� ���� ����");
        return 0;
    }
    else return s->data[s->top]; // ���� ���°� �ƴ� ��� Top�� ��ȯ
}


// ���α׷� 4.6
int check_matching(const char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  	// n= ���ڿ��� ����
	init_stack(&s);			// ������ �ʱ�ȭ

	for (i = 0; i < n; i++) {
		ch = in[i];		// ch = ���� ����
		switch (ch) {
		case '(':   case '[':    case '{':
            // push
            push(&s,ch);
            break;
            
		case ')':   case ']':    case '}':
            // pop �Ͽ� ��. unmatch�̸� 0�� return
            if(is_empty(&s) != 0) return 0;
            else
            {
                open_ch = pop(&s);
                if((open_ch == '('&&ch!=')')||(open_ch == '['&&ch!=']')||(open_ch == '{'&&ch!='}'))
                
                return 0;
            }
            
            break;

		}
	}
	if (!is_empty(&s)) return 0; // ���ÿ� ���������� unmatch
	return 1;   // match�̸� 1�� return
}

// (���� ǥ�� ���� ��� �Լ�) 
int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    
    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        // ch�� �ǿ������̸� push. ch�� �����̹Ƿ� ������ ��ȯ�Ͽ� push
        if ( ch != '+' && ch != '-' && ch != '*' && ch != '/' )
        {
            value = ch - '0';
            push(&s, value);
        }
        
        // �׷��� ������(�������̸�), pop �� �� �� ���� ����. ����� push
        else 
        {
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){
                case '+' : push(&s,op1+op2); break;
                case '-' : push(&s,op1-op2); break;
                case '*' : push(&s,op1*op2); break;
                case '/' : push(&s,op1/op2); break;
            }
        }
        
        
    }
    return pop(&s);
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
    char    *line = NULL;
	size_t     size;
	getline(&line, &size, stdin);    // &line �� **��
	if (check_matching(line) == 1)
		printf("%s ��ȣ�˻缺��\n", line);
	else
		printf("%s ��ȣ�˻����\n", line);
	return 0;
    // infix���� postfix�� ��ȯ

    // postfix ���� ���
    char    postfix[100];

    scanf("%s", postfix);
    printf("%d\n", eval(postfix)); // ���� ����� ���
}