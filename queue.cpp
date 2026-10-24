/*
- is a linear list/data structure
- one end is called front, the other end is called rear
- removals are only made from the front

- queue operations: isFull(), isEmpty(), enqueue(), dequeue()
*/

/*Pham Anh Tho (1143568) - Chen Si-en (1143725) - Source code
This file includes queue implementations using normal array, linked-list, and circular array*/
#include <iostream>
using namespace std;

class QueueNormalArray
{
private:
    int *arr;
    int capacity;
    int rear;

public:
    QueueNormalArray(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        rear = -1;
    }

    ~QueueNormalArray() { delete[] arr; }

    void enqueueJob(int x)
    {
        if (rear == capacity - 1)
        {
            cout << "Queue is full\n";
            return;
        }
        else
        {
            cout << "Job " << x << " added\n";
            arr[++rear] = x;
        }
    }

    void accessQueueJobs(int index)
    {
        if (index > rear)
        {
            cout << "No job available\n";
            return;
        }
        else if (index < 0)
        {
            cout << "Invalid index\n";
            return;
        }
        else
        {
            cout << "Job at index " << index << " is " << arr[index] << "\n";
        }
    }

    void dequeueJob()
    {
        if (rear == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        else if (rear == 0)
        {
            rear = -1;
            return;
        }
        else
        {
            for (int i = 1; i <= rear; i++)
            {
                arr[i - 1] = arr[i];
            }
            rear--;
        }
    }

    int searchJob(int job)
    {
        for (int i = 0; i <= rear; i++)
        {
            if (arr[i] == job)
            {
                cout << "Job " << job << " found at index " << i << "\n";
                return i;
            }
        }
        cout << "Job not found\n";
        return -1;
    }

    int size() { return rear + 1; }

    bool isEmpty()
    {
        if (rear == -1)
            return true;
        else
            return false;
    }

    bool isFull()
    {
        if (rear == capacity - 1)
            return true;
        else
            return false;
    }

    void changeFront(int x)
    {
        if (rear == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        else
            arr[0] = x;
    }

    void changeBack(int x)
    {
        if (rear == -1)
        {
            cout << "Queue is empty\n";
            return;
        }
        else
            arr[rear] = x;
    }

    void displayAllJobs()
    {
        cout << "All current jobs: ";
        for (int i = 0; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
};

class QueueCircularArray
{
private:
    int *arr;
    int front;
    int size;
    int capacity;

public:
    QueueCircularArray(int cap)
    {
        capacity = cap;
        arr = new int[capacity];
        front = 0;
        size = 0;
    }

    ~QueueCircularArray() { delete[] arr; }

    void enqueueJob(int x)
    {
        if (size == capacity)
        {
            cout << "Queue is full\n";
            return;
        }
        int rear = (front + size) % capacity;
        arr[rear] = x;
        size++;
        cout << "New job added\n";
    }

    void dequeueJob()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }
        front = (front + 1) % capacity;
        size--;
        cout << "Job remove completed\n";
    }

    int searchJob(int job)
    {
        for (int i = 0; i < size; i++)
        {
            if (arr[(front + i) % capacity] == job)
            {
                cout << "Job " << job << " found at index " << i << "\n";
                return i;
            }
        }
        cout << "Job not found\n";
        return -1;
    }

    void insertJob(int job, int index)
    {
        if (size == capacity)
        {
            cout << "Queue is full\n";
            return;
        }
        if (index < 0 || index > size)
        {
            cout << "Invalid index\n";
            return;
        }

        for (int i = size; i > index; i--)
            arr[(front + i) % capacity] = arr[(front + i - 1) % capacity];

        arr[(front + index) % capacity] = job;
        size++;

        cout << "Job " << job << " is inserted at index " << index << "\n";
    }

    void cancelJob(int job)
    {
        int index = -1;
        for (int i = 0; i < size; i++)
        {
            if (arr[(front + i) % capacity] == job)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            cout << "Job not found\n";
            return;
        }

        for (int i = index; i < size - 1; i++)
            arr[(front + i) % capacity] = arr[(front + i + 1) % capacity];
        size--;
    }

    bool isEmpty()
    {
        if (size == 0)
            return true;
        else
            return false;
    }

    bool isFull() { return size == capacity; }

    int queueSize() { return size; }

    void displayAllJobs()
    {
        cout << "All current jobs: ";
        for (int i = 0; i < size; i++)
        {
            cout << arr[(front + i) % capacity] << " ";
        }
        cout << "\n";
    }
};

struct Node
{
    int data;
    Node *next;
};

class QueueLinkedList
{
private:
    Node *head;
    Node *tail;
    int size;
    int capacity;

public:
    QueueLinkedList(int cap)
    {
        capacity = cap;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~QueueLinkedList()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueueJob(int x)
    {
        if (size == capacity)
        {
            cout << "Queue is full\n";
            return;
        }

        Node *newNode = new Node;
        newNode->data = x;
        newNode->next = nullptr;

        if (head == nullptr)
        {
            head = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
        cout << "New job added\n";
    }

    void accessQueueJobs(int index)
    {
        if (index < 0)
        {
            cout << "Invalid index\n";
            return;
        }
        if (index >= size)
        {
            cout << "No job available\n";
            return;
        }

        Node *temp = head;
        for (int i = 0; i < index; i++)
            temp = temp->next;

        cout << "Job at index " << index << " is " << temp->data << "\n";
    }

    void dequeueJob()
    {
        if (size == 0)
        {
            cout << "Queue is empty\n";
            return;
        }

        Node *temp = head;
        head = head->next;
        if (head == nullptr)
            tail = nullptr;
        delete temp;
        size--;

        cout << "Job remove completed\n";
    }

    int searchJob(int job)
    {
        Node *temp = head;
        int index = 0;
        while (temp != nullptr)
        {
            if (temp->data == job)
            {
                cout << "Job " << job << " found at index " << index << "\n";
                return index;
            }
            temp = temp->next;
            index++;
        }
        cout << "Job not found\n";
        return -1;
    }

    void insertJob(int job, int index)
    {
        if (size == capacity)
        {
            cout << "Queue is full\n";
            return;
        }
        if (index < 0 || index > size)
        {
            cout << "Invalid index\n";
            return;
        }

        Node *newNode = new Node;
        newNode->data = job;

        if (index == 0)
        {
            newNode->next = head;
            head = newNode;
            if (size == 0)
                tail = newNode;
        }
        else
        {
            Node *prev = head;
            for (int i = 0; i < index - 1; i++)
                prev = prev->next;

            newNode->next = prev->next;
            prev->next = newNode;
            if (newNode->next == nullptr)
                tail = newNode;
        }
        size++;

        cout << "Job " << job << " is inserted at index " << index << "\n";
    }

    void cancelJob(int job)
    {
        Node *prev = nullptr;
        Node *cur = head;

        while (cur != nullptr && cur->data != job)
        {
            prev = cur;
            cur = cur->next;
        }

        if (cur == nullptr)
        {
            cout << "Job not found\n";
            return;
        }

        if (prev == nullptr)
            head = cur->next;
        else
            prev->next = cur->next;

        if (cur == tail)
            tail = prev;

        delete cur;
        size--;
    }

    bool isEmpty()
    {
        return size == 0;
    }

    bool isFull() { return size == capacity; }

    int queueSize() { return size; }

    void displayAllJobs()
    {
        cout << "All current jobs: ";
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main()
{
    // check queue implementations using circular array
    QueueCircularArray a(10);
    a.enqueueJob(1);
    a.enqueueJob(2);
    a.displayAllJobs();

    a.cancelJob(2);
    a.displayAllJobs();

    a.enqueueJob(3);
    a.dequeueJob();
    a.displayAllJobs();

    a.searchJob(1);

    if (a.isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    cout << "Size of queue: " << a.queueSize() << "\n";

    cout << "\n";

    // check queue implementations using normal array
    QueueNormalArray b(10);
    b.enqueueJob(1);
    b.enqueueJob(2);
    b.enqueueJob(3);
    b.displayAllJobs();

    b.accessQueueJobs(1);

    b.dequeueJob();
    b.displayAllJobs();

    b.changeBack(5);
    b.changeFront(4);
    b.displayAllJobs();

    b.searchJob(2);

    if (b.isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    cout << "Size of queue: " << b.size() << "\n";

    cout << "\n";

    // check queue implementations using linked list
    QueueLinkedList c(10);
    c.enqueueJob(1);
    c.enqueueJob(2);
    c.displayAllJobs();

    c.cancelJob(2);
    c.displayAllJobs();

    c.enqueueJob(3);
    c.dequeueJob();
    c.displayAllJobs();

    c.insertJob(9, 0);
    c.displayAllJobs();

    c.searchJob(3);

    cout << (c.isEmpty() ? "Queue is empty\n" : "Queue is not empty\n");
    cout << "Size of queue: " << c.queueSize() << "\n";

    return 0;
}
