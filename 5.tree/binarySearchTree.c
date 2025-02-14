#include <stdio.h>
#include <stdlib.h>

//이진탐색트리

typedef struct BST {
    int value;
    struct BST *left, *right;
}BST;

BST* newNode(int value) {
    BST *node = (BST *) malloc(sizeof(BST));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

BST* search(BST* node, int value) {
    if (node == NULL) return NULL;
    if (node->value == value) { //발견
        return node;
    }else if (node->value > value) { //왼쪽 탐색
        return search(node->left,value);
    }else { //오른쪽 탐색
        return search(node->right,value);
    }
}

BST *insert(BST *node, int value) {
    if (node == NULL) { //비었으면 넣어주기
        return newNode(value);
    }

    if (node->value > value) {
        //왼쪽으로 내려가기
        node->left = insert(node->left,value);
    }else if (node->value < value) {
        //오른쪽으로 내려가기
        node->right = insert(node->right,value);
    }

    return node;
}

BST* search_min(BST* node) {
    if (node->left == NULL) return node;
    return search_min(node->left);
}

BST* delete(BST* node,int value){
    if (node == NULL) return NULL;

    if (node->value > value) { //왼쪽 탐색
        node-> left = delete(node->left,value);
    } else if ( node->value < value) { //오른쪽 탐색
        node -> right = delete(node->right, value);
    } else { //발견
        //1. 말단 노드 (자식이 없는 경우)
        //2. 자식이 하나인 경우
        if (node->left == NULL) {
            BST* temp = node->right;
            free(node);
            return temp;
        }
        if (node->right == NULL) {
            BST* temp = node->left;
            free(node);
            return temp;
        }

        //3. 자식이 둘인 경우
        //후계자를 찾아서 나와 바꿈 (후계자: 오른쪽 노드에서 가장 작은 값)
        int temp = search_min(node->right)->value;
        node->value = temp;
        delete(node->right,temp);
    }
    return node;
}

void inorder(BST* node) { //중위순회 L->V->R
    if (node == NULL) {
        return;
    }
    inorder(node->left);
    printf("[%d] ", node->value);
    inorder(node->right);
}

int main(){
    BST* root = NULL;

    // 삽입
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("중위 순회 (삽입 후): ");
    inorder(root); // 삽입 후 중위순회
    printf("\n");

    // 삭제
    root = delete(root, 20); // 20 삭제
    root = delete(root, 30); // 30 삭제
    root = delete(root, 50); // 50 삭제

    printf("중위 순회 (삭제 후): ");
    inorder(root); // 삭제 후 중위순회
    printf("\n");
}
