#include <stdio.h>
typedef int Item;
struct StackNode
{
	Item data;
	StackNode* link;
};
struct Stack
{
	StackNode* top;
};
StackNode* create(Item x){
	StackNode* p = new StackNode;
	if (!p) return NULL;
	p->data = x;
	p->link = NULL;
	return p;
}
void initStack(Stack &s){
	s.top = NULL;
}
bool isEmpty(Stack s){
	return s.top == NULL ? true : false;
}
bool push(Stack &s,	StackNode* p){
	if (!p) return false;
	if (isEmpty(s)){
		s.top = p;
	}
	else {
		p->link = s.top;
		s.top = p;
	}
	return true;
}
bool pop(Stack &s, Item &x){
	if (isEmpty(s)) return false;
	StackNode* p = s.top;
	s.top = s.top->link;
	x = p->data;
	delete p;
	return true;
}
bool top(Stack s, Item &x){
	if (isEmpty(s)) return false;
	x = s.top->data;
	return true;
}
void showNode(Stack s){
	if (isEmpty(s)) return;
	for (StackNode* p = s.top; p ; p = p->link)
	{
		printf("%5d", p->data);
	}
}
void Stack_doiCoso(int n, int a){
	int sodu, x, tmp = n;
	StackNode* p;
	Stack s;
	initStack(s);
	while (tmp != 0){
		sodu = tmp % a;
		tmp /= a;
		p = create(sodu);
		push(s, p);
	}
	//printf("\nChuyen doi co so %d sang he %d la: ", n, a);
	while (pop(s, x))
	{
		if (n >= 10 && a > 2){
			switch (x)
			{
			case 10: printf("A"); break;
			case 11: printf("B"); break;
			case 12: printf("C"); break;
			case 13: printf("D"); break;
			case 14: printf("E"); break;
			case 15: printf("F"); break;
			}
		} else printf("%d", x);
	}
}
void Stack_GiaiThua( int n){
	Stack s;
	StackNode* p;
	initStack(s);
	int  res = 1, x  = n;
	while (x > 0)
	{
		p = create(x);
		push(s, p);
		x--;
	}
	while (pop(s, x))
	{
		res *= x;
	}
	printf("%d! = %d ", n, res);
}

int main(){
	//Stack_doiCoso(2805, 16);
	Stack_doiCoso(25, 8);
	return 0;
}