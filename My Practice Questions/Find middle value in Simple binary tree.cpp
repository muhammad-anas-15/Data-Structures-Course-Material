    /*
       To find the mid value of a binary tree using an array without sorting, you can follow these steps:

        1) Traverse the tree to collect all node values into an array.
        2) Calculate the mid index of the array.
        3) The mid value can then be accessed directly using this index.    
    */
    
    
	// Function to collect values of the tree nodes into an array
    void collectValues(Node* node, int arr[], int &index) 
    {
        if (node == NULL)
            return;

        // Traverse the left subtree
        collectValues(node->left, arr, index);
        // Store the current node's data in the array
        arr[index++] = node->data;
        // Traverse the right subtree
        collectValues(node->right, arr, index);
    }

    // Function to find the mid value in the binary tree
    int findMidValue() 
    {
        if (size == 0)
            return -1; // Return -1 if the tree is empty

        int* arr = new int[size]; // Create an array to hold node values
        int index = 0;

        // Collect values from the binary tree into the array
        collectValues(root, arr, index);

        int midIndex = size / 2; // Calculate the mid index
        int midValue = arr[midIndex]; // Get the mid value

        delete[] arr; // Clean up the allocated array
        return midValue; // Return the mid value
    }