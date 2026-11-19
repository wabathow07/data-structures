/*
Non-recursive/Incremental comparison sorting:
- Selection sort
- Bubble sort
- Insertion sort
Recursive comparison sorting:
- Merge sort
- Quick sort
- Heap sort
Non-comparison linear sorting:
- Count sort
- Radix sort
- Bucket sort
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

template <typename T>
void selection(vector<T> &a)
{
    T n = a.size();

    for (int i = 0; i < n - 1; ++i)
    {
        T minIndex = i;

        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[minIndex])
            {
                minIndex = j;
            }
        }

        if (minIndex != i)
        {
            swap(a[i], a[minIndex]);
        }
    }
}
/*
how it works: set the first element as the smallest, then find the smallest number in the rest and swap their places, repeat

time complexity: O(n²)

pseudocode:
for i = 0 to length(A) - 2 do
    minIndex = i
    for j = i + 1 to length(A) - 1 do
        if A[j] < A[minIndex] then
            minIndex = j
        end if
    end for
    if minIndex != i then
        swap A[i] with A[minIndex]
    end if
end for
*/

template <typename T>
void bubbleSort(vector<T> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

/*
how it works: larger value elements "bubble up" to the top

time complexity: O(n²)

pseudocode:
n = length(A)
for i from 0 to n - 2 do
    for j from 0 to n - i - 2 do
        if a[j] > a[j + 1] then
            swap the 2 elements
        end if
    end for
end for
*/

template <typename T>
void insertion(vector<T> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        T t = a[i];
        int j;
        for (j = i - 1; j >= 0 && t < a[j]; j--)
        {
            cout << t << " is looking to be inserted...\n";
            a[j + 1] = a[j];
            a[j] = t;
        }
        cout << t << " is inserted at " << j + 1 << "\n";
    }
}

/*
how it works: first loop chooses the index, second loop find the current smallest element and insert it into said index

time complexity: O(n²)

pseudocode:
for i = 1 to length(A) - 1
    key = A[i]
    j = i - 1
    while j >= 0 and A[j] > key
        A[j + 1] = A[j]
        j = j - 1
    A[j + 1] = key
}
*/

template <typename T>
void merge(vector<T> &a, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<T> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[left + i];
    }

    for (int i = 0; i < n2; i++)
    {
        R[i] = a[mid + i + 1];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] < R[j])
        {
            a[k] = L[i];
            k++;
            i++;
        }
        else
        {
            a[k] = R[j];
            k++;
            j++;
        }
    }

    while (i < n1)
    {
        a[k] = L[i];
        k++;
        i++;
    }

    while (j < n2)
    {
        a[k] = R[j];
        k++;
        j++;
    }
}

template <typename T>
void mergeSort(vector<T> &a, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(a, left, mid);
    mergeSort(a, mid + 1, right);
    merge(a, left, mid, right);
}

/*
how it works: Order a list of values by recursively dividing the list in half until each sub-list has one element, then recombining
- divide: n element sequence to be sorted into two subsequences of n/2 elements each
- conquer: sort the two subsequences to produce the sorted answer
- combine: merge the two sorted sub sequences to produce the sorted answer

time complexity: O(n.log2(n))

advantage: extremely fast
disadvantage: require a second array with the same size
*/

int main()
{
    vector<int> a = {20, 10, 30, 50, 100, 99, 60, 11};
    int n = a.size();
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << "\n";

    vector<double> b = {2.11, 1.12, 3.14, 3.56, 7.12, 9.11, 8.50};
    int m = b.size();
    bubbleSort(b);
    for (auto x : b)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}
