#include <iostream>
using namespace std;

void RearrangeList(int* arr, int n) 
{
    int* evenPtr = arr;        // Pointer to the first even index (0)
    int* oddPtr = arr + 1;     // Pointer to the first odd index (1)

    while (true) 
	{
        // Move evenPtr to the next even position that contains an odd number
        while (evenPtr < arr + n && *evenPtr % 2 == 0) 
		{
            evenPtr += 2;
        }

        // Move oddPtr to the next odd position that contains an even number
        while (oddPtr < arr + n && *oddPtr % 2 != 0) 
		{
            oddPtr += 2;
        }

        // If either pointer goes out of bounds, the array is rearranged
        if (evenPtr >= arr + n || oddPtr >= arr + n) 
		{
            break;
        }

        // Manually swap the values pointed by evenPtr and oddPtr without using swap()
        int temp = *evenPtr;
        *evenPtr = *oddPtr;
        *oddPtr = temp;
    }
}

int main() {
    int arr[] = {5, 2, 9, 4, 7, 6, 1, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    RearrangeList(arr, n);

    // Output the rearranged array
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 0;
}
