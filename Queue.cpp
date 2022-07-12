#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

struct phoneNumber
{
	char number[11];
	char message[30];
};
typedef goods ItemType;
struct goods
{
	char code[10];
	char nameTag[20];
	char unit[5];
	int amount;
};

struct QueueNode
{
	ItemType data;
	QueueNode* link;
	QueueNode* prev;
};
struct Queue
{
	QueueNode* Head;
	QueueNode* Tail;
};
QueueNode* createPhoneNumber(ItemType x){
	QueueNode* p = new QueueNode;
	if (!p) return NULL;
	p->data = x;
	p->link = NULL;
	p->prev = NULL;
}
void initQueue(Queue &qu){
	qu.Head = qu.Tail = NULL;
}
bool isEmpty(Queue qu){
	return qu.Head == NULL;
}
bool insert(Queue &qu, QueueNode* p){
	if (!p) return false;
	if (isEmpty(qu)) qu.Head = p;
	else {
		qu.Tail->link = p;
		p->prev = qu.Tail;
	}
	qu.Tail = p;
	return true;
}
bool remove(Queue &qu, ItemType &x){
	if (isEmpty(qu)) return false;
	QueueNode* p = qu.Head;
	qu.Head = p->link;
	if (!qu.Head) qu.Tail = NULL;
	qu.Head->prev = NULL;
	x = p->data;
	delete p;
	return true;
}
bool Head(Queue qu, ItemType &x){
	if (isEmpty(qu)) return false;
	x = qu.Head->data;
	return true;
}
bool Tail(Queue qu, ItemType &x){
	if (isEmpty(qu)) return false;
	x = qu.Tail->data;
	return true;
}
void showNode(QueueNode* p){
	printf("%5d", p->data);
}
QueueNode* createGoodsQueue(goods x){
	QueueNode* p = new QueueNode;
	if (!p) return NULL;
	p->data = x;
	p->link = NULL;
	p->prev = NULL;
}
void creatListGoods(Queue &qu){
	int n;
	bool res;
	do
	{
		printf("N = "); scanf("%d", &n);
	} while (n <= 0);
	for (int i = 1; i <= n; i++)
	{
		goods x;
		printf("PLU: "); gets(x.code);
		printf("Product name:"); gets(x.nameTag);
		printf("Unit:"); gets(x.unit);
		printf("Amount : "); scanf("%d", &x.amount);
		QueueNode* p = createGoodsQueue(x)
		res = insert(qu, p);
		//showNode(p);
		if (!res) printf("Can't add node!");
	}
}
void showQueue(Queue qu){
	if (isEmpty(qu)){
		printf("Queue nothing!");
		return;
	}
	printf("Your Queue: ");
	for (QueueNode* p = qu.Head; p  != NULL; p = p->link )
	{
		showNode(p);
	}
}
void removeAll(Queue &qu){
	if (isEmpty(qu)){
		printf("Queue Empty!");
		return;
	}
	ItemType x;
	while (qu.Head)
	{
		remove(qu, x);
		printf("Deleted %d", x);
	}
}
// bool IsKNode(Queue qu, int k){
// 	if (isEmpty(qu)) return false;
// 	int count = 0;
// 	for (QueueNode* p = qu.Head; p!= NULL ; p= p->link)
// 	{
// 		count++;
// 	}
// 	return count == k ? true : false;
// }
// bool isSame(Queue qu, ItemType x){
// 	for (QueueNode* p = qu.Head; p ; p = p->link)
// 	{
// 		if (strcmp(p->data.number, p->data.number)==0) return true;
// 	}
// 	return false;
// }
// void showMessage(Queue qu, int k){
// 	ItemType bin;
// 	do
// 	{

// 		ItemType subject;
// 		printf("\nNumber : "); gets(subject.number);
// 		printf("Message : "); gets(subject.message);
// 		if (!isSame(qu, subject)){
// 			if (IsKNode(qu, k)) remove(qu, bin);
// 			QueueNode* p = createPhoneNumber(subject);
// 			insert(qu, p);
// 		}
// 		for (QueueNode*  p = qu.Head; p != NULL ; p = p->prev)
// 		{
// 			puts(p->data.number); puts(p->data.message); 
// 		}
// 	} while (1);
// }

int main(){
	Queue qu;
	initQueue(qu);
	/*creatQueueAuto(qu);
	showQueue(qu);*/
	//showMessage(qu, 3);
	return 0;
}