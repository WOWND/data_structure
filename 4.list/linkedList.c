#include <stdio.h>
#include <stdlib.h>

typedef int element;

typedef struct { //노드
    struct Node *next; //다음 노드를 가르킴
    element data; //데이터
}Node;


typedef struct { //연결 리스트
    Node *head;
    int size;
}LinkedList;

LinkedList* init() {  //초기화
    LinkedList *list = (LinkedList *) malloc(sizeof(LinkedList));
    list->size = 0;
    list->head = NULL;
    return list;
}

Node* get(LinkedList *list,int index) { //특정 위치 값 얻기
    if (index < 0 || index >=list->size) {
        printf("인덱스 범위 오류\n");
        exit(1);
    }

    Node* now = list->head;
    for (int i=0;i<index;++i) {
        now = now->next;
    }
    return now;
}

void insert_first(LinkedList *list,element data) { //맨 앞에 값 추가
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

void insert_at(LinkedList *list, int index,element data) { //특정 위치에 값 추가
    if (index == 0) {
        insert_first(list,data);
        return;
    }
    if (index < 0 || index >list->size) {
        printf("인덱스 범위 오류\n");
        exit(1);
    }

    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->data = data;

    Node *prev = get(list, index - 1);
    newNode-> next = prev->next;
    prev->next = newNode;

    list->size++;
}

element delete_first(LinkedList *list) { //맨 앞에 값 제거
    element item = list->head->data;
    Node *node = list->head;
    list->head = node->next;
    free(node);
    list->size--;
    return item;
}

element delete_at(LinkedList *list,int index){ //특정 위치에 값 제거
    if (index == 0) {
        return delete_first(list);
    }
    if (index < 0 || index >=list->size) {
        printf("인덱스 범위 오류\n");
        exit(1);
    }
    Node *prevNode = get(list,index - 1);
    Node *delNode = prevNode->next;
    prevNode->next = delNode->next;

    element item = delNode->data;
    free(delNode);
    list->size--;

    return item;
}

void print_list(LinkedList *list) { //출력
    Node *now = list->head;
    while (now != NULL) {
        printf("%d ",now->data);
        now = now->next;
    }
}
int main() {
    LinkedList* list = init();

    insert_first(list,10);
    insert_at(list,0,20);
    insert_at(list,0,30);
    insert_at(list,0,40);

    delete_at(list,0);

    print_list(list);
    free(list);
}