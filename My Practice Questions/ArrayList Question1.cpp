#include <iostream>
using namespace std;

void RearrangeList(int* arr, int n) 
{
    int* posPtr = arr;        // Pointer to the first position for positive values
    int* negPtr = arr + 1;    // Pointer to the first position for negative values

    while (true) 
    {
        // Move posPtr to the next position that contains a misplaced negative value
        while (posPtr < arr + n && *posPtr >= 0) 
        {
            posPtr += 2;
        }

        // Move negPtr to the next position that contains a misplaced positive value
        while (negPtr < arr + n && *negPtr < 0) 
        {
            negPtr += 2;
        }

        // If either pointer goes out of bounds, the array is rearranged
        if (posPtr >= arr + n || negPtr >= arr + n) 
        {
            break;
        }

        // Swap the values pointed to by posPtr and negPtr
        int temp = *posPtr;
        *posPtr = *negPtr;
        *negPtr = temp;
    }
}

int main() 
{
    int arr[] = {4, 2, -1, 5, -3, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    RearrangeList(arr, n);

    // Output the rearranged array
    for (int i = 0; i < n; ++i) 
    {
        cout << arr[i] << " ";
    }
    return 0;
}
