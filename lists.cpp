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

doubly linked list: insert(), delete(), search(), print()

type of linked lists: with dummy (sentinel), without dummy, circular

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
    ArrayList(int cap) // O(1)
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

    ~ArrayList() // O(1)
    {
        delete[] arr;
    }

    ArrayList(const ArrayList &a) // O(n)
    {
        this->capacity = a.capacity;
        this->top = a.top;
        this->arr = new int[capacity];

        for (int i = 0; i <= top; i++)
        {
            this->arr[i] = a.arr[i];
        }
    }

    void clear() // O(n)
    {
        delete[] arr;
        arr = new int[capacity];
        top = -1;
    }

    void insert(int x, int index) // O(n)
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

    void remove(int index) // O(n)
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

    int get(int index) // O(1)
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

    void update(int x, int index) // O(1)
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

    bool find(int x) // O(n)
    {
        for (int i = 0; i <= top; i++)
        {
            if (arr[i] == x)
                return true;
        }

        return false;
    }

    int length() // O(1)
    {
        return top + 1;
    }
};

ArrayList createList(int cap) // O(1)
{
    return ArrayList(cap);
}

struct Node
{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};

class LinkedList
{
private:
    Node *head;
    int top;

public:
    LinkedList() // O(1)
    {
        head = nullptr;
        top = -1;
    }

    ~LinkedList() // O(n)
    {
        while (head != nullptr)
        {
            Node *next = head->next;
            delete head;
            head = next;
        }
    }

    void get(int index) // O(n)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (index < 0 || index > top)
        {
            cout << "Invalid index\n";
            return;
        }
        Node *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }

    void deleteNode(int index) // O(n)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (index < 0 || index > top)
        {
            cout << "Invalid index\n";
            return;
        }
        if (index == 0)
        {
            Node *deleteNode = head;
            head = head->next;
            delete deleteNode;
            top--;
            return;
        }
        if (index == top)
        {
            Node *temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            Node *deleteNode = temp->next;
            temp->next = nullptr;
            delete deleteNode;
            top--;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }
        Node *deleteNode = temp->next;
        temp->next = temp->next->next;
        top--;
        delete deleteNode;
    }

    void insertNode(int x, int index) // O(n)
    {
        if (index > top + 1 || index < 0)
        {
            cout << "Invalid index\n";
            return;
        }
        if (head == nullptr)
        {
            head = new Node(x);
            top++;
            return;
        }
        if (index == 0)
        {
            Node *newNode = new Node(x);
            newNode->next = head;
            head = newNode;
            top++;
            return;
        }
        if (index == top + 1)
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(x);
            top++;
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index - 1; i++)
        {
            temp = temp->next;
        }

        Node *newNode = new Node(x);
        newNode->next = temp->next;
        temp->next = newNode;
        top++;
    }

    /* void makeCircular()
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }

        Node *temp = head;
        while (temp->next != nullptr)
            temp = temp->next;

        temp->next = head;

        temp = nullptr;
        delete temp;
    } */
};

struct DoublyNode
{
    int data;
    DoublyNode *prev;
    DoublyNode *next;

    DoublyNode(int d)
    {
        data = d;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    DoublyNode *head;
    int top;

public:
    DoublyLinkedList() // O(1)
    {
        head = nullptr;
        top = -1;
    }

    ~DoublyLinkedList() // O(n)
    {
        while (head != nullptr)
        {
            DoublyNode *next = head->next;
            delete head;
            head = next;
        }
    }

    void get(int index) // O(n)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (index < 0 || index > top)
        {
            cout << "Invalid index\n";
            return;
        }

        DoublyNode *temp = head;
        for (int i = 0; i < index; i++)
        {
            temp = temp->next;
        }
        cout << temp->data << "\n";
    }

    void deleteNode(int index) // O(n)
    {
        if (head == nullptr)
        {
            cout << "List is empty\n";
            return;
        }
        if (index < 0 || index > top)
        {
            cout << "Invalid index\n";
            return;
        }

        DoublyNode *nodeToDelete = head;
        for (int i = 0; i < index; i++)
        {
            nodeToDelete = nodeToDelete->next;
        }

        if (nodeToDelete->prev != nullptr)
        {
            nodeToDelete->prev->next = nodeToDelete->next;
        }
        else
        {
            head = nodeToDelete->next;
        }

        if (nodeToDelete->next != nullptr)
        {
            nodeToDelete->next->prev = nodeToDelete->prev;
        }

        delete nodeToDelete;
        top--;
    }

    void insertNode(int x, int index) // O(n)
    {
        if (index < 0 || index > top + 1)
        {
            cout << "Invalid index\n";
            return;
        }

        DoublyNode *newNode = new DoublyNode(x);
        if (index == 0)
        {
            newNode->next = head;
            if (head != nullptr)
            {
                head->prev = newNode;
            }
            head = newNode;
        }
        else
        {
            DoublyNode *temp = head;
            for (int i = 0; i < index - 1; i++)
            {
                temp = temp->next;
            }

            newNode->next = temp->next;
            newNode->prev = temp;
            if (temp->next != nullptr)
            {
                temp->next->prev = newNode;
            }
            temp->next = newNode;
        }

        top++;
    }
};