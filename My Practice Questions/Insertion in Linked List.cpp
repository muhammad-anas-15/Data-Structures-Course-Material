#include<iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL; // global pointer, initialize to NULL

// function to create a linked List
void create(int A[], int n) {
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int count(struct Node *p){
	int l=0;
	while(p)
	{
		l++;
		p=p->next;
	}
	return l;
}

int RecursiveCount(struct Node *p){
	if(p!=NULL)
	    return RecursiveCount(p->next)+1;
	
	else
	    return 0;    
}

int sum(struct Node *p)
{
	int s = 0;
	while(p!=NULL){
		s+=p->data;
		p=p->next;
	}
	return s;
}


void Insert(struct Node *p, int index, int x){
	
	struct Node *t;
	
	if(index < 0 || index > count(p))
	       return;
	
	t = new Node;
	t->data = x;
	
	if(index == 0)
	{
		t->next = first;
		first = t;
	}       
	else
	{
		for(int i=0; i<index-1; i++)
		{
			p = p->next;
		}
		t->next = p->next;
		p->next = t;
	}
}
int main() {
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    Insert(first, 0, 9);
    Insert(first, 1,20);
    Insert(first, 2, 30);
    display(first);
    
    return 0;
}
