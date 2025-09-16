#include <iostream>
#include <string>
using namespace std;


class Node // Class for each node
{
   public:
      int data;  
      Node *next; 

      Node(int val)  // Constructor
      {
          data = val;
          next = NULL; 
      }
};

class Stack 
{
   private:
       Node *top; // Pointer to keep track of the top value
       int stack_size, current_size; // To track the size of the stack.
       

   public:
       Stack(int s) // Constructor with size parameter
       {
          top = NULL;
          stack_size = s; 
          
          current_size = 0; // Initialize current size to 0
       } 

       ~Stack() // Destructor
       {
          while (!isEmpty()) 
          {
            Pop(); 
          }
       }

    bool isEmpty() // Check if the stack is empty
    {
        return top == NULL; 
    }
    
    bool isFull() // Check if the stack is full
    {
        return current_size >= stack_size;
    }

    void Push(int val) // Push value onto the stack
    {
        if (isFull()) 
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }

        Node* newNode = new Node(val); // Create a new node
        newNode->next = top; 
        
        top = newNode; // Move the top pointer
        
        current_size++; // Increment the current size
    }

    int Pop() // Pop value from the stack
    {
        if (!isEmpty()) 
        {
            Node* temp = top; // Temporary node to delete
            int val = temp->data;
             
            top = top->next; 
            delete temp; 
            
            
            return val; 
        }
        return -1; 
    }

    int Peek() // Get the top value
    {
        if (!isEmpty()) 
        {
            return top->data; 
        }
        return -1; 
    }
    
int longest_valid_parenthes(string &s) // Function to calculate length of longest valid parentheses
{
    int len = 0; // Variable for maximum length
    
    int i = 0; // Initialize index for the while loop

    Push(-1); // Initialize stack with -1 to handle valid parentheses from the start

    while (i < s.length()) // Loop until the end of the string
    {
        if (s[i] == '(') // if find start paranthesis push into stack.
        {
            Push(i); 
        } 
        else // if find closing paranthesis start pop.
        {
            Pop(); // Pop for the matching ')'

            if (isEmpty()) // If stack is empty, push the current index
            {
                Push(i); 
            } 
            else 
            {
                int length = i - Peek(); // Calculate the length of valid substring such as if peek value index is 2 and i is 0 so 2-0 = 0.
                
                len = max(len, length); //maximum length 
            }
        }
        i++; // Increment the index
    }
    return len; // Return the maximum length of valid parentheses
}



};


int main()
 {
    string s;
    cout << "Enter a string of parentheses: ";//prompt user to enter paranthesis.
    getline(cin, s);

    Stack S1(s.length()); // Create a stack with the length of the string.

    int result = S1.longest_valid_parenthes(s);//store the result in variable.
    
    cout << "The length of longest valid parentheses substring : " << result << endl;

    return 0;
}

