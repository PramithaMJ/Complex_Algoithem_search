// A C++ program to find k'th
// smallest element in a stream
#include <bits/stdc++.h>
using namespace std;

// Prototype of a utility function
// to swap two integers
void swap(int *x, int *y);

// A class for Min Heap
class MinHeap
{
    int *harr;     // pointer to array of elements in heap
    int capacity;  // maximum possible size of min heap
    int heap_size; // Current number of elements in min heap
public:
    MinHeap(int a[], int size); // Constructor
    void buildHeap();
    void MinHeapify(
        int i); // To minheapify subtree rooted with index i
    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int extractMin(); // extracts root (minimum) element
    int getMin() { return harr[0]; }

    // to replace root with new node x and heapify() new
    // root
    void replaceMin(int x)
    {
        harr[0] = x;
        MinHeapify(0);
    }
};

MinHeap::MinHeap(int a[], int size)
{
    heap_size = size;
    harr = a; // store address of array
}

void MinHeap::buildHeap()
{
    int i = (heap_size - 1) / 2;
    while (i >= 0)
    {
        MinHeapify(i);
        i--;
    }
}

// Method to remove minimum element
// (or root) from min heap
int MinHeap::extractMin()
{
    if (heap_size == 0)
        return INT_MAX;

    // Store the minimum value.
    int root = harr[0];

    // If there are more than 1 items,
    // move the last item to
    // root and call heapify.
    if (heap_size > 1)
    {
        harr[0] = harr[heap_size - 1];
        MinHeapify(0);
    }
    heap_size--;

    return root;
}

// A recursive method to heapify a subtree with root at
// given index This method assumes that the subtrees are
// already heapified
void MinHeap::MinHeapify(int i)
{
    int l = left(i);
    int r = right(i);
    int smallest = i;
    if (l < heap_size && harr[l] < harr[i])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(&harr[i], &harr[smallest]);
        MinHeapify(smallest);
    }
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to return k'th largest element from input stream
void kthLargest(int k, vector<int> &A)
{
    // count is total no. of elements in stream seen so far
    int count = 0, x; // x is for new element

    // Create a min heap of size k
    int *arr = new int[k];
    MinHeap mh(arr, k);

    for (auto &x : A)
    {

        // Nothing much to do for first k-1 elements
        if (count < k - 1)
        {
            arr[count] = x;
            count++;

            cout << "Kth largest element is -1 " << endl;
        }

        else
        {
            // If this is k'th element, then store it
            // and build the heap created above
            if (count == k - 1)
            {
                arr[count] = x;
                mh.buildHeap();
            }

            else
            {
                // If next element is greater than
                // k'th largest, then replace the root
                if (x > mh.getMin())
                    mh.replaceMin(x); // replaceMin calls
                                      // heapify()
            }

            // Root of heap is k'th largest element
            cout << "Kth largest element is "
                 << mh.getMin() << endl;
            count++;
        }
    }
}
// Driver code
int main()
{
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    int K = 3;
    // Function call
    kthLargest(K, arr);
    return 0;
}
