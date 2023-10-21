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

// 프로그램 4.3 
// 스택 동작 관련 함수들
// . . .                               
// 스택 초기화 함수
void init_stack(StackType *s)
{
    s->top = -1;            // 스택을 -1로 초기화 해줌으로서 공백상태로 만듬
}
// 공백 상태 검출 함수
int is_empty(StackType *s)  // 스택의 공백상태를 검출하기위한 함수
{
    return(s->top == -1);
}
// 포화 상태 검출 함수
int is_full(StackType *s)           // 스택의 공백을 나타내는 -1로 선언해줌
{
    return(s->top==(MAX_STACK_SIZE-1)); // 스택의 full 상태를 확인하기위해 MAX_STACK_SIZE에 -1을 해줌
}                                       // -1 을 해주는 이유는 처음 시작할때 -1 부터 시작했기때문에 결과값에도 -1 을 해줘야함
/*
// 삽입함수
void push(StackType *s, element item)
{
	if (is_full(s)) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else s->stack[++(s->top)] = item;
	    // push 
	
}
// 삭제함수
element pop(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else 
	return s->stack[(s->top)--];
	    // pop
	    
}
// 피크함수
element peek(StackType *s)
{
	if (is_empty(s)) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else
	    return s->stack[s->top];
	    // peek
	    
}
*/
// (데이터 삽입 함수)
void push(StackType *s, element item) {
    if (is_full(s)) {
        printf("스택 포화 오류");
        return;
    } 
    else s->data[++(s->top)] = item;
}
// (데이터 삭제 함수)
element pop(StackType *s) {
    if(is_empty(s)) {
        printf("스택 공백 오류");
        return 0;
    }
    else return s->data[(s->top)--]; // 공백 상태가 아닐 경우 스택 삭제
}
// (TOP 확인 함수)
element peek(StackType *s) {
    if (is_empty(s)) {
        printf("스택 공백 오류");
        return 0;
    }
    else return s->data[s->top]; // 공백 상태가 아닐 경우 Top값 반환
}


// 프로그램 4.6
int check_matching(const char *in)
{
	StackType s;
	char ch, open_ch;
	int i, n = strlen(in);  	// n= 문자열의 길이
	init_stack(&s);			// 스택의 초기화

	for (i = 0; i < n; i++) {
		ch = in[i];		// ch = 다음 문자
		switch (ch) {
		case '(':   case '[':    case '{':
            // push
            push(&s,ch);
            break;
            
		case ')':   case ']':    case '}':
            // pop 하여 비교. unmatch이면 0을 return
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
	if (!is_empty(&s)) return 0; // 스택에 남아있으면 unmatch
	return 1;   // match이면 1을 return
}

// (후위 표기 수식 계산 함수) 
int eval(char exp[])
{
    int op1, op2, value, i = 0;
    int len = strlen(exp);
    char ch;
    StackType s;
    
    init_stack(&s);
    for (i = 0; i < len; i++) {
        ch = exp[i];
        // ch가 피연산자이면 push. ch는 문자이므로 값으로 변환하여 push
        if ( ch != '+' && ch != '-' && ch != '*' && ch != '/' )
        {
            value = ch - '0';
            push(&s, value);
        }
        
        // 그렇지 않으면(연산자이면), pop 두 번 후 연산 수행. 결과값 push
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
    char    *line = NULL;
	size_t     size;
	getline(&line, &size, stdin);    // &line 은 **형
	if (check_matching(line) == 1)
		printf("%s 괄호검사성공\n", line);
	else
		printf("%s 괄호검사실패\n", line);
	return 0;
    // infix에서 postfix로 변환

    // postfix 수식 계산
    char    postfix[100];

    scanf("%s", postfix);
    printf("%d\n", eval(postfix)); // 수식 결과값 출력
}