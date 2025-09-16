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
    if(p!=NULL){
    	cout<<p->data<<" ";
    	display(p->next);
	}
    
}

struct Node* LSearch(struct Node *p, int key)
{
	struct Node *q;
	
	while(p!=NULL){
		if(key ==p->data)
		{
			//3 steps to move key node to the first of list
			q->next = p->next;
			p->next = first;
			first = p;
			
		   return p;	
		}
		q = p;
		p = p->next;
	}
	return NULL;
}

int main() {
	struct Node *temp;
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    display(first);
    
    temp = LSearch(first, 10);
    
    if(temp)
       cout<<"\nkey is found "<<temp->data;
    
	else   
        cout<<"\nkey is not found";
    
    cout<<"\n";
	display(first);  
	  
    return 0;
}
