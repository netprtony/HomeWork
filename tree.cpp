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
    int l = countTNodeHaveTwoChild(root->left);
    int r = countTNodeHaveTwoChild(root->right);
    return (root->left && root->right) ? 1+r+l : l+r; 
}
int countTNodeHaveOneChild(TNode* root){
    if(!root) return 0;
    int l = countTNodeHaveTwoChild(root->left);
    int r = countTNodeHaveTwoChild(root->right);
    return ((root->left && !root->right)||(!root->left && root->right)) ? 1+r+l : l+r;   
}
int countTNodeHaveChildIsLeaf(TNode* root){
    if(!root) return 0;
    int l = countTNodeHaveChildIsLeaf(root->left);
    int r = countTNodeHaveChildIsLeaf(root->right);
    return (isLeaf(root->left)||isLeaf(root->right)) ? 1+l+r : l+r;
}
int sumTNode(TNode* root){
    return root ? root->data + sumTNode(root->left) + sumTNode(root->right) : 0;
}
int highTree(TNode* root){
    if(!root) return 0;
    int hl = highTree(root->left);
    int hr = highTree(root->right);
    return hl > hr ? hl+1 : 1+hr;
}
int countTNodeIsNoLeaf(TNode* root){
    return countTNode(root) - countNodeLeaf(root);
}
int countTNodeMedium(TNode* root){
    int n = countTNodeIsNoLeaf(root);
    return (n != 0) ? n-1 : 0;
}
int TNodeMax(TNode* root){
    TNode* p;
    for (p = root; p->right; p = p->right);
    return p->data;
}
void showTNodeOfLevelK(TNode* root, int k){
    if(!root) return;
    if(k==0) printf("%5d", root->data);
    k--;
    showTNodeOfLevelK(root->left, k); 
    showTNodeOfLevelK(root->right, k);
}
void showTNodeIsLeafOfLevelK(TNode* root, int k){
    if(!root) return;
    if(k==0 && !root->left && !root->right) printf("%5d",root->data);
    k--;
    showTNodeIsLeafOfLevelK(root->left, k);
    showTNodeIsLeafOfLevelK(root->right, k);
}
int countTNodeOfLevelK(TNode* root, int k){
    if(!root) return 0;
    if(k==0) return 1;
    k--;
    return countTNodeOfLevelK(root->left, k) + countTNodeOfLevelK(root->right, k);
}
int countTNodeIsLeafOfLevelK(TNode* root, int k){
    if(!root) return 0;
    if(k==0 && !root->left && !root->right) return 1;
    k--;
    return countTNodeIsLeafOfLevelK(root->left, k) +  countTNodeIsLeafOfLevelK(root->right, k);
}
int sumTNodeOfLevelK(TNode* root, int k){
    if(!root) return 0;
    if(k==0) return root->data;
    k--;
    return sumTNodeOfLevelK(root->left, k) + sumTNodeOfLevelK(root->right, k);
}
int sumTNodeIsLeafOfLevelK(TNode* root, int k){
    if(!root) return 0;
    if(k==0 && !root->left && !root->right) return root->data;
    k--;
    return sumTNodeIsLeafOfLevelK(root->left, k) + sumTNodeIsLeafOfLevelK(root->right, k);
}
bool isSameTree(TNode* p, TNode* q){
    if(p->data != q->data) return false;
        isSameTree(p->left, q->left);
        isSameTree(p->right, q->right);
    return true;
}
void menu(){
    printf("\n****************MENU************************");
    printf("\n* 1_Create Tree form array.                *");
    printf("\n* 2_Create Tree random.                    *");
    printf("\n* 3_Create Tree hand make.                 *");
    printf("\n* 4_Show LRN.                              *");
    printf("\n* 5_Find node any.                         *");
    printf("\n* 6_Count leaf.                            *");
    printf("\n* 7_Count node.                            *");
    printf("\n* 8_Count node have two child.             *");
    printf("\n* 9_Sum all node of tree.                  *");
    printf("\n* 10_Height of tree.                       *");
    printf("\n* 11_Count node have one child.            *");
    printf("\n* 12_Count node have child is leaf.        *");
    printf("\n* 13_Count node isn't leaf.                *");
    printf("\n* 14_Count node is medium.                 *");
    printf("\n* 15_Node max.                             *");
    printf("\n* 16_Show node of level k.                 *");
    printf("\n* 17_Show node is leaf of level k.         *");
    printf("\n* 18_Count node of level k.                *");
    printf("\n* 19_Count node is leaf of level k.        *");
    printf("\n* 20_Sum node of level k.                  *");
    printf("\n* 21_Sum node is leaf of level k.          *");
    printf("\n* 21_Check is same tree.                   *");
    printf("\n* 0_Exit.                                  *");
    printf("\n*******************************************");
}
void process(){
    int selectFunction;
    Btree bt, bt1;
    TNode* p;
    ItemType x;
    ItemType a[] = {10, 2, 5, 4, 65, 6, 3, 25, 7, 36, 12};
    int n = 11, k;
    initBtree(bt);
    initBtree(bt1);
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
                else printf("Node %d is not in tree", x);
                break; 
        case 6: printf("\nAmount leaf of tree: %d",countNodeLeaf(bt.Root));
                break;
        case 7:printf("\nAmount node of tree: %d",countTNode(bt.Root));
                break;
        case 8:printf("\nAmount node have two child of tree: %d",countTNodeHaveTwoChild(bt.Root));
                break;  
        case 9:printf("\nSum all node of tree: %d",sumTNode(bt.Root));
                break; 
        case 10 :printf("\nHigh of tree : %d",highTree(bt.Root));
                break; 
        case 11:printf("\nAmount node have one child of tree: %d",countTNodeHaveOneChild(bt.Root));                
                break; 
        case 12:printf("\nAmount node have child is leaf of tree: %d",countTNodeHaveChildIsLeaf(bt.Root));                
                break;
        case 13:printf("\nAmount node isn't leaf of tree: %d",countTNodeIsNoLeaf(bt.Root));                
                break;
        case 14:printf("\nAmount node is medium of tree: %d",countTNodeMedium(bt.Root));                
                break;
        case 15:printf("\nNode max of tree: %d",TNodeMax(bt.Root));                
                break;
        case 16: printf("\nK = "); scanf("%d", &k); printf("\nNode of at level %d\n", k); showTNodeOfLevelK(bt.Root, k);
                break;
        case 17: printf("\nK = "); scanf("%d", &k); printf("\nNode is leaf of at level %d\n", k); showTNodeIsLeafOfLevelK(bt.Root, k);
                break;
        case 18: printf("\nK = "); scanf("%d", &k); printf("%d node at level %d",countTNodeOfLevelK(bt.Root, k), k);
                break;
        case 19: printf("\nK = "); scanf("%d", &k); printf("%d node is leaf at level %d",countTNodeIsLeafOfLevelK(bt.Root, k), k);
                break;
        case 20: printf("\nK = "); scanf("%d", &k); printf("%d sum node at level %d",sumTNodeOfLevelK(bt.Root, k), k);
                break;
        case 21: printf("\nK = "); scanf("%d", &k); printf("%d sum node is leaf at level %d",sumTNodeIsLeafOfLevelK(bt.Root, k), k);
                break;
        case 22 : createHandMake(bt, n);  createHandMake(bt1, n);  isSameTree(bt.Root, bt1.Root);
                break;
        }
        printf("\n--------------------------------");
    } while (selectFunction );
    
}
int main(){
    process();
    return 0;
}
