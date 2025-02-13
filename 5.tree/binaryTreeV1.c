#include <stdio.h>
#include <stdlib.h>

//배열로 구현한 이진트리
#define MAX_SIZE 15
typedef struct {
    int array[MAX_SIZE];
    int size;
}Tree;

Tree* init() {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->size = 0;
    return tree;
}

void insert(Tree *tree,int value) {
    if (tree->size == MAX_SIZE) {
        printf("트리가 가득 참");
        return;
    }
    tree->array[tree->size++] = value;
}

void preorder(Tree *tree,int index) {//전위순회 V->L->R
    if (index>=MAX_SIZE) {
        return;
    }
    printf("%d ", tree->array[index]);
    preorder(tree, index * 2 + 1);
    preorder(tree, index * 2 + 2);
}

void inorder(Tree *tree,int index) { //중위순회 L->V->R
    if (index>=MAX_SIZE) {
        return;
    }
    inorder(tree, index * 2 + 1);
    printf("%d ", tree->array[index]);
    inorder(tree, index * 2 + 2);
}

void postorder(Tree *tree,int index) { //후위순회 L->R->V
    if (index>=MAX_SIZE) {
        return;
    }
    postorder(tree, index * 2 + 1);
    postorder(tree, index * 2 + 2);
    printf("%d ", tree->array[index]);
}

int main() {
    Tree* tree = init();
    for (int i=1;i<=MAX_SIZE;++i) {
        insert(tree, i);
    }

    preorder(tree, 0);
    printf("\n");

    inorder(tree,0);
    printf("\n");

    postorder(tree,0);

    free(tree);
}