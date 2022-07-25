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
	return s.top == NULL;
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
	printf("\nChuyen doi co so %d sang he %d la: ", n, a);
	while (pop(s, x))
	{
		if (x >= 10){
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
void Stack_GiaiThua(int n){
	Stack s;
	StackNode* p;
	initStack(s);
	int  res = 1, x = n;
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
void WordOfNumber(int x) {
	switch (x)
	{
	case 0:
		printf("Khong "); break;
	case 1:
		printf("Mot "); break;
	case 2:
		printf("Hai "); break;
	case 3:
		printf("Ba "); break;
	case 4:
		printf("Bon "); break;
	case 5:
		printf("Nam "); break;
	case 6:
		printf("Sau "); break;
	case 7:
		printf("Bay "); break;
	case 8:
		printf("Tam "); break;
	case 9:
		printf("Chin "); break;
	}
}
bool isAllZero(Stack s) {
	for (StackNode* p = s.top; p; p = p->link)
	{
		if (p->data != 0) return false;
	}
	return true;
}
void popTwo(Stack& s, int &i, Item& x) {
	for (int j = 1; j <= 2; j++)
	{
		pop(s, x);
		i--;
	}
}
void ReadBill(int n) {
	if (!n) {
		printf("Khong Dong"); return;
	}
	int x = n, count = 0;
	Stack s;
	initStack(s);
	StackNode* p;
	while (x) {
		p = create(x % 10);
		push(s, p);
		count++;
		x /= 10;
	}
	printf("%d tien chu la : ", n);
	x = 1;
	for (int i = count; i >= 1; i--)
	{
		if (i % 3 == 0) {
			if (isAllZero(s)) return;
			switch (i)
			{
			case 3: pop(s, x);
				if (x == 0 && s.top->data == 0 && s.top->link->data == 0) {
					popTwo(s, i, x);
					break;
				}
				WordOfNumber(x);
				printf("Tram ");
				break;
			case 6:pop(s, x);
				if (x == 0 && s.top->data == 0 && s.top->link->data == 0) {
					popTwo(s, i, x);
					break;
				}
				WordOfNumber(x);
				if (s.top->data == 0 && s.top->link->data == 0) {
					printf("Tram Nghin ");
					popTwo(s, i, x);
					break;
				}
				else printf("Tram ");
				break;
			case 9: pop(s, x);
				if (x == 0 && s.top->data == 0 && s.top->link->data == 0) {
					popTwo(s, i, x);
					break;
				}
				WordOfNumber(x);
				if (s.top->data == 0 && s.top->link->data == 0) {
					printf("Tram Trieu ");
					popTwo(s, i, x);
					break;
				} 
				else printf("Tram ");
				break;
			case 12:pop(s, x);
				if (x == 0 && s.top->data == 0 && s.top->link->data == 0) {
					popTwo(s, i, x);
					break;
				}
				WordOfNumber(x);
				if (s.top->data == 0 && s.top->link->data == 0) {
					printf("Tram Ty ");
					popTwo(s, i, x);
					break;
				} 
				else printf("Tram ");
				break;
			}
			continue;
		}
		if ((i + 1) % 3 == 0) {
			if (isAllZero(s)) return;
			switch (i)
			{
			case 2: pop(s, x);
				if (x != 0) {
					if(x == 1) printf("Muoi ");
					else {
					WordOfNumber(x);
					printf("Muoi ");
					} 
				}
				break;
			case 5: pop(s, x);
				if (x != 0) {
					if (x == 1) printf("Muoi ");
					else {
						WordOfNumber(x);
						printf("Muoi ");
					}
				}
				break;
			case 8: pop(s, x);
				if (x != 0) {
					if (x == 1) printf("Muoi ");
					else {
						WordOfNumber(x);
						printf("Muoi ");
					}
				}
				break;
			case 11: pop(s, x);
				if (x != 0) {
					if (x == 1) printf("Muoi ");
					else {
						WordOfNumber(x);
						printf("Muoi ");
					}
				}
				break;
			}
			continue;
		}
		if ((i + 2) % 3 == 0) {
			if (isAllZero(s)) return;
			switch (i)
			{
			case 1: if (x == 0) printf("Le ");
				pop(s, x);
				if (x != 0) WordOfNumber(x);
				break;
			case 4:if (x == 0) printf("Le ");
				pop(s, x);
				if (x != 0) WordOfNumber(x);
				printf("Nghin ");
				break;
			case 7: if (x == 0) printf("Le ");
				pop(s, x);
				if(x !=  0) WordOfNumber(x);
				printf("Trieu ");
				break;
			case 10: if (x == 0) printf("Le ");
				pop(s, x);
				if (x != 0) WordOfNumber(x);
				printf("Ty ");
				break;
			}
			continue;
		}
	}
}
void RomanNumber_units(int x){
	switch (x)
	{
	case 1:
		printf("I");
		break;
	case 2:
		printf("II");
		break;
	case 3:
		printf("III");
		break;
	case 4:
		printf("IV");
		break;
	case 5:
		printf("V");
		break;
	case 6:
		printf("VI");
		break;	
	case 7:
		printf("VII");
		break;
	case 8:
		printf("VIII");
		break;
	case 9:
		printf("IX");
		break;
	}
}
void RomanNumber_dozen(int x){
	switch (x)
	{
	case 1:
		printf("X");
		break;
	case 2:
		printf("XX");
		break;
	case 3:
		printf("XXX");
		break;
	case 4:
		printf("XL");
		break;
	case 5:
		printf("L");
		break;
	case 6:
		printf("LX");
		break;	
	case 7:
		printf("LXX");
		break;
	case 8:
		printf("LXXX");
		break;
	case 9:
		printf("XC");
		break;
	}
}
void RomanNumber_hundreds(int x){
	switch (x)
	{
	case 1:
		printf("C");
		break;
	case 2:
		printf("CC");
		break;
	case 3:
		printf("CCC");
		break;
	case 4:
		printf("CD");
		break;
	case 5:
		printf("D");
		break;
	case 6:
		printf("DC");
		break;	
	case 7:
		printf("DCC");
		break;
	case 8:
		printf("DCCC");
		break;
	case 9:
		printf("CM");
		break;
	}
}
void NumberToRoman(int n ){
	int count = 0;
	int x = n;
	Stack s;
	initStack(s);
	StackNode* p;
	while (x) {
		p = create(x % 10);
		push(s, p);
		count++;
		x /= 10;
	}
	printf("\nRoman Number of %d is : ", n);
	while(pop(s, x)){
		switch (count)
		{
		case 1:
			RomanNumber_units(x);
			break;
		case 2:
			RomanNumber_dozen(x);
			break;
		case 3:
			RomanNumber_hundreds(x);
			break;	
		}
		count--;
	}
}
int main() {
	//Stack_doiCoso(2805, 16);
	//Stack_doiCoso(10, 7);
	int n = 0;
	// do
	// {
	// 	printf("So Tien : "); scanf_s("%d", &n);
	// 	ReadBill(n); 
	// 	printf("Dong\n");
	// } while (n != -1);
	do
	{
			printf("\nSo : "); scanf_s("%d", &n);
			NumberToRoman(n);
	} while (n != -1);
	return 0;
}