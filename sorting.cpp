#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void insertion(vector<int> &a)
{
    int n = a.size();
    for (int i = 1; i < n; i++)
    {
        int t = a[i];
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

void selection(vector<int> &a)
{
    int n = a.size();

    for (int i = 0; i < n - 1; ++i)
    {
        int minIndex = i;

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

void bubbleSort(vector<int> &a)
{
    int n = a.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
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

int main()
{
    vector<int> a = {20, 10, 30, 50, 100, 99, 60, 11};
    bubbleSort(a);
    for (auto x : a)
    {
        cout << x << " ";
    }
    cout << "\n";
    return 0;
}