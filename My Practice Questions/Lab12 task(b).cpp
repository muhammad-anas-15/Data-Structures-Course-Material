#include <iostream>
using namespace std;

class HeapSort 
{
private:
    int heap[100]; 
    int size;      

public:
    HeapSort() : size(0) {}

    void insertMaxHeap(int value) 
	{
        heap[size] = value;
        int current = size;

        while (current > 0 && heap[(current - 1) / 2] < heap[current]) 
		{
            swap(heap[current], heap[(current - 1) / 2]);
            
            current = (current - 1) / 2;
        }

        size++;
        printHeap();
    }

    void insertMinHeap(int value) 
	{
        heap[size] = value;
        int current = size;

        while (current > 0 && heap[(current - 1) / 2] > heap[current]) 
		{
            swap(heap[current], heap[(current - 1) / 2]);
            
            current = (current - 1) / 2;
        }

        size++;
        printHeap();
    }

    int extractMax() 
	{
        if (size == 0) return -1;

        int maxVal = heap[0];
        heap[0] = heap[size - 1];
        size--;

        int current = 0;
        
        while (true) 
		{
            int left = 2 * current + 1;
            int right = 2 * current + 2;
            int largest = current;

            if (left < size && heap[left] > heap[largest]) largest = left;
            if (right < size && heap[right] > heap[largest]) largest = right;

            if (largest != current) 
			{
                swap(heap[current], heap[largest]);
                current = largest;
            } 
			else 
			{
                break;
            }
        }

        return maxVal;
    }

    int extractMin() 
	{
        if (size == 0) return -1;

        int minVal = heap[0];
        heap[0] = heap[size - 1];
        size--;

        // Min heapify downwards
        int current = 0;
        
        while (true) 
		{
            int left = 2 * current + 1;
            int right = 2 * current + 2;
            int smallest = current;

            if (left < size && heap[left] < heap[smallest]) smallest = left;
            if (right < size && heap[right] < heap[smallest]) smallest = right;

            if (smallest != current) 
			{
                swap(heap[current], heap[smallest]);
                current = smallest;
            } 
			else 
			{
                break;
            }
        }

        return minVal;
    }

    void printHeap() 
	{
        cout << "Heap: ";
        
        for (int i = 0; i < size; i++) 
		{
            cout << heap[i] << " ";
        }
        cout << endl;
    }

    void clearHeap() 
	{
        size = 0;
    }
};

void sortAscending(int arr[], int n) 
{
    HeapSort heap;
    cout << "Sorting in Ascending Order using Max Heap:\n";

    for (int i = 0; i < n; i++) 
	{
        heap.insertMaxHeap(arr[i]);
    }

    cout << "Ascending Order: ";
    
    for (int i = 0; i < n; i++) 
	{
        cout << heap.extractMax() << " ";
    }
    cout << endl;
}

void sortDescending(int arr[], int n)
{
    HeapSort heap;
    
    cout << "Sorting in Descending Order using Min Heap:\n";

    for (int i = 0; i < n; i++) 
	{
        heap.insertMinHeap(arr[i]);
    }

    cout << "Descending Order: ";
    
    for (int i = 0; i < n; i++) 
	{
        cout << heap.extractMin() << " ";
    }
    cout << endl;
}

int main() 
{
    int arr[] = {10, 5, 20, 2, 15};
    
    int n = sizeof(arr) / sizeof(arr[0]);

    sortAscending(arr, n);

    sortDescending(arr, n);

    return 0;
}
