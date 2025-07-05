#include<bits/stdc++.h>
using namespace std;

class MyCircularQueue {
private:
    vector<int> data;
    int front, rear, size, capacity;

public:
    MyCircularQueue(int k) {
        capacity = k;
        data.resize(k);
        front = 0;
        rear = 0;
        size = 0;
    }

    bool enQueue(int value) {
        if (isFull()) return false;
        data[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) return false;
        front = (front + 1) % capacity;
        size--;
        return true;
    }

    int Front() {
        if (isEmpty()) return -1;
        return data[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return data[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularQueue obj(3);
    
    cout << "enQueue(1): " << obj.enQueue(1) << endl;  // true
    cout << "enQueue(2): " << obj.enQueue(2) << endl;  // true
    cout << "enQueue(3): " << obj.enQueue(3) << endl;  // true
    cout << "enQueue(4): " << obj.enQueue(4) << endl;  // false (full)
    
    cout << "Rear: " << obj.Rear() << endl;            // 3
    cout << "isFull: " << obj.isFull() << endl;        // true
    
    cout << "deQueue: " << obj.deQueue() << endl;      // true
    cout << "enQueue(4): " << obj.enQueue(4) << endl;  // true
    cout << "Rear: " << obj.Rear() << endl;            // 4

    cout << "Front: " << obj.Front() << endl;          // 2
    cout << "isEmpty: " << obj.isEmpty() << endl;      // false

    return 0;
}