#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5
//원형큐 v2 count 변수를 사용
// (모든 칸을 사용하는 방식)

typedef int element; //큐에 담을 타입
typedef struct {
    element data[MAX_SIZE];
    int rear;  //뒤에서 넣기
    int front; //앞에서 빼기
    int count;
}Queue;

Queue* init() { //큐 초기화
    Queue *queue = (Queue *) malloc(sizeof(Queue));
    queue->rear = -1;
    queue->front = -1;
    queue->count = 0;
    return queue;
}

int isEmpty(Queue *q) { //큐 공백 체크
    return q->count == 0;
}

int isFull(Queue *q) { //큐 포화 체크
    return q->count == MAX_SIZE;
}

void enqueue(Queue *q, element newValue) { //삽입
    if (isFull(q)) { //포화 상태면
        printf("포화 에러 발생");
        exit(1);
    }
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->count++;
    q->data[q->rear] = newValue;
}

element dequeue(Queue *q) { //추출
    if (isEmpty(q)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    q->front = (q->front + 1) % MAX_SIZE;
    q->count--;
    return q->data[q->front];
}

element peek(Queue *q) { //추출
    if (isEmpty(q)) { //공백 상태면
        printf("공백 에러 발생");
        exit(1);
    }
    return q->data[(q->front + 1) % MAX_SIZE];
}

int size(Queue *q) {
    return q->count;
}

int main(){
    Queue* q = init();

    enqueue(q,1);
    enqueue(q,2);
    enqueue(q,3);
    enqueue(q,4);
    enqueue(q,5);
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));

    enqueue(q,6);
    enqueue(q,7);
    enqueue(q,8);

    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));
    printf("%d\n",dequeue(q));


    free(q);
}