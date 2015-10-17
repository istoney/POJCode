#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

struct Node{
	Node *lChild;
	Node *rChild;
	int pValue;
	int value;
}Tree[100];

int loc;

Node *creat(){
	Tree[loc].lChild = NULL;
	Tree[loc].rChild = NULL;
	return &Tree[loc++];
}

Node *insert(Node *T,int x){
	if (T == NULL){
		T = creat();
		T->value = x;
		return T;
	}
	else if (T->value > x)
		T->lChild = insert(T->lChild,x);
	else if (T->value < x)
		T->rChild = insert(T->rChild,x);
	return T;
}

void find(Node *T,int x)
{
	Node *p;
	p = T;
	p->pValue = -1;
	while (p->value != x){
		p->pValue = p->value;
		printf("%d\n",p->pValue);
		if (x > p->value){
		//	p->pValue = p->value;
			p = p->rChild;
		}
		else if (x < p->value){
		//	p->pValue = p->value;
			p = p->lChild;
		}
	}
	printf("%d\n",p->pValue);
}


int main()
{
	int num;
	while (scanf("%d",&num) != EOF){
		loc = 0;
		Node *T = NULL;
		int i;
		for (i = 0;i < num;i ++){
			int x;
			scanf("%d",&x);
			T = insert(T,x);
		}
		for (i = 0;i < num;i ++){
			find(T,Tree[i].value);
		}
	}

	return 0;
}