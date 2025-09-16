#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node *next, *previous;
		
		Node(int d)
		{
			this->data = d;
			next = previous = NULL;
		}
};

class Doubly_LinkedList
{
	private:
		Node *head, *current;
		int List_size;
	
	public:
		Doubly_LinkedList()
		{
			head = current = NULL;
			List_size = 0;
		}
		
		// Print the entire list
		void Print()
		{
			current = head;
			while(current != NULL)  
			{
				cout << current->data << " ";
				current = current->next;
			}
			cout << endl;  
		}

		void Delete_Start()
		{
			if (head == NULL)
			{
				cout << "List is empty!" << endl;
				return;
			}

			Node *temp = head;
			head = head->next;

			if (head != NULL)
			
				head->previous = NULL;

			delete temp;
			List_size--;
		}


		void Delete_Last()
		{
			if (head == NULL)
			{
				cout << "List is empty!" << endl;
				return;
			}

			if (head->next == NULL)  
			{
				delete head;
				head = NULL;
			}
			else
			{
				Node *temp = head;
				current = head;
				while (current->next != NULL)
				{
					current = current->next;
					temp = temp->next;
				}

				current->previous->next = NULL;
				current = current->previous;
				delete temp;
			}

			List_size--;
		}

	
		void Delete_pos(int pos)
		{
			if (pos < 1 || pos > List_size)
			{
				cout << "Invalid position!" << endl;
				return;
			}

			if (pos == 1)
			{
				Delete_Start();
			}
			else
			{
				current = head;
				int count = 1;

				while (count < pos && current != NULL)
				{
					current = current->next;
					count++;
				}

				// If node is the last node
				if (current->next == NULL)
				{
					Delete_Last();
				}
				else
				{
					Node *temp = current;
					temp->previous->next = temp->next;
					temp->next->previous = temp->previous;

					delete temp;
					List_size--;
				}
			}
		}
int main()
	{
		
	Doubly_LinkedList D1;
	D1.Add_Start(4);
	D1.Add_Start(5);
	D1.Add_Start(6);
	D1.Print();

	D1.Add_Last(7);
	D1.Print();

	D1.Add_pos(2, 10);
	D1.Print();

	D1.Delete_Start();
	D1.Print();

	D1.Delete_Last();
	D1.Print();

	D1.Delete_pos(2);
	D1.Print();

	return 0;
}
