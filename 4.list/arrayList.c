#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
typedef int element;
typedef struct {
    element array[MAX_SIZE];
    int size;
}ArrayList;

ArrayList* init() {
    ArrayList *list = (ArrayList *) malloc(sizeof(ArrayList));
    list->size = 0;
    return list;
}

element get(ArrayList *list, int index) {
    if (index <0 || index>=MAX_SIZE) {
        printf("범위 초과");
        exit(1);
    }
    return list->array[index];
}

void insert(ArrayList *list, int index, int newValue) { //지정 인덱스에 추가
    if (index < 0 || index >= MAX_SIZE) {
        printf("인덱스 범위 초과");
        exit(1);
    }
    if (list->size == MAX_SIZE) {
        printf("포화 오류 발생");
        exit(1);
    }


    //배열 뒤로 밀고 난 뒤에 값 넣기
    for (int i = list->size; i > index; --i) {
        list->array[i] = list->array[i - 1];
    }

    list->size++;
    list->array[index] = newValue; //값 삽입
}

void add(ArrayList *list,int newValue) { //맨 뒤에 추가
    if (list->size ==MAX_SIZE) {
        printf("포화 오류 발생");
        exit(1);
    }
    list->array[list->size++] = newValue;
}

element delete(ArrayList *list){ //맨 뒤에 삭제
    if (list->size == 0) {
        printf("공백 오류 발생");
        exit(1);
    }
    return list->array[--list->size];
}

element delete_index(ArrayList *list,int index){ //지정 인덱스 삭제
    if (list->size == 0) {
        printf("공백 오류 발생");
        exit(1);
    }

    element item = list->array[index];

    //배열 앞으로 당기기
    for (int i = index; i < list->size; ++i) {
        list->array[i] = list->array[i + 1]; //뒤에 애를 앞으로 가져오기
    }
    list->size--;

    return item;
}

void clear(ArrayList* list) { //초기화
    list->size =0;
}


int main() {
    ArrayList *list = init();

    add(list,10);
    insert(list, 0, 9);

    free(list);

}