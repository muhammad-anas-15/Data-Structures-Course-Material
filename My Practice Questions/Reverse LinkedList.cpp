#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *nextnode;
		
		Node(int val)
		{
			data = val;
			nextnode = NULL;
		}
};
class LinkedList
{
	private:
		Node *head, *current;
		int List_Size;
	
	public:
	    LinkedList()
		{
			head = current = NULL;
			List_Size = 0;
		}	
		
        void Add_End(int val)
        {
        	
        	Node *newnode = new Node(val);
        	
        	if(head == NULL || List_Size == 0)
        	{
        		head = current = newnode;
        		newnode = NULL;
        		List_Size++;
			}
			else
			{
				current->nextnode = newnode;
				current = newnode;
				newnode = NULL;
				List_Size++;
			}
		}
		
		void Print()
		{
			current = head;
			for(int i=0; i<List_Size; i++)
			{
				cout << current->data <<" ";
				current = current->nextnode;
			}
		}
        
		void Reverse() 
		{
         Node* previous = NULL;
         Node* forward = NULL;
         Node* current = head;

         // Reverse the linked list while skipping negative nodes
        while (current != NULL) 
		{
           forward = current->nextnode;

        if (current->data < 0) 
		{
            previous = current; // Keep negative nodes in place
        } 
		else 
		{
            current->nextnode = previous; // Reverse positive nodes
            previous = current;
        }

        current = forward;
    }

    head = previous; // Update head to the new front of the list
}

};

  int main()
  {
	LinkedList L1;
	L1.Add_End(1);
	L1.Add_End(2);
	L1.Add_End(3);
	L1.Add_End(4);
	L1.Add_End(5);
	L1.Add_End(6);
     
    L1.Print(); 
	
	
	//L1.Print();
//	L1.Algorihim();

	cout<<"\n\n";
	
    L1.Reverse();
    cout<<"\n\n";
    L1.Print(); 
    
//	L1.Add_End(7);
//	L1.Add_End(8);
//	L1.Add_End(9);
//	L1.Add_End(10);	
//	
//	L1.Print();
// 
//	L1.Add_End(11);
//	L1.Add_End(12);
//	L1.Add_End(13);
//	L1.Add_End(14);
//	L1.Add_End(15);
//	L1.Add_End(16);
//	L1.Add_End(17);
//	L1.Add_End(18);
//	L1.Add_End(19);
//	L1.Add_End(20);	
//	
//	L1.Reverse();
//	L1.Print();
}
