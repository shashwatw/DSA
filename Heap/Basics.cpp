// Referance Video
// https://www.youtube.com/watch?v=NKJnHewiGdc

// TC - O(logn) -time and space

#include <iostream>
using namespace std;

class heap
{
    int arr[100];
    int size = 0;

public:
    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while (index > 1)
        {
            int parent = index / 2;

            // MAX HEAP CASE
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

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void deleteFromHeap()
    {
        if (size == 0)
        {
            cout << "Nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        int i = 1;
        while (i <= size)
        {
            // For 0 Based indexing
            //  int leftChild = 2 * i + 1;
            //  int rightChild = 2 * i + 2;

            // For 1 based indexing
            int leftChild = 2 * i;
            int rightChild = 2 * i + 1;

            if (leftChild < size && arr[i] < arr[leftChild])
            {
                swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else if (rightChild < size && arr[i] < arr[rightChild])
            {
                swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else
            {
                return;
            }
        }
    }
};

// MaX heapify
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftChild = 2 * i;
    int rightChild = 2 * i + 1;

    if (leftChild < n && arr[largest] < arr[leftChild])
    {
        largest = leftChild;
    }

    if (rightChild < n && arr[largest] < arr[rightChild])
    {
        largest = rightChild;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    // delete topmost element from heap
    h.deleteFromHeap();
    h.print();

    int arr[6] = {-1,
                  54,
                  53,
                  55,
                  52,
                  50};
    int n = 5;
    // Kisi bhi heap mein n/2 + 1 se n tk saari nodes leaf nodes hoti hai so they are itself an individual heap
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    cout << endl
         << "Printing the array after heapify: ";

    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}