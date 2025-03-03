#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 100

char stack[MAX];
char infix[MAX];
char postfix[MAX];
int top = -1;


void push(char);
char pop();
int isEmpty();
void inToPost();
int space(char);
void print();
int precedence(char);


int main(){
	
	printf("Masukkan infixnya = ");
	scanf("%s",&infix);
	getchar();
	
	inToPost();
	print();
	
	return 0;
}


void inToPost(){
	
	char symbol;
	char next;
	int j=0;
	int i=0;
	
	
	for(i=0;i<strlen(infix);i++){
		symbol = infix[i];

			switch(symbol){
		
			case '(':
				push(symbol);
				break;
			
		case ')':
			while((next=pop())!='('){
				postfix[j++]=next;
			}
			break;
			
		case'+':
		case'-':
		case'*':
		case'/':			
		case'^':
			while(!isEmpty() && precedence(stack[top])>=precedence(symbol)){
				postfix[j++] = pop();
			}
			push(symbol);
			break;
		
		default:
			postfix[j++]=symbol;
		
			
		}
	}
	while(!isEmpty()){
		postfix[j++] = pop();
	}
	postfix[j]='\0';
}



int precedence(char symbol)
	{
		switch(symbol)
		{
			case'^':
				return 3;
			case'/':
			case'*':
				return 2;
			case'+':
			case'-':
				return 1;
			default:
				return 0;
		}
	}
	
	

void print(){
	int i=0;
	printf("hasil postfix: ");
	while(postfix[i]){
		printf("%c", postfix[i++]);
	}
	printf("\n");
}

void push(char c) {
    if (top == MAX - 1) {
        printf("Stack Penuh\n");
        return;
    }
    stack[++top] = c;
}

char pop() {
    if (isEmpty()) {
        printf("Stack Kosong\n");
        return -1;
    }
    return stack[top--];
}

int isEmpty() {
    return top == -1;
}

