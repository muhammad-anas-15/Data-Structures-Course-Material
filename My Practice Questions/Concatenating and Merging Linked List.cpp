#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL; // global pointers, initialized to NULL

// Function to create a linked list
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

void create2(int A[], int n) {
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    
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

void concat(struct Node *p, struct Node *q) {
    third = p;
    
    while (p->next != NULL)
        p = p->next;
    p->next = q;
}

void merge(struct Node *p, struct Node *q) {
    struct Node *last;
    
    if (p->data < q->data) {
        third = last = p;
        p = p->next;
        third->next = NULL;
    } else {
        third = last = q;
        q = q->next;
        third->next = NULL;
    }
    
    while (p && q) {
        if (p->data < q->data) {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        } else {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    
    if (p) last->next = p;
    if (q) last->next = q;
}

int main() {
    int A[] = {3, 5, 7, 10, 15};
    int B[] = {2, 4, 6, 9};
    create(A, 5);
    create2(B, 4);
    
    cout << "First\n";
    display(first);
    cout << "\n\n";
    cout << "Second\n";
    display(second);
    
    // Do not concatenate before merging, this would alter the original lists
    // concat(first, second);
    
    // cout << "\n\nConcatenated first and second\n";
    // display(third);
    
    cout << "\n\nMerging first and second\n";
    merge(first, second);
    display(third);
    
    return 0;
}
