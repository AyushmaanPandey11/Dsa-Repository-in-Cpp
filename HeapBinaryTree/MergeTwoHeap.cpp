#include<iostream>
#include<vector>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size;

public:
    Heap()
    {
        size = 0;
        // in Heaps, We don't use the first 0th index, that's why it is initialized as -1
        arr[0] = -1;
    }
    void insertion(int val)
    {
        // incrementing the size by one
        size = size + 1;
        // index initialization and definition
        int index = size;
        // storing the value inside the new block of array at the end
        arr[index] = val;
        // child and parent node
        while (index > 1)
        {
            // getting the parent node index in the array
            int parent = index / 2;
            // checking for values between them
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
        cout << "Values in the array are :" << endl;
        for (int idx = 1; idx <= size; idx++)
        {
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
    void heapify(int size, int index)
    {
        int largest = index;
        int leftidx = 2 * index + 1;
        int rightidx = 2 * index + 2;
        // conditions
        // left
        if (leftidx < size && arr[largest] < arr[leftidx])
        {
            largest = leftidx;
        }
        // right
        if (rightidx < size && arr[largest] < arr[rightidx])
        {
            largest = rightidx;
        }
        // swapping to heapify
        if (index != largest)
        {
            swap(arr[index], arr[largest]);
            heapify(size, largest);
        }
    }
    void MergeHeap(const Heap& h)
    {
        int size_merged = size + h.size;

        // Copy elements from h.arr to this.arr
        for (int i = 1; i <= h.size; i++) {
            arr[size + i] = h.arr[i];
        }

        // Heapify the merged heap
        for (int i = size_merged / 2; i >= 1; i--) {
            heapify(size_merged, i);
        }

        // Update the size
        size = size_merged;
    }
};

int main()
{
    Heap h1;
    h1.insertion(50);
    h1.insertion(55);
    h1.insertion(53);
    h1.insertion(52);
    h1.insertion(54);
    Heap h2;
    h2.insertion(60);
    h2.insertion(65);
    h2.insertion(63);
    h2.insertion(62);
    h2.insertion(64);

    cout << "Heap 1:" << endl;
    h1.print();

    cout << "Heap 2:" << endl;
    h2.print();

    h1.MergeHeap(h2);

    cout << "Merged Heap:" << endl;
    h1.print();

    return 0;
}
