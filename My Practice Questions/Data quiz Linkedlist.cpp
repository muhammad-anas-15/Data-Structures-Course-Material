#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node *nextnode;
        
        Node(int val) {
            data = val;
            nextnode = NULL;
        }
};

class LinkedList {
    private:
        Node *head, *current;
        int List_Size;
    
    public:
        LinkedList() {
            head = current = NULL;
            List_Size = 0;
        }	
        
        // Add a node at the end of the list
        void Add_End(int val) {
            Node *newnode = new Node(val);
            if(head == NULL || List_Size == 0) {
                head = current = newnode;
                List_Size++;
            } else {
                current->nextnode = newnode;
                current = newnode;
                List_Size++;
            }
        }
        
        // Print the linked list
        void Print() {
            current = head;
            while(current != NULL) {
                cout << current->data << " ";
                current = current->nextnode;
            }
            cout << endl;
        }

        // Reverse a group of nodes
        Node* Reverse(Node* head, int k) 
		{
            Node *prev = NULL, *current = head, *next = NULL;
            
            int count = 0;
            
            while (current != NULL && count < k) 
			{
                next = current->nextnode;
                current->nextnode = prev;
                prev = current;
                current = next;
                count++;
            }
            
            head->nextnode = current;  // Link the remaining part
            return prev;  // New head of the reversed part
        }

        
        void Algorithim() // Algorithm to reverse every 3rd group of nodes
       {
             current = head;
             Node* start = NULL;
             Node* end = NULL;
    
             int num = 1;
             int size = 3;

             while (current != NULL) 
            {
              Node* partStart = current;
              Node* partEnd = current;

        // Move the partEnd pointer to the end of the current group
               for (int i = 1; i < size && partEnd->nextnode != NULL; i++) 
             {
                  partEnd = partEnd->nextnode;
             }

              Node* next = partEnd->nextnode;
              partEnd->nextnode = NULL;

        // Reverse the odd parts
             if (num % 2 == 1) 
			 {
                   partStart = Reverse(partStart, size);
             }

        // If it's the first part, set the start
             if (start == NULL) 
			 {
                 start = partStart;
             }
			  else
			   {
                 end->nextnode = partStart;
               }

        // Update the end
              end = partStart;
              
              while (end->nextnode != NULL) 
			  {
                  end = end->nextnode;
               }

          // Move to the next part
               current = next;
               num++;
           }

               head = start;  // Update the list's head
        }

};

int main() {
    LinkedList L1;
    
    // Adding 20 elements to the linked list
    L1.Add_End(1);
    L1.Add_End(2);
    L1.Add_End(3);
    L1.Add_End(4);
    L1.Add_End(5);
    L1.Add_End(6);
    L1.Add_End(7);
    L1.Add_End(8);
    L1.Add_End(9);
    L1.Add_End(10);
   

    // Print the original list
    cout << "Original List:" << endl;
    L1.Print();
    
    // Apply the algorithm
    L1.Algorithim();
    
    // Print the modified list
    cout << "\n\nModified List:" << endl;
    L1.Print();

    return 0;
}
