#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 //스택 최대 크기

typedef int element; //스택에 담을 타입
typedef struct {
    element data[MAX_SIZE];
    int top;
}Stack;

Stack* init() { //스택 초기화
    Stack *stack = (Stack *) malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack *s) { //스택 공백 체크
   return s->top == -1;
}

int isFull(Stack *s) { //스택 포화 체크
    return s->top == MAX_SIZE - 1;
}

void push(Stack *s, element newValue) { //삽입
    if (isFull(s)) { //포화 상태면
        printf("포화 에러 발생");
        exit(1);
    }
    s->data[++s->top] = newValue;
}

element pop(Stack *s) { //추출
    if (isEmpty(s)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    return s->data[s->top--];
}

element peek(Stack *s) { //맨 위의 값 확인
    if (isEmpty(s)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    return s->data[s->top];
}

int size(Stack *s) {
    return s->top + 1;
}


int main() {
    Stack *stack = init();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);
    //push(stack, 6);  포화 에러 발생

    printf("%d\n", peek(stack));

    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    printf("%d\n", pop(stack));
    //printf("%d\n", pop(stack)); 공백 에러 발생

    free(stack);

}
