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
			nextnode  = NULL;
		}
};
class LinkedList
{
	private:
		Node *head, *current;
		int List_size;
	
	public:
	    LinkedList()
		{
			head = current = NULL;
			List_size = 0;
		}	
		void Add_last(int val)
		{
			Node *newnode = new Node(val);
			
			if(head == NULL || List_size == 0)
			{
				head = current = newnode;
				head->nextnode = NULL;
				List_size++;
			}
			else
			{
				current->nextnode = newnode;
				current = newnode;
				newnode = NULL;
				List_size++;
			}
		}
		
		void Remove_last()
		{
			Node *temp = head;
			
			for(int i=0; i<List_size-1; i++)
			{
				temp = temp->nextnode;
			}
			current = temp;
			temp = temp->nextnode;
			
			delete temp;
			
			List_size--;
		}
		
		void Remove_first()
		{
			Node *temp = head;
			
			temp = current = head;
			
			head = head->nextnode;
			current = head;
			delete temp;
			List_size--;
		}
		
		void Remove_Pos(int pos)
		{
			Node *temp = head;
			
			for(int i= 1; i<pos; i++)
			{
				temp= temp->nextnode;
			}
			
			current = temp;
			temp = temp->nextnode;
			
			current->nextnode = temp->nextnode;
			delete temp;
			List_size--;
		}
		
         void Remove_at(int pos) 
		 {
            if (pos < 0 || pos >= List_size) // if the position is valid
	        {
               return; 
            }

    
           if (pos == 0) //removal of the first node
	        {
               Node *temp = head;
               head = head->nextnode;
               delete temp;
            }
    
           else if (pos == List_size - 1) // Removal of the last node
	       {
               Node *temp = head;
               for (int i = 0; i < List_size - 2; i++) 
		       {
                   temp = temp->nextnode;
                }
                   current = temp;
                   temp = temp->nextnode;
                   delete temp;
                   current->nextnode = NULL;
            }
    
            else //removal of any other node
         	{
                Node *temp = head;
                for (int i = 1; i < pos; i++) 
	         	{
                   temp = temp->nextnode;
                }
                    current = temp;
			        temp = temp->nextnode;
			        current->nextnode = temp->nextnode;
			        delete temp;
			        List_size--;
               }

          }

		
		void Print()
		{
			current = head;
			
			for(int i= 0; i<List_size; i++)
			{
				cout<<current->data<<" ";
				current = current->nextnode;
			}
		}
};
int main()
{
	LinkedList L1;
	L1.Add_last(3);
	L1.Add_last(5);
	L1.Add_last(7);
	L1.Add_last(9);
	L1.Print();
	cout<<"\n\n";
//	L1.Remove_last();
//	L1.Print();
//	L1.Remove_first();
//	cout<<"\n\n";
//	L1.Print();
//	L1.Remove_Pos(1);
    L1.Remove_at(1);
	L1.Print();
}