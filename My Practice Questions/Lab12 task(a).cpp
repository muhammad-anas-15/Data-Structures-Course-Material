#include <iostream>
using namespace std;

class Heap {
public:
    int htree[100]; 
    int size;       

    Heap() : size(0) {}

    int getParent(int child) 
	{
        return (child == 0) ? -1 : (child - 1) / 2;
    }

    int getLeft(int parent) 
	{
        int child = 2 * parent + 1;
        
        return (child < size) ? child : -1;
    }

    int getRight(int parent) 
	{
        int child = 2 * parent + 2;
        
        return (child < size) ? child : -1;
    }

    void swap(int &a, int &b) 
	{
        int temp = a;
        a = b;
        b = temp;
    }

    void heapifyUp(int node) 
	{
        int parent = getParent(node);
        
        if (node >= 0 && parent >= 0 && htree[parent] < htree[node]) 
		{
            swap(htree[node], htree[parent]);
            
            heapifyUp(parent);
        }
    }

    void heapifyDown(int node) 
	{
        int lchild = getLeft(node);
        int rchild = getRight(node);
        
        int largest = node;

        if (lchild >= 0 && htree[lchild] > htree[largest]) 
		{
            largest = lchild;
        }
        if (rchild >= 0 && htree[rchild] > htree[largest]) 
		{
            largest = rchild;
        }

        if (largest != node) 
		{
            swap(htree[node], htree[largest]);
            
            heapifyDown(largest);
        }
    }

    void insert(int value) 
	{
        if (size >= 100) 
		{
            cout << "Heap overflow, cannot insert more elements." << endl;
            return;
        }

        htree[size] = value;
        size++;
        heapifyUp(size - 1);
    }

    void del(int value) 
	{
        int index = -1;

        for (int i = 0; i < size; i++) 
		{
            if (htree[i] == value) 
			{
                index = i;
                break;
            }
        }

        if (index != -1) 
		{
            swap(htree[index], htree[size - 1]); // Swap with last element
            size--;                             // Reduce heap size
            heapifyDown(index);                 // Restore heap property
        } 
		else 
		{
            cout << "Value " << value << " not found in heap." << endl;
        }
    }

    void display() 
	{
        for (int i = 0; i < size; i++) 
		{
            cout << htree[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Heap h;

    h.insert(5);
    h.insert(3);
    h.insert(8);
    h.insert(2);
    h.insert(7);

    h.display(); 

    h.del(5);
    h.del(3);

    h.display(); 

    return 0;
}
