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

int count(struct Node *p){
	int l=0;
	while(p)
	{
		l++;
		p=p->next;
	}
	return l;
}

void display(struct Node *p) {
    while (p != NULL) {
        cout << p->data << " ";
        p = p->next;
    }
}

int Delete(struct Node *p, int index)
{
	struct Node *q;
	int x =-1;
	
	if(index <1 || index > count(p))
		return -1;
	
	if(index == 1)
	{
		q = first;
		x = first->data;
		first= first->next;
		delete p;
		
		return x;
	}
	
	else
	{
		for(int i=0; i< index-1; i++){
			q = p;
			p= p->next;
		}
		q->next = p->next;
		x = p->data;
		delete p;
		return x;
	}
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    
    Delete(first, 3);
    //display(first);
    
    Delete(first, 1);
    display(first);
    return 0;
}
