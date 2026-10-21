#include<iostream>
#include<vector>
using namespace std;

void insertion(vector<int>& a) {
    int n = a.size();
    for (int i = 1; i < n; i++) {
        int t = a[i];
        int j;
        for (j = i-1; j >= 0 && t < a[j]; j--) {
            cout << t << " is looking to be inserted...\n";
            a[j+1] = a[j];
            a[j] = t;
        }
        cout << t << " is inserted at " << j+1 << "\n";
    }
}

void selection(vector<int>& a) {
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int t = a[i];
        int j; 
        int minValue = t;
        for (j = i+1; j < n; j++) {
            if (a[j] < minValue) {
                minValue = a[j];
                cout << "Current smallest value: " << a[j] << "\n";
            }
        }
        cout << "Switched " << t << " with " << minValue << "\n";
        a[i] = a[j];
        a[j] = t;
    }
}

int main() {
    vector<int> a = {20, 10, 30, 50, 100, 99, 60, 11};
    selection(a);
    for (auto x : a) cout << x << " ";
    cout << "\n";



    return 0;
}