#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5 //큐 최대 크기

typedef int element; //큐에 담을 타입
typedef struct {
    element data[MAX_SIZE];
    int rear;  //뒤에서 넣기
    int front; //앞에서 빼기
}Queue;

Queue* init() { //큐 초기화
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->rear = -1;
    queue->front = -1;
    return queue;
}

int isEmpty(Queue *q) { //큐 공백 체크
    return q->rear == q-> front;
}

int isFull(Queue *q) { //큐 포화 체크
    return q->rear == MAX_SIZE - 1;
}

void enqueue(Queue *q, element newValue) { //삽입
    if (isFull(q)) { //포화 상태면
        printf("포화 에러 발생");
        exit(1);
    }
    q->data[++q->rear] = newValue;
}

element dequeue(Queue *q) { //추출
    if (isEmpty(q)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    return q->data[++q->front];
}

element peek(Queue *q) { //다음 추출 값 확인
    if (isEmpty(q)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    return q->data[q->front+1];
}

int size(Queue *s) {
    return s->rear - s->front;
}

int main(){
    Queue* q = init();

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    printf("%d\n",dequeue(q));
    enqueue(q,5);


    //enqueue(q,5); //포화 에러 발생

    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));

    //printf("%d\n",dequeue(q)); //공백 에러 발생

    free(q);
}