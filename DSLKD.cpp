#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Itemtype;
//tạo node
struct SNode {
	Itemtype val;
	SNode* next;
	SNode* previous;
}; 
//create linked list
struct Slist
{
	SNode* head;
	SNode* tail;
};

//Check list empty
int isEmpty(Slist sl){
	return sl.head == NULL;
}
// insert tail
bool insert_tail(Slist &sl, SNode* p){
	if(!p) return false;
	if(isEmpty(sl)){
		sl.head = sl.tail = p;
	}else {
		if(!sl.tail) return false;
		p->previous = sl.tail;
		sl.tail->next = p;
		sl.tail = p;
	}
	return true;
}
//create node first linked list
SNode* create(Itemtype x){
	SNode* p = new SNode;
	if(!p) return NULL;
	p->val = x;
	p->next = NULL;
	p->previous = NULL;
	return p;
}
void initSlist(Slist& sl) {
    sl.head = sl.tail = NULL;
}
void createSlist(Slist& sl) {
    int n, res;
	Itemtype x;
    do
    {
        printf("Amount : "); scanf_s("%d", &n);
    } while (n <= 0);
    initSlist(sl);
    for (int i = 1; i <= n; i++)
    {
		printf("x = "); scanf("%d", &x);
        SNode* p = create(x);
        res = insert_tail(sl, p);
        if (!res) printf("Can not add student!");
    }
}
bool deleteNode(Slist &sl, SNode* node, Itemtype &x) {
    if(isEmpty(sl)) return false;
	if(node == sl.tail){
		x = node->val;
		sl.tail = node->previous;
		sl.tail->next = NULL;
		delete node;
		return true;
	}else {
		x = node->val;
		node->previous->next = node->next;
		node->next->previous = node->previous;
		if(node == sl.head) sl.head = node->next;
		delete node;
		return true;
	}
}
void oddEvenList(Slist &sl){
	Itemtype x;
	for (SNode* p = sl.tail; p ; p = p->previous)
	{
		if(p->val % 2 == 0){
			if(!deleteNode(sl , p, x)) printf("Node NULL!");
			insert_tail(sl , create(x));
		} 
	}
	while (sl.tail != NULL)
	{
		sl.tail = sl.tail->next;
	}
}
// output linked list
void showLinkedListElement(const Slist sl){
	const SNode* p = sl.head;
	printf("\nNULL <=> ");
	while(p){
		printf("(%d) <=> ", p->val);
		p = p->next;
	}
	printf("NULL\n");
}
void rotateRight(Slist &sl, int k){
	int count = 0;
	for (SNode* p = sl.head; p; p = p->next)
	{
		count++;
	}
	if(k  > count) k %= count;
	if( k == 0 ) {
		showLinkedListElement(sl);
		return;
	}
	SNode* p = sl .tail;
	if(k > 1) {
		if(k <= count/2 ){
			p = sl.tail;
			for (int  i = 1; i < k; i++) p = p->previous;
		} 
		else {
			p = sl.head;
			for (int  i = 1; i < count - k + 1; i++) p = p->next;
		}
	}
	p->previous->next = NULL;// gan tail new next gia tri NULL
		sl.tail->next = sl.head; // gan tail = head
		sl.head->previous = sl.tail; // truoc head la tail
		sl.tail = p->previous; // gan tail truoc p la tail old
		sl.head = p; //cap nhat head gan p
	showLinkedListElement(sl);
}
void swap(int &x, int &y){
	int temp = x;
	x = y;
	y = temp;
}
void reverseBetween(Slist sl, int left, int right){
	int count = 0;
	SNode* l = sl.head; 
	SNode* r = sl.head;
	for (int i = 1; i < left; i++)
	{
		l = l->next;
	}
	for (int i = 1; i < right; i++)
	{
		r = r->next;
	}
	while (r != l)
	{
		swap(r->val, l->val);
		r = r->previous;
		l = l->next;
	}
	showLinkedListElement(sl);
}
int main() {
	Slist sl;
	createSlist(sl);
	oddEvenList(sl);
	showLinkedListElement(sl);
	return 0;
}