#include <iostream>
using namespace std;

class MinHeap 
{
private:
    int* arr;      
    int heap_size;  

public:
  
    MinHeap(int* inputArr, int n) 
    {
        heap_size = n - 1;  // Excluding index 0 (empty placeholder)
        
        arr = new int[heap_size + 1];
        
        
        for (int i = 1; i <= heap_size; ++i) // Copy the elements from the given array into the heap array (skip index 0)
        {
            arr[i] = inputArr[i];
        }

        buildMinHeap();  // Build the heap
    }

    void buildMinHeap() 
    {
        
        for (int i = heap_size / 2; i >= 1; --i) // Start from the last non-leaf node and heapify each node
        {
            minHeapify(i);
        }
    }

    void minHeapify(int i) 
    {
        int l = left(i);  // Left child index
        int r = right(i); // Right child index
        
        int smallest = i;

        
        if (l <= heap_size && arr[l] < arr[smallest]) // If the left child is smaller than the current element, swap
        {
            smallest = l;
        }

        
        if (r <= heap_size && arr[r] < arr[smallest]) // If the right child is smaller than the current element, swap
        {
            smallest = r;
        }

       
        if (smallest != i)  // If the smallest element is not the current element, swap and heapify
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }

    int left(int i) 
    { 
        return 2 * i; 
    }

    int right(int i) 
    { 
        return 2 * i + 1; 
    }

    void printHeap() 
    {
        for (int i = 1; i <= heap_size; ++i) 
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() 
{
    // Input array with index 0 as empty placeholder
    int arr[] = {0, 3, 5, 8, 7, 6, 10, 11};
    
    int n = sizeof(arr) / sizeof(arr[0]); 

    MinHeap heap(arr, n);

    // Print the constructed Min-Heap
    cout << "Min-Heap constructed from the array: ";
    heap.printHeap();

    return 0;
}
