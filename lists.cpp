#include<iostream>
using namespace std;

class Lists {
private:
    int arr[10000];
    int top = -1;

public:
    Lists() {}

    void copy(Lists a) {
        if (a.top == -1) {
            cout << "Nothing to copy\n";
            return;
        } else {
            for (int i = 0; i <= a.top; i++) {
                arr[i] = a.arr[i];
            }
        }
    }

    void clear() {top = -1; return;}

    void insertX(int x, int ind) {
        if (top == 9999) {
            cout << "List is full\n";
            return;
        } 

        for (int i = top+1; i >= ind; i--) {
            arr[i] = arr[i-1];
        }

        arr[ind] = x; top++;
    }

    void remove(int ind) {
        if (top == -1) {
            cout << "List is empty\n";
            return;
        }

        for (int i = ind; i < top; i++) {
            arr[i] = arr[i+1];
        }

        top--;
    }

    void get(int ind) {
        if (top == -1) {
            cout << "List is empty\n";
            return;
        } else if (top < ind) {
            cout << "No element at this index\n";
            return;
        } else cout << "Element at this index: " << arr[ind] << "\n";
    }

    void update(int x, int ind) {
        if (top == -1) {
            cout << "List is empty\n";
            return;
        } else if (top < ind) {
            cout << "No element at this index\n";
        } else arr[ind] = x;
    }

    bool find(int x) {
        for (int i = 0; i <= top; i++) {
            if (arr[i] == x) return true;
        }

        return false;
    }

    int length() {return top;}

    void display() {
        for (int i = 0; i <= top; i++) cout << arr[i] << " ";
    }
};

void createList() {
    Lists a;
}

int main() {
    Lists a;

    a.insertX(10, 0);
    a.display();

    return 0;
}