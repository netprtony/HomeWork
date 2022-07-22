#include <stdio.h>
typedef int ItemType;
struct AVLNode
{       
    ItemType data;
    AVLNode* left;
    AVLNode* right;
};
struct AVLTree
{
    AVLNode* root;
};
AVLNode* creat(ItemType x){
    AVLNode* p = new AVLNode;
    if(!p) {
        printf("Khong du bo nho !");
        return NULL;
    }
    p->data = x;
    p->left = NULL;
    p->right = NULL;
    return p;
}
void initAVLTree(AVLTree &avl){
    avl.root = NULL;
}
void deleteAVLNode(AVLNode* &p){
    p->left = NULL;
    p->right = NULL;
    delete p;
    p = NULL;
}
void RotateLL (AVLNode* &T){
    AVLNode* T1 = T->left;
    T->left = T1->right;
    T1->right = T;
}




