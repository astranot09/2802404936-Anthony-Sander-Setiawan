#include<stdio.h>
#include<stdlib.h>

struct Node{
	int angka;
		
	Node *prev;
	Node *next;
}*head,*tail;

Node *createNode(int angka){
	Node *newNode= (Node*)malloc(sizeof(Node));
	
	newNode->angka = angka;
	newNode->next = NULL;
	newNode->prev = NULL;
	
	return newNode;
}

void pushHead(int angka){
	Node *temp = createNode(angka);
	
	if(!head){
		head=tail=temp;
	}
	else{
		temp->next= head;
		head->prev=temp;
		head=temp;
		
	}
}
void pushTail(int angka){
	Node *temp = createNode(angka);
	
	if(!head){
		head=tail=temp;
	}
	else{
		tail->next=temp;
		temp->prev=tail;
		tail=temp;
		
	}
}
void pushMid(int angka){
	Node *temp = createNode(angka);
	
	if(!head){
		head=tail=temp;
	}
	else if(angka<head -> angka){
		pushHead(angka);
	}
	else if(angka>tail -> angka){
		pushTail(angka);
	}
	else{
		Node *curr = head->next;
		while(angka>curr->angka){
			curr=curr->next;
		}
		Node *data = curr->prev;
		data->next=temp;
		curr->prev=temp;
		temp->next=curr;
		temp->prev=data;
		
	}
}

void popHead(){
	if(!head){
		return;
	}
	else if(head==tail){
		free(head);
		head = tail = NULL;
	}
	else{
		Node *temp = head->next;
		head->next = NULL;
		temp->prev = NULL;
		free(head);
		head=temp;
		
	}
}
void popTail(){
	if(!head){
		return;
	}
	else if(head==tail){
		free(head);
		head = tail = NULL;
	}
	else{
		Node *temp = tail->prev;
		temp->next = NULL;
		tail->prev = NULL;
		free(tail);
		tail=temp;
		
	}
}

void popMid(int angka){
	if(!head){
		return;
	}
	else if(angka==head->angka){
		popHead();
	}
	else if(angka==tail->angka){
		popTail();
	}
	else{
		Node *curr = head->next;
		while(curr->angka!=angka){
			curr=curr->next;
		}
		Node *depan = curr->prev;
		Node *belakang = curr->next;
		curr->prev = NULL;
		curr->next = NULL;
		free(curr);
		depan->next=belakang;
		belakang->prev=depan;
	}
	
}

void printList(){
	if (head==NULL)
	{
		printf("No Data\n");
		return;
	}
	
	struct Node *curr = head;
	
	while(curr!=NULL)
	{
		printf("%d ", curr->angka);
		curr = curr->next;
	}
}


int main(){
//	pushHead(5);
//	pushHead(7);
//	pushTail(2);

	pushMid(6);
	pushMid(3);
	pushMid(9);
	
//	popHead();
//	popTail();
	popMid(6);
	

	printList();
	
	return 0;
}
