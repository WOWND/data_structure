#include <stdio.h>
#include <stdlib.h>

//노드로 구현한 이진트리
typedef struct TreeNode {
    int value;
    struct TreeNode *right, *left;
}Tree;


Tree *init(int value) {
    Tree *tree = (Tree *) malloc(sizeof(Tree));
    tree->value = value;
    tree->left = NULL;
    tree->right = NULL;
    return tree;
}

void preorder(Tree *tree) {//전위순회 V->L->R
    if (tree == NULL) {
        return;
    }
    printf("%d ", tree->value);
    preorder(tree->left);
    preorder(tree->right);
}

void inorder(Tree *tree) { //중위순회 L->V->R
    if (tree == NULL) {
        return;
    }
    inorder(tree->left);
    printf("%d ", tree->value);
    inorder(tree->right);
}

void postorder(Tree *tree) { //후위순회 L->R->V
    if (tree == NULL) {
        return;
    }
    postorder(tree->left);
    postorder(tree->right);
    printf("%d ", tree->value);
}

int main() {
    Tree *root = init(1);
    Tree *node2 = root->left = init(2);
    Tree *node3 = root->right = init(3);
    Tree *node4 = node2->left = init(4);
    Tree *node5 = node2->right = init(5);
    Tree *node6 = node3->left = init(6);
    Tree *node7 = node3->right = init(7);

    preorder(root);
    printf("\n");

    inorder(root);
    printf("\n");

    postorder(root);

    free(root);
}