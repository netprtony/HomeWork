#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef int Itemtype;
//tạo node
struct SNode {
	Itemtype data;
	struct SNode* next;
}; 
//create linked list
typedef struct SNode* LinkedList;
//Check list empty
int isEmpty(LinkedList list){
	return list == NULL;
}
//insert node first linked list
void addNewSNode (LinkedList* head, Itemtype data){
	struct SNode*p = (struct SNode*)malloc(sizeof(struct SNode));
	p->data = data;
	p->next =NULL;
	if(isEmpty(*head)){
		*head = p;
	}else{
		p->next = *head;
		*head = p;
	}
}
//add element at the end linked list
void addNewEndLinkedList (LinkedList *head){
	
}
// output linked list
void showLinkedListElement(const LinkedList head){
	const struct SNode* p = head;
	while(p){
		printf("%5d => ", p->data);
		p = p->next;
	}
	printf("NULL\n");
}
int main() {
	LinkedList singlyLinkedList = NULL;
	int n;
	puts("n =  ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		Itemtype data;
		scanf("%d", &data);
		addNewSNode(&singlyLinkedList, data);
	}
	// output right here
	showLinkedListElement(singlyLinkedList);
	return 0;
}