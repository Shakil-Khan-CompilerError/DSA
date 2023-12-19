#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i)
{
    int largest = i;
    int leftchild = 2 * i + 1;
    int rightchild = 2 * i + 2;

    if (leftchild < n && arr[largest] < arr[leftchild])
        largest = leftchild;

    if (rightchild < n && arr[largest] < arr[rightchild])
        largest = rightchild;

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n)
{
    int size = n-1;
    while(size > 0)
    {
        swap(arr[0], arr[size]);
        heapify(arr, size, 0);
        size--;
    }
}
int main()
{
    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int start = (n / 2) - 1;
    for (int i = start; i >= 0; i--)
        heapify(arr, n, i);

    cout << "Max Heap-->\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    heapsort(arr, n);

    cout << "Sorted array --->\n";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
}
