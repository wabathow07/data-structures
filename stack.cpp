/*
application:
- function calls: return addresses -> continue executions
- recursions: track local variables and states during nested recursive calls
- undo/redo operations
- syntax parsing
- memory management: support dynamic memory allocation and deallocation

is a LIFO list

stack operations: push(), pop(), pop(index), display(), peek(), isEmpty(), size()
*/

#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;

    Node(char d)
    {
        data = d;
        next = nullptr;
    }
};

class LinkedListStack
{
private:
    Node *top;
    int count;

public:
    LinkedListStack()
    {
        top = nullptr;
        count = 0;
    }

    void push(char x) // time complexity: O(1)
    {
        if (top == nullptr)
        {
            top = new Node(x);
        }
        else
        {
            Node *newNode = new Node(x);
            newNode->next = top;
            top = newNode;
        }

        cout << "Value " << x << " is at the top of the stack\n";
        count++;
    }

    void pop() // time complexity: O(1)
    {
        if (top == nullptr)
        {
            cout << "The stack is empty\n";
            return;
        }

        cout << "Value " << top->data << " is popped out of the stack\n";

        Node *temp = top;
        top = top->next;
        delete temp;
        count--;
    }

    void pop(int index) // time complexity: O(n)
    {
        if (index >= count || index < 0)
        {
            cout << "Invalid index\n";
            return;
        }

        for (int i = 0; i <= index; i++)
            pop();

        cout << "Current value at the top: " << top->data << "\n";
    }

    void display()
    {
        cout << "Stack from top to bottom: \n";
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << "\n";
            temp = temp->next;
        }
    }

    char peek() // time complexity: O(1)
    {
        if (top == nullptr)
        {
            cout << "Stack is empty\n";
            return '-';
        }
        return top->data;
    }

    bool isEmpty() { return top == nullptr; } // time complexity: O(1)

    int size() { return count; }
};

int main()
{
    LinkedListStack st;

    st.push('a');
    st.push('b');
    st.push('c');
    st.push('a');
    st.push('b');
    st.push('c');
    st.push('a');
    st.push('b');
    st.push('c');

    st.pop();
    st.display();

    st.pop(5);
    st.display();

    cout << "Data at the top: " << st.peek() << "\n";
    cout << "Stack size: " << st.size() << "\n";
}