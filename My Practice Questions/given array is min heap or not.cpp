#include <iostream>
using namespace std;

// Function to check if the given binary tree is complete
bool isCompleteBinaryTree(int* arr, int n) 
{
    for (int i = 1; i <= n; ++i) 
    {
        int left = 2 * i;      // Left child index
        int right = 2 * i + 1; // Right child index

        // If left child index exceeds n, the binary tree is complete
        if (left > n) 
        {
            break;
        }

        // If right child exists but left child does not, it's incomplete
        if (right <= n && left > n) 
        {
            return false;
        }
    }

    return true;
}

// Function to check if the array satisfies the Min-Heap property
bool isMinHeap(int* arr, int n) 
{
    for (int i = 1; i <= n / 2; ++i) 
    {
        int left = 2 * i;      // Left child index
        int right = 2 * i + 1; // Right child index

        // Check if the left child exists and is smaller than the parent
        if (left <= n && arr[i] < arr[left]) 
        {
            return false; // Violates Min-Heap property
        }

        // Check if the right child exists and is smaller than the parent
        if (right <= n && arr[i] < arr[right]) 
        {
            return false; // Violates Min-Heap property
        }
    }
    return true;
}

int main() 
{
    // Example array (index 0 is placeholder)
    int arr[] = {0, 3, 5, 8, 7, 6, 10, 11};
    int n = sizeof(arr) / sizeof(arr[0]) - 1; // Exclude index 0

    if (isCompleteBinaryTree(arr, n)) 
    {
        cout << "The binary tree is complete." << endl;
        if (isMinHeap(arr, n)) 
        {
            cout << "The given array is a Min-Heap." << endl;
        } 
        else 
        {
            cout << "The given array is NOT a Min-Heap." << endl;
        }
    } 
    else 
    {
        cout << "The binary tree is NOT complete." << endl;
    }

    return 0;
}
