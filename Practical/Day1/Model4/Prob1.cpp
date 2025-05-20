#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
private:
    int arr[SIZE];
    int front = 0;
    int rear = -1;
    int count = 0;

public:
    bool isEmpty() {
        return count == 0;
    }

    bool isFull() {
        return count == SIZE;
    }

    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full\n";
            return;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        count++;
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % SIZE;
        count--;
        return val;
    }

    int size() {
        return count;
    }

    void display() {
        cout << "Queue: ";
        for (int i = 0; i < count; i++) {
            int idx = (front + i) % SIZE;
            cout << arr[idx] << " ";
        }
        cout << endl;
    }
    void reverseLastK(int k) {
        if (k <= 0 || k > count) {
            cout << "Invalid value of k\n";
            return;
        }
        int temp[SIZE];
        for (int i = 0; i < count; i++) {
            temp[i] = arr[(front + i) % SIZE];
        }
        int start = count - k, end = count - 1;
        while (start < end) {
            swap(temp[start], temp[end]);
            start++;
            end--;
        }
        for (int i = 0; i < count; i++) {
            arr[(front + i) % SIZE] = temp[i];
        }
    }
};

int main() {
    Queue q;
    for (int i = 1; i <= 8; i++) {
        q.enqueue(i);
    }
    cout << "Before reversing last 4 elements:\n";
    q.display();
    q.reverseLastK(4);
    cout << "After reversing last 4 elements:\n";
    q.display();
    return 0;
}
