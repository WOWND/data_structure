#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 //덱 최대 크기


typedef int element; //덱에 담을 타입
typedef struct {
    element data[MAX_SIZE];
    int rear;  //뒤에서 넣고 빼기
    int front; //앞에서 넣고 빼기
    int count;
}Deque;

Deque* init() { //덱 초기화
    Deque *deque = (Deque *) malloc(sizeof(Deque));
    deque->rear = -1;
    deque->front = 0;
    deque->count = 0;
    return deque;
}

int isEmpty(Deque *d) { //덱 공백 체크
    return d->count == 0;
}

int isFull(Deque *d) { //덱 포화 체크
    return d->count == MAX_SIZE;
}

void addFront(Deque *d, element newValue) { //앞에서 삽입
    if (isFull(d)) { //포화 상태면
        printf("포화 에러 발생");
        exit(1);
    }
    d->front = (d->front - 1 + MAX_SIZE) % MAX_SIZE;
    d->count++;
    d->data[d->front] = newValue;
}

void addRear(Deque *d, element newValue) { //뒤에서 삽입
    if (isFull(d)) { //포화 상태면
        printf("포화 에러 발생");
        exit(1);
    }
    d->rear = (d->rear + 1) % MAX_SIZE;
    d->count++;
    d->data[d->rear] = newValue;
}

element deleteFront(Deque *d) { //앞에서 추출
    if (isEmpty(d)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    element item = d->data[d->front];
    d->front = (d->front + 1) % MAX_SIZE;
    d->count--;
    return item;
}

element deleteRear(Deque *d) { //뒤에서 추출
    if (isEmpty(d)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    element item = d->data[d->rear];
    d->rear = (d->rear - 1 + MAX_SIZE) % MAX_SIZE;
    d->count--;
    return item;
}

element getFront(Deque *d) { //앞에서 확인
    if (isEmpty(d)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    return d->data[d->front];
}

element getRear(Deque *d) { //뒤에서 확인
    if (isEmpty(d)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    return d->data[d->rear];
}

int size(Deque *d) {
    return d->count;
}

int main(){
    Deque* d = init();

    addRear(d,10);
    addFront(d,20);
    addRear(d,30);
    addFront(d,40);
    printf("%d\n", getFront(d));
    printf("%d\n", getRear(d));
    printf("%d\n", deleteFront(d));
    printf("%d\n", deleteRear(d));
    printf("%d\n", deleteFront(d));
    printf("%d\n", deleteFront(d));
    printf("%d\n", deleteFront(d)); //공백 에러 발생


    free(d);
}