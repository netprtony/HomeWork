#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int ItemType;
struct TNode
{
    ItemType data;
    TNode* right;
    TNode* left;
};
struct Btree
{
    TNode* Root;
};
TNode* Create(ItemType x){
    TNode* p = new TNode;
    if(!p) return NULL;
    p->data = x;
    p->right = p->left = NULL;
    return p;
}
void showTNode(TNode *p){
    printf("%4d", p->data);
}
void deleteTNode(TNode *&p){
    if(!p) return;
    p->left = p->right =NULL;
    delete p;
    p == NULL;
}
void initBtree(Btree &bt){
    bt.Root =NULL;
}
bool insertLeft(TNode* &t, TNode* p){
    if(!p||!t) return false;
    if(t->left) return false;
    t->left = p;
    return true;
}
bool insertRight(TNode* &t, TNode* p){
    if(!p||!t) return false;
    if(t->right) return false;
    t->right = p;
    return true;
}
bool insert(TNode* &root, TNode* p){
    if(!p) return false;
    if(!root){
        root = p;
        return true;
    }
    if(root->data == p->data) return false;
    if(p->data < root->data) insert(root->left, p);
    else insert(root->right, p);
    return true;
}
void createArray(Btree &bt, ItemType *a, int n){
    initBtree(bt);
    for (int i = 0; i < n; i++)
    {
        TNode* p = Create(a[i]) ;
        insert(bt.Root, p);
    }
}
void createHandMake(Btree &bt, int n){
    initBtree(bt);
    ItemType x; 
    printf("How many tree do you want : ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("new X : "); scanf("%d", &x);
        TNode* p = Create(x);
        insert(bt.Root, p);
    }
}
void createAuto(Btree &bt){
    int n;
     ItemType x;
    printf("How many tree do you want : ");
    scanf("%d", &n);
    initBtree(bt);
   srand((unsigned)time(NULL));
   for (int i = 1; i <= n; i++)
   {
        x= (rand()%199) - 99;
        TNode* p = Create(x);
        insert(bt.Root, p);
   }
}
void NLR(TNode* root){
    if(!root) return;
    printf("%4d", root->data);
    NLR(root->left);
    NLR(root->right);
}
void NRL(TNode* root){
    if(!root) return;
    printf("%4d", root->data);
    NLR(root->right);
    NLR(root->left);
}
void LNR(TNode* root){
    if(!root) return;
    NLR(root->left);
    printf("%4d", root->data);
    NLR(root->right);
}
void LRN(TNode* root){
    if(!root) return;
    NLR(root->left);
    NLR(root->right);
    printf("%4d", root->data);
}
void RNL(TNode* root){
    if(!root) return;
    NLR(root->right);
    printf("%4d", root->data);
    NLR(root->left);
}
void RLN(TNode* root){
    if(!root) return;
    NLR(root->right);
    NLR(root->left);
    printf("%4d", root->data);
}
TNode* FindTNode (TNode* root, ItemType x){
    if(!root) return NULL;
    if(root->data == x) return root;
    else if(root->data > x) FindTNode(root->left, x);
        else FindTNode(root->right, x); 
    return NULL;
} 
TNode* FindTNode2(TNode* root, ItemType x){
    TNode* p = root;
    while (p)
    {
        if(p->data == x) return p;
        else if(p->data > x) p = p->left;
        else p= p->right;
    }
    return NULL;
}
bool isLeaf(TNode* t){
    if(!t) return false; 
    if(t->left || t->right) return false;//là lá khi và chỉ khi không có nhánh con chỉ có nhánh cha.
    return true;
}
int countNodeLeaf(TNode* root){
    if(!root) return 0;
    if(!root->left && !root->right) return 1;
    return countNodeLeaf(root->left) + countNodeLeaf(root->right);
}
bool deleteTNodeLeft(TNode* t, ItemType &x){
    if(!t) return false; //Điều kiện xóa khi và chỉ nút trái của cây là lá.
    TNode* p = t->left; 
    if(!p) return false;
    if(p->left || p->right) return false; //kiểm tra có phải lá không.
    t->left = NULL; //ngắn kết nối giữ rễ và nhánh con cần xóa
    x = p->data;// lưu giá trị
    delete p;
    return true;
}
bool deleteTNodeRight(TNode* t, ItemType &x){
    if(!t) return false; //Điều kiện xóa khi và chỉ nút phải của cây là lá.
    TNode* p = t->right; 
    if(!p) return false;
    if(p->left || p->right) return false; //kiểm tra có phải lá không.
    t->right = NULL; //ngắn kết nối giữ rễ và nhánh con cần xóa
    x = p->data;// lưu giá trị
    delete p;
    return true;
}
int countTNode(TNode* root){
    if(!root) return 0;
    return 1 + countTNode(root->right)+ countTNode(root->left);
}
int countTNodeHaveTwoChild(TNode* root){
    if(!root) return 0;
    if(!root->left || !root->right) return 0;
    return countTNodeHaveTwoChild(root->left) + countTNodeHaveTwoChild(root->right) + 1;
}
int sumTNode(TNode* root){
    if(!root) return 0;
    return root->data + sumTNode(root->left) + sumTNode(root->right);
}
int highTree(TNode* root){
    if(!root) return 0;
    int hl = highTree(root->left);
    int hr = highTree(root->right);
    if(hl > hr) return hl + 1;
    else return hr + 1; 
}
void menu(){
    printf("\n****************MENU***********************");
    printf("\n*1.Create Tree form array.                *");
    printf("\n*2.Create Tree random.                    *");
    printf("\n*3.Create Tree hand make.                 *");
    printf("\n*4.Show LRN.                              *");
    printf("\n*5.Find node any.                         *");
    printf("\n*6.Count leaf.                            *");
    printf("\n*7.Count node.                            *");
    printf("\n*8.Count node have two child.             *");
    printf("\n*9.Sum all node of tree.                  *");
    printf("\n*10.Height of tree.                       *");
    printf("\n*0.Exit.                                  *");
    printf("\n*******************************************");
}
void process(){
    int selectFunction;
    Btree bt;
    TNode* p;
    ItemType x;
    ItemType a[] = {10, 2, 5, 4, 65, 6, 3, 25, 7, 36, 12};
    int n = 11;
    initBtree(bt);
    do
    {
        menu();
        printf("\nSelection : "); scanf("%d", &selectFunction);
        printf("\n----------RESULT---------------\n");
        switch (selectFunction)
        {
        case 1 :    createArray(bt, a, n);  
                    break;    
        case 2 :    createAuto(bt);  
                    break;
        case 3 :    createHandMake(bt, n);  
                    break;           
        case 4 : LRN(bt.Root);
                break;
        case 5 : printf("X = "); scanf("%d", &x);
                if(FindTNode2(bt.Root, x)!= NULL) printf("Node %d in tree.", x);
                else printf("Node %d is not in tree");
                break; 
        case 6: printf("Amount leaf of tree: %d",countNodeLeaf(bt.Root));
                break;
        case 7:printf("Amount node of tree: %d",countTNode(bt.Root));
                break;
        case 8:printf("Amount node have two child of tree: %d",countTNodeHaveTwoChild(bt.Root));
                break;  
        case 9:printf("Sum all node of tree: %d",sumTNode(bt.Root));
                break; 
        case 10 :printf("High of tree : %d",highTree(bt.Root));
                break; 
        }
        printf("\n--------------------------------");
    } while (selectFunction );
    
}
int main(){
    process();
    return 0;
}