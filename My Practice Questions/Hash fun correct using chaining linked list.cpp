#include <iostream>
using namespace std;

class Node 
{
public:
    int key;
    int value;
    Node* next;

    Node(int k, int v) 
	{
        key = k;
        value = v;
        
        next = NULL;
    }
};

class HashTable 
{
private:
    int capacity; // Size of the hash table
    Node** table; // Array of pointers to nodes for chaining

    // Hash function to calculate index
    int hashFunction(int value) 
	{
        return value % capacity;
    }

public:
    // Constructor
    HashTable(int size) 
	{
        capacity = size;
        table = new Node*[capacity];
        
        for (int i = 0; i < capacity; i++) 
		{
            table[i] = NULL;
        }
    }

    // Destructor
    ~HashTable() 
	{
        for (int i = 0; i < capacity; i++) 
		{
            Node* current = table[i];
            
            while (current != NULL) 
			{
                Node* toDelete = current;
                current = current->next;
                
                delete toDelete;
            }
        }
        delete[] table;
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int value) 
	{
        int index = hashFunction(value);
        Node* newNode = new Node(key, value);

        if (table[index] == NULL) 
		{
            table[index] = newNode;
        } 
		else 
		{
            Node* current = table[index];
            
            while (current->next != NULL) 
			{
                if (current->value == value) 
				{
                    current->key = key; // Update key if value exists
                    delete newNode;
                    
                    cout << "Updated value " << value << " with key " << key << " at index " << index << endl;
                    return;
                }
                current = current->next;
            }

            if (current->value == value) 
			{
                current->key = key; // Update key if value exists
                delete newNode;
                
                cout << "Updated value " << value << " with key " << key << " at index " << index << endl;
                return;
            }
                                                                      
                                                                      
            current->next = newNode; // Add new node at the end of the chain
        }
        cout << "Inserted (" << key << ", " << value << ") at index " << index << endl;
    }

    // Delete a key-value pair from the hash table
    void remove(int value) 
	{
        int index = hashFunction(value);
        Node* current = table[index];
        
        Node* prev = NULL;

        while (current != NULL) 
		{
            if (current->value == value) 
			{
                if (prev == NULL) 
				{
                    table[index] = current->next;
                } 
				else 
				{
                    prev->next = current->next;
                }
                delete current;
                
                cout << "Value " << value << " deleted from index " << index << endl;
                return;
            }
            prev = current;
            current = current->next;
        }
        cout << "Value " << value << " not found." << endl;
    }

    // Search for a value by key
    int search(int value) 
	{
        int index = hashFunction(value);
        
        Node* current = table[index];

        while (current != NULL) 
		{
            if (current->value == value) 
			{
                return current->key;
            }
            current = current->next;
        }
        return -1; // Not found
    }

    // Display the hash table
    void display() 
	{
        for (int i = 0; i < capacity; ++i) 
		{
            cout << "Index " << i << ": ";
            Node* current = table[i];
            
            if (current == NULL) 
			{
                cout << "Empty";
            } 
			else 
			{
                while (current != NULL) 
				{
                    cout << "(" << current->key << ", " << current->value << ") ";
                    current = current->next;
                }
            }
            cout << endl;
        }
    }
};

int main() 
{
    HashTable ht(10); // Create a hash table of size 10

    // Insert some key-value pairs
    ht.insert(1, 100);
    ht.insert(2, 200);
    ht.insert(11, 300); // Collision with value 100

    // Display the hash table
    cout << "Hash Table: " << endl;
    ht.display();

    // Search for values
    cout << "Search for value 100: " << ht.search(100) << endl;
    cout << "Search for value 200: " << ht.search(200) << endl;
    cout << "Search for value 300: " << ht.search(300) << endl;

    // Delete a value
    ht.remove(100);
    ht.remove(500); // Not found

    // Display the hash table after deletion
    cout << "Hash Table after deletions: " << endl;
    ht.display();

    return 0;
}
