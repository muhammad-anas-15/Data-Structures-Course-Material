#include <iostream>
using namespace std;

class HashTable 
{
private:
    int capacity; // Size of the hash table
    
    int **keys;   // Array to store keys
    int **values; // Array to store values

    // Hash function to calculate index
    int hashFunction(int key) 
	{
        return key % capacity;
    }

public:
    // Constructor
    HashTable(int size) 
	{
        capacity = size;
        
        keys = new int *[capacity];
        values = new int *[capacity];

        for (int i = 0; i < capacity; i++) 
		{
            keys[i] = nullptr;
            values[i] = nullptr;
        }
    }

    // Destructor
    ~HashTable() {
        for (int i = 0; i < capacity; i++) 
		{
            if (keys[i] != nullptr) 
			{
                delete keys[i];
                delete values[i];
            }
        }
        
        delete[] keys;
        delete[] values;
    }

    // Insert a key-value pair into the hash table
    void insert(int key, int value) 
	{
        int index = hashFunction(key);
        
        while (keys[index] != nullptr && *keys[index] != key) 
		{
            index = (index + 1) % capacity; // Linear probing
        }
        
        if (keys[index] == nullptr) 
		{
            keys[index] = new int(key);
            values[index] = new int(value);
        } 
		else 
		{
            *values[index] = value; // Update value if key exists
        }
        cout << "Inserted (" << key << ", " << value << ") at index " << index << endl;
    }

    // Delete a key-value pair from the hash table
    void remove(int key) 
	{
        int index = hashFunction(key);
        
        while (keys[index] != nullptr) 
		{
            if (*keys[index] == key) 
			{
                delete keys[index];
                delete values[index];
                
                keys[index] = nullptr;
                values[index] = nullptr;
                cout << "Key " << key << " deleted from index " << index << endl;
                
                return;
            }
            
            index = (index + 1) % capacity;
        }
        cout << "Key " << key << " not found." << endl;
    }

    // Search for a value by key
    int search(int key) 
	{
        int index = hashFunction(key);
        
        while (keys[index] != nullptr) 
		{
            if (*keys[index] == key) 
			{
                return *values[index];
            }
            
            index = (index + 1) % capacity;
        }
        return -1; // Not found
    }

    // Display the hash table
    void display() 
	{
        for (int i = 0; i < capacity; ++i) 
		{
            if (keys[i] != nullptr) 
			{
                cout << "Index " << i << ": (" << *keys[i] << ", " << *values[i] << ")\n";
            } 
			else 
			{
                cout << "Index " << i << ": Empty\n";
            }
        }
    }
};

int main() 
{
    HashTable ht(10); // Create a hash table of size 10

    // Insert some key-value pairs
    ht.insert(1, 100);
    ht.insert(2, 200);
    ht.insert(11, 300); // Collision with key 1

    // Display the hash table
    cout << "Hash Table: " << endl;
    ht.display();

    // Search for keys
    cout << "Search for key 1: " << ht.search(1) << endl;
    cout << "Search for key 11: " << ht.search(11) << endl;
    cout << "Search for key 3: " << ht.search(3) << endl;

    // Delete a key
    ht.remove(1);
    ht.remove(3);

    // Display the hash table after deletion
    cout << "Hash Table after deletions: " << endl;
    ht.display();

    return 0;
}
