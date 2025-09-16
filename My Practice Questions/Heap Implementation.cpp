 #include <iostream>
using namespace std;

class MinHeap 
{
private:
    int *arr;       
    int capacity;   
    int heap_size;  

public:
    MinHeap(int capacity) 
    {
        this->capacity = capacity;
        heap_size = 0;
        arr = new int[capacity + 1]; // 1-based indexing
        
        arr[0] = -1; // 1-based indexing
    }

    ~MinHeap() 
    {
        delete[] arr;
    }

    void insert(int val) 
    {
        if (heap_size == capacity) 
        {
            cout << "Heap overflow! Cannot insert more elements." << endl;
            return;
        }

        heap_size++;
        int index = heap_size;
        arr[index] = val;

        // Maintain min-heap property by bubbling up
        while (index > 1) 
        {
            int parent = index / 2;
            
            if (arr[parent] > arr[index]) 
            {
                swap(arr[parent], arr[index]);
                index = parent;
            } 
            else 
            {
                break;
            }
        }
    }

    void deleteMin() 
    {
        if (heap_size == 0) 
        {
            cout << "Heap underflow! Cannot delete element." << endl;
            return;
        }

        cout << "Deleting min: " << arr[1] << endl;
        
        arr[1] = arr[heap_size]; // Move the last element to the root
        heap_size--; 

        
        minHeapify(1); // Restore min-heap property
    }

    void minHeapify(int i) 
    {
        int left = 2 * i;
        int right = 2 * i + 1;

        int smallest = i; 

        // Check if the left child is smaller
        if (left <= heap_size && arr[left] < arr[smallest]) 
        {
            smallest = left;
        }

        // Check if the right child is smaller
        if (right <= heap_size && arr[right] < arr[smallest]) 
        {
            smallest = right;
        }

        // If the smallest is not the current element
        if (smallest != i) 
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest); 
        }
    }

    void printHeap() 
    {
        if (heap_size == 0) 
        {
            cout << "Heap is empty!" << endl;
            return;
        }

        for (int i = 1; i <= heap_size; ++i) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    MinHeap h(11);

    h.insert(3);
    h.insert(5);
    h.insert(9);
    h.insert(6);
    h.insert(2);
    h.insert(8);
    h.insert(10);
    h.insert(1);
    h.insert(7);
    h.insert(4);

    cout << "Min Heap is: ";
    h.printHeap();

    // Delete the minimum element
    h.deleteMin();

    cout << "After deleting min: ";
    h.printHeap();

    return 0;
}
