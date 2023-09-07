#include<iostream>
#include<algorithm>
using namespace std;

class Heap
{
public:
    int size;
    int arr[100];

    Heap()
    {
        size = 0;
        arr[0] = -1;
    }

    void insertion(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;
        while (index > 1)
        {
            int parent = index / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
                return;
        }
    }

    void MaxHeapify(int idx)
    {
        int largest = idx;
        int leftchildidx = 2 * idx;
        int rightchildidx = 2 * idx + 1;
        if (leftchildidx <= size && arr[largest] < arr[leftchildidx])
        {
            largest = leftchildidx;
        }
        if (rightchildidx <= size && arr[largest] < arr[rightchildidx])
        {
            largest = rightchildidx;
        }
        if (largest != idx)
        {
            swap(arr[largest], arr[idx]);
            MaxHeapify(largest);
        }
    }

    void MinHeapify(int idx)
    {
        int smallest = idx;
        int leftchildidx = 2 * idx;
        int rightchildidx = 2 * idx + 1;
        if (leftchildidx <= size && arr[smallest] > arr[leftchildidx])
        {
            smallest = leftchildidx;
        }
        if (rightchildidx <= size && arr[smallest] > arr[rightchildidx])
        {
            smallest = rightchildidx;
        }
        if (smallest != idx)
        {
            swap(arr[smallest], arr[idx]);
            MinHeapify(smallest);
        }
    }

    void Heapsort()
    {
        int heapsize = size;
        while (heapsize > 1)
        {
            swap(arr[heapsize], arr[1]);
            heapsize--;
            MaxHeapify(1);
        }
    }

    void BuildMaxHeap()
    {
        for (int idx = size / 2; idx > 0; idx--)
        {
            MaxHeapify(idx);
        }
    }

    void BuildMinHeap()
    {
        for (int idx = size / 2; idx > 0; idx--)
        {
            MinHeapify(idx);
        }
    }
};

void display(int arr[], int size)
{
    cout << "Elements in the heap are : " << endl;
    for (int idx = 1; idx <= size; idx++)
    {
        cout << arr[idx] << " ";
    }
    cout << endl;
}

int main()
{
    int arr1[6] = {-1, 5, 2, 3, 8, 1};
    int n = 5;

    display(arr1, n);

    Heap maxHeap;
    maxHeap.size = n;
    for (int i = 1; i <= n; i++)
    {
        maxHeap.arr[i] = arr1[i];
    }

    maxHeap.BuildMaxHeap();

    cout << "Elements in the max heap are after building : " << endl;
    display(maxHeap.arr, n);

    maxHeap.Heapsort();

    cout << "Max Heap Sorting: " << endl;
    display(maxHeap.arr, n);

    Heap minHeap;
    minHeap.size = n;
    for (int i = 1; i <= n; i++)
    {
        minHeap.arr[i] = arr1[i];
    }

    minHeap.BuildMinHeap();

    cout << "Elements in the min heap are after building : " << endl;
    display(minHeap.arr, n);

    minHeap.Heapsort();

    cout << "Min Heap Sorting: " << endl;
    display(minHeap.arr, n);

    cout << endl;
    return 0;
}
