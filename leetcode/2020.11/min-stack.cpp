#include <bits/stdc++.h>

using namespace std;

class MinStack {
private:
    int capacity = 16;
    int pos = 0;
    int* cont;
    int* minCont;
public:
    /** initialize your data structure here. */
    MinStack() {
        cont = new int[capacity];
        minCont = new int[capacity];
    }

    void push(int x) {
        if (pos >= capacity - 1) {
            resize(capacity * 2);
        }

        int minIdx = 0;
        if (pos > 0) {
            if(getMin() > x) {
                minIdx = pos;
            } else {
                minIdx = minCont[pos-1];
            }
        }

        cont[pos] = x;
        minCont[pos] = minIdx;
        pos++;
    }

    void pop() {
        if(pos == 0) return;
        pos--;
    }

    int top() {
        return cont[pos-1];
    }

    int getMin() {
        return cont[minCont[pos-1]];
    }

    void resize(int sz) {
        int* newCont = new int[sz];
        memcpy(newCont, cont, sizeof(int) * capacity);
        delete cont;
        cont = newCont;

        int* newMinCont = new int[sz];
        memcpy(newMinCont, minCont, sizeof(int) * capacity);
        delete minCont;
        minCont = newMinCont;

        capacity = sz;
    }

    void debug() {
        for(int i = 0; i < pos; ++i) {
            cout << minCont[i] << ", ";
        }
        cout << "\n";
    }
};

int main() {

    MinStack ms;
    ms.push(2);
    ms.push(0);
    ms.push(3);
    ms.push(0);

    ms.debug();

    cout << ms.getMin() << "\n";
    ms.pop();
    cout << ms.getMin() << "\n";
    ms.pop();
    cout << ms.getMin() << "\n";
    ms.pop();
    cout << ms.getMin() << "\n";

    return 0;
}