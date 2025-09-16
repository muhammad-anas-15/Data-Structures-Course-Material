#include <iostream>
using namespace std;

class Heap 
{
public:
    static const int MAX_SIZE = 100;
    int arr[MAX_SIZE];
    int size;

    Heap() 
	{
        arr[0] = -1; 
        size = 0;
    }

    void insert(int val) 
	{
        if (size >= MAX_SIZE - 1) 
		{
            cout << "Heap overflow! Cannot insert more elements." << endl;
            return;
        }

        size += 1;
        int index = size;
        arr[index] = val;

        // Maintain heap property (max-heap by default)
        while (index > 1) 
		{
            int parent = index / 2;
            
            if (arr[parent] < arr[index]) 
			{
                swap(arr[parent], arr[index]);
                index = parent;
            } 
			else 
			{
                return;
            }
        }
    }

    void Print() 
	{
        if (size == 0) 
		{
            cout << "Heap is empty. Nothing to print." << endl;
            return;
        }

        for (int i = 1; i <= size; i++) 
		{
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    // Heapify function that works for both max-heap and min-heap
    void heapify(int index, bool isMaxHeap) 
	{
        int leftChild = 2 * index;
        int rightChild = 2 * index + 1;
        int extreme = index;

        if (isMaxHeap) 
		{
            // Max-Heap: Parent should be greater than or equal to both children
            if (leftChild <= size && arr[leftChild] > arr[extreme]) 
			{
                extreme = leftChild;
            }
            if (rightChild <= size && arr[rightChild] > arr[extreme]) 
			{
                extreme = rightChild;
            }
        } 
		else 
		{
            // Min-Heap: Parent should be less than or equal to both children
            if (leftChild <= size && arr[leftChild] < arr[extreme]) 
			{
                extreme = leftChild;
            }
            if (rightChild <= size && arr[rightChild] < arr[extreme]) 
			{
                extreme = rightChild;
            }
        }

        if (extreme != index) 
		{
            swap(arr[extreme], arr[index]);
            heapify(extreme, isMaxHeap); // Recursively heapify the affected subtree
        }
    }

    // Extract the max element (for max-heap)
    int extractMax()
	{
        if (size == 0) 
		{
            cout << "Heap is empty!" << endl;
            return -1; // Return -1 if heap is empty
        }

        int maxVal = arr[1];
        
        arr[1] = arr[size]; // Move the last element to the root
        size--;

        // Reheapify the heap (max-heap property)
        heapify(1, true);

        return maxVal;
    }

    // Extract the min element (for min-heap)
    int extractMin() 
	{
        if (size == 0)
		{
            cout << "Heap is empty!" << endl;
            return -1; // Return -1 if heap is empty
        }

        int minVal = arr[1];
        
        arr[1] = arr[size]; // Move the last element to the root
        size--;

        // Reheapify the heap (min-heap property)
        heapify(1, false);

        return minVal;
    }

    void heapSort(bool isMaxHeap = true) 
	{
        // Step 1: Build the heap (max-heap or min-heap)
        for (int i = size / 2; i >= 1; i--) 
		{
            heapify(i, isMaxHeap);
        }

        // Step 2: Repeatedly extract the root and reheapify the heap
        int originalSize = size;
        
        while (size > 1) 
		{
            // Swap the root with the last element
            swap(arr[1], arr[size]);
            size--; // Decrease the heap size

            // Reheapify the heap
            heapify(1, isMaxHeap);
        }

        // Restore the size to original for display
        size = originalSize;
    }
};

int main() 
{
    Heap maxHeap;

    // Inserting elements into the heap
    maxHeap.insert(50);
    maxHeap.insert(55);
    maxHeap.insert(53);
    maxHeap.insert(52);
    maxHeap.insert(54);

    cout << "Max Heap before heap sort: ";
    maxHeap.Print(); // Print the heap

    // Perform heap sort in descending order (max-heap)
    maxHeap.heapSort(true);

    cout << "Max Heap after heap sort (Descending Order): ";
    maxHeap.Print(); // Print sorted array

    // Create a min-heap instance
    Heap minHeap;

    // Inserting elements into the min-heap
    minHeap.insert(50);
    minHeap.insert(55);
    minHeap.insert(53);
    minHeap.insert(52);
    minHeap.insert(54);

    cout << "Min Heap before heap sort: ";
    minHeap.Print(); // Print the heap

    // Perform heap sort in ascending order (min-heap)
    minHeap.heapSort(false);

    cout << "Min Heap after heap sort (Ascending Order): ";
    minHeap.Print(); // Print sorted array

    return 0;
}
