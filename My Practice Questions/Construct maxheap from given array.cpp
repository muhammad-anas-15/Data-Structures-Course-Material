#include <iostream>
using namespace std;

class MaxHeap 
{
private:
    int* arr;      
    int heap_size;  

public:
    MaxHeap(int* inputArr, int n) 
    {
        heap_size = n;  // Total elements including index 0
        arr = new int[heap_size + 1]; // Allocate memory for the heap array
        
        arr[0] = -1; // Insert -1 at index 0
        
        for (int i = 1; i <= heap_size; ++i) // Copy the elements from the given array into the heap array
        {
            arr[i] = inputArr[i - 1];
        }

        buildMaxHeap(); // Build the heap
    }

    ~MaxHeap() 
    {
        delete[] arr; // Clean up the dynamically allocated memory
    }

    void buildMaxHeap() 
    {
        for (int i = heap_size / 2; i >= 1; --i) // Start from the last non-leaf node and heapify each node
        {
            maxHeapify(i);
        }
    }

    void maxHeapify(int i) 
    {
        int l = left(i);  // Left child index
        int r = right(i); // Right child index
        int largest = i;

        if (l <= heap_size && arr[l] > arr[largest])  // If the left child is greater than the current element, swap
        {
            largest = l;
        }

        if (r <= heap_size && arr[r] > arr[largest]) // If the right child is greater than the current element, swap
        {
            largest = r;
        }

        if (largest != i)  // If the largest element is not the current element, swap and heapify
        {
            swap(arr[i], arr[largest]);
            maxHeapify(largest);
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
    int inputArr[] = {3, 5, 8, 7, 6, 10, 11}; // Input array
    int n = sizeof(inputArr) / sizeof(inputArr[0]); 

    MaxHeap heap(inputArr, n); // Create a MaxHeap object

    cout << "Max-Heap constructed from the array: ";
    heap.printHeap();

    return 0;
}
