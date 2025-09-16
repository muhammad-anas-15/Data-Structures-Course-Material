#include <iostream>
using namespace std;

class MaxHeap 
{
private:
    int *arr;       
    int capacity;  
    int heap_size; 

public:
    MaxHeap(int capacity) 
    {
        this->capacity = capacity;
        heap_size = 0;
        arr = new int[capacity + 1]; // 1-based indexing
        
        arr[0] = -1; // 1-based indexing
    }

    ~MaxHeap() 
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

        
        while (index > 1) // Maintain max-heap property by bubbling up
        {
            int parentIdx = index / 2;
            if (arr[parentIdx] < arr[index]) 
            {
                swap(arr[parentIdx], arr[index]);
                index = parentIdx;
            } 
            else 
            {
                break;
            }
        }
    }

    void deleteMax() 
    {
        if (heap_size == 0) 
        {
            cout << "Heap underflow! Cannot delete element." << endl;
            return;
        }

        cout << "Deleting max: " << arr[1] << endl;
        arr[1] = arr[heap_size]; // Move the last element to the root
        
        heap_size--; 

        maxHeapify(1); // Restore max-heap property
    }

    void maxHeapify(int i) 
    {
        int left = 2 * i;   
        int right = 2 * i + 1; 
        
        int largest = i;      // Assume the current element is the largest

        // Check if the left child is greater than the current element
        if (left <= heap_size && arr[left] > arr[largest]) 
        {
            largest = left;
        }

        // Check if the right child is greater than the current element
        if (right <= heap_size && arr[right] > arr[largest]) 
        {
            largest = right;
        }

        // If the largest element is not the current element, swap and continue heapifying
        if (largest != i) 
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest); 
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
    MaxHeap h(11);

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

    cout << "Max Heap is: ";
    h.printHeap();

    h.deleteMax();

    cout << "After deleting max: ";
    h.printHeap();

    return 0;
}
