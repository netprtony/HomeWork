#include <stdio.h>
#include <string.h>
typedef char Item;
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
bool push(Stack &s, StackNode* p){
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
char top(Stack s){
	if (isEmpty(s)) return NULL;
	return s.top->data;
}
void showNode(Stack s){
	if (isEmpty(s)) return;
	for (StackNode* p = s.top; p; p = p->link)
	{
		printf("%c", p->data);
	}
}
bool checkDauNgoac(char s[]){
	if (!s) return false;
	Item x;
	Stack st;
	StackNode*p;
	initStack(st);
	int i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '{' || s[i] == '[' || s[i] == '('){
			p = create(s[i]);
			push(st, p);
		}
		else {
			if (!pop(st, x)) return false;
			if (s[i] == '{' && x != '}') return false;
			else if (s[i] == '(' && x != ')') return false;
			else if (s[i] == '[' && x != ']') return false;
		}
		i++;
	}
	return true;
}
void DaoChuoi(char str[]){
	Stack s;
	initStack(s);
	Item x;
	int i = 0;
	while (str[i] != '\0'){
		StackNode* p = create(str[i]);
		push(s, p);
		i++;
	}
	while (pop(s, x))
	{
		printf("%c", x);
	}
}
int priority(char s){
	if(s == '(') return 0;
	if(s == '+' || s == '-') return 1;
	if(s == '*' || s =='/' || s == '%') return 2;
	if(s == '^') return 3;
	return -1;
}
void InfixToPostfix(char s[]){
	if(!s) return;
	int i = 0;
	Item x;
	Stack st;
	while (s[i] != '\0')
	{
		if(s[i] == '(') {
			StackNode* p = create(s[i]);
			push(st, p);
		}
		if(s[i] >= 'a' && s[i] <= 'z' ) {
			printf("%s", s[i]);
		}
		if (s[i] == ')')
		{
			while (pop(st, x))
			{		
				if(x =='(') break;
				else printf("%c", x);
			}
		}
		if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '%' || s[i] == '^') {
			if(isEmpty(st)) {
				StackNode* p = create(s[i]);
				push(st, p);
			}else {
				if(priority(s[i]) <= priority(top(st))) {
					pop(st, x);
					printf("%c", x);
				}
			}
		}
		i++;
	}
}
int main(){
	char s[] = "3*4+(2+5)/2)";
	InfixToPostfix(s);
	return 0;
}
