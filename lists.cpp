/*
array

dynamic array: int* arr = new int[20] -> use when you don't know the size at compile time

list: collection of items of same type, stored in some particular order
list operations: 
- createList(): create a new list (presumably empty)
- copy(): set one list to be a copy of another
- clear(); clear a list (remove all elments)
- insert(int index, int x): Insert element x at a particular position in the list
- remove(int index): Remove element at some position in the list
- get(int index): Get element at a given position
- update(int x, int index): replace the element at a given position with X
- find(int x): determine if the element X is in the list
- length(): return the length of the list.

to traverse in a list, we need to use iterations (ignore the shits he wrote in the slide it's for python):
    for (it = data.begin(); it != data.end(); ++it) {
        std::cout<<(*it)->name;
    }

linear list operations: isEmpty(), length(), retrieve(int index), indexOf(int x), delete(int index), insert(int index, int x)
*/

#include <iostream>
using namespace std;

class ArrayList
{
private:
    int *arr;
    int capacity;
    int top;

public:
    ArrayList(int cap)
    {
        if (cap < 0)
        {
            cout << "Invalid capacity. Setting capacity to 0\n";
            cap = 0;
        }
        capacity = cap;
        arr = new int[capacity];
        top = -1;
    }

    ~ArrayList() { delete[] arr; }

    ArrayList(const ArrayList &a)
    {
        this->capacity = a.capacity;
        this->top = a.top;
        this->arr = new int[capacity];

        for (int i = 0; i <= top; i++)
        {
            this->arr[i] = a.arr[i];
        }
    }

    void clear()
    {
        delete[] arr;
        arr = new int[capacity];
        top = -1;
    }

    void insert(int x, int index)
    {
        if (index > length() || index < 0)
        {
            cout << "Invalid index\n";
            return;
        }

        if (length() == capacity)
        {
            cout << "List is full\n";
            return;
        }

        for (int i = top + 1; i > index; i--)
        {
            arr[i] = arr[i - 1];
        }

        arr[index] = x;
        top++;
    }

    void remove(int index)
    {
        if (index > top || index < 0)
        {
            cout << "Invalid index\n";
            return;
        }

        if (top == -1)
        {
            cout << "List is empty\n";
            return;
        }

        for (int i = index; i < top; i++)
        {
            arr[i] = arr[i + 1];
        }
        top--;
    }

    int get(int index)
    {
        if (index > top || index < 0)
        {
            cout << "Invalid index\n";
            return -1;
        }

        if (top == -1)
        {
            cout << "List is empty\n";
            return -1;
        }

        return arr[index];
    }

    void update(int x, int index)
    {
        if (index > top || index < 0)
        {
            cout << "Invalid index\n";
            return;
        }

        if (top == -1)
        {
            cout << "List is empty\n";
            return;
        }

        arr[index] = x;
    }

    bool find(int x)
    {
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == x)
                return true;
        }

        return false;
    }

    int length() { return top + 1; }
};

ArrayList createList(int cap)
{
    return ArrayList(cap);
}
