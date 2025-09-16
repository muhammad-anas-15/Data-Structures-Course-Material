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
//		void Add_Start(int val)
//		{
//			Node *newnode = new Node(val);
//			newnode->nextnode = head;
//			head = newnode;
//			current =  head->nextnode;
//			List_Size++;
//		}
//		
//		void Add_Post(int pos, int val)
//		{
//			Node *newnode = new Node(val);
//			if(pos < 0 || pos > List_Size)
//			{
//				cout<<"Invalid Position!"<<endl;
//			}
//			else
//			{
//				current = head;
//				for(int i =0 ; i<pos; i++)
//				{
//					current = current->nextnode;
//				}
//				newnode->nextnode = current->nextnode;
//				current->nextnode = newnode;
//				current = newnode;
//				List_Size++;
//			}
//		}
		
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
			Node *previous = NULL;
			Node *forward = NULL;
			
			current = head;
			
		while(current != NULL)
		{
			forward = current->nextnode;
			current->nextnode = previous;
			previous = current;
			current = forward;
		}	
		head = previous;
}
       void Remove_duplicates_Sorted()
       {
       	 current = head;
       	 
       	 while(current != NULL)
       	 {
       	 	if((current->nextnode !=NULL) && current->data == current->nextnode->data)
       	 	{
       	 		Node *next = current->nextnode->nextnode;
       	 		Node *node_to_delete = current->nextnode;
       	 		
       	 		delete node_to_delete;
       	 		
       	 		current->nextnode = next;
			}
			else
			{
				current = current->nextnode;
			}
		}
	   }
	   
	   void Remove_duplicates_UnSorted()
       {
          current = head;
    
          while (current != NULL && current->nextnode != NULL)
         {
             Node *temp = current;
        
            while (temp->nextnode != NULL)
            {
                 if (current->data == temp->nextnode->data) // Check for duplicate by comparing data
               {
                // Duplicate found, remove the node
                  Node *node_to_delete = temp->nextnode;
                  
                  temp->nextnode = temp->nextnode->nextnode;
                  
                  delete node_to_delete;
                  
                  List_Size--; // Decrement list size after deletion
               }
               else
               {
                  temp = temp->nextnode; // Only move to the next node if no deletion happens
               }
            }
        
                current = current->nextnode; // Move to the next node in the outer loop
          }
      }

};
int main()
{
//	LinkedList L1;
//	cout<<"Sorted Linked List!"<<endl;
//	L1.Add_End(1);
//	L1.Add_End(2);
//	L1.Add_End(2);
//	L1.Add_End(3);
//	L1.Add_End(3);
//	L1.Add_End(3);
//	L1.Add_End(4);
//
//	L1.Print();
//	cout<<"\n\n";
//    L1.Remove_duplicates_Sorted();
//    L1.Print();
//    cout<<"\n\n";
//    
    LinkedList L2;
	cout<<"Sorted Linked List!"<<endl;
	L2.Add_End(4);
	L2.Add_End(5);
	L2.Add_End(2);
	L2.Add_End(2);
	L2.Add_End(4);
	L2.Add_End(2);
	L2.Add_End(5);
	L2.Remove_duplicates_UnSorted();
	L2.Print();
	

}