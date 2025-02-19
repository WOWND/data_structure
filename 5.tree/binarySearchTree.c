#include <stdio.h>
#include <stdlib.h>

typedef int element; //노드에 담을 타입
typedef struct Node { //노드
    element value;
    struct Node *left, *right;
}Node;

Node *create_node(element value) { //노드 생성
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node *search(Node *node, element value) { //노드 탐색
    if (node == NULL) return NULL; //값을 찾을 수 없음

    if (node->value > value) //왼쪽 탐색
        return search(node->left,value);
    if (node-> value < value) //오른쪽 탐색
        return search(node->right, value);
    if (node->value == value) //값을 찾음
        return node;
}

Node *search_min(Node *node) { //최솟값 노드 탐색
    if (node->left == NULL) return node; //왼쪽이 비었으면 최솟값
    return search_min(node->left);
}

Node *insert(Node *node, element value) { //노드 삽입
    if (node == NULL) return create_node(value); //빈 노드 발견하면 삽입하기

    if (node->value > value) //왼쪽 탐색
        node->left = insert(node->left,value);
    else if (node-> value < value) //오른쪽 탐색
        node->right = insert(node->right, value);
    return node;
}

Node *delete(Node *node, element value){ //노드 삭제
    if (node == NULL) return NULL; //삭제할 노드를 찾을 수 없음

    if (node->value > value) //왼쪽 탐색
        node->left = delete(node->left,value);
    else if (node->value < value) //오른쪽 탐색
        node->right = delete(node->right, value);
    else { //삭제할 노드 발견
        if (node->left == NULL || node->right == NULL) { //삭제할 노드의 자식이 하나 or 없을 때
            Node *temp = node;
            node = (node->left == NULL ? node->right : node-> left);
            free(temp);
        }else { //자식이 둘일 때
            Node* successor = search_min(node->right); //후계자는 오른쪽 서브트리에서 가장 작은 값
            node->value = successor->value; //후계자 값 복사
            node->right = delete(node->right,successor->value); //후계자 삭제
        }
    }
    return node;
}

void inorder(Node *node) { //중위순회 L->V->R (오름차순으로 순회한다.)
    if (node == NULL) return;
    inorder(node->left);
    printf("[%d] ", node->value);
    inorder(node->right);
}

int main() {
    Node* root = create_node(10);

    root = insert(root,5);
    root = insert(root,15);
    root = insert(root,20);
    root = insert(root,0);
    root = insert(root,40);
    root = insert(root,17);
    root = insert(root,19);
    root = insert(root,13);
    delete(root,15);
    inorder(root);
}
