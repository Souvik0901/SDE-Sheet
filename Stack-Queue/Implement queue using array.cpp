#include <iostream>
using namespace std;

class Queue {
private:
    int front, rear, size;
    int* arr;

public:
    // Constructor
    Queue(int capacity) {
        size = capacity;
        arr = new int[size];
        front = 0;
        rear = -1;
    }

    // Destructor
    ~Queue() {
        delete[] arr;
    }

    // Check if queue is full
    bool isFull() {
        return rear == size - 1;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front > rear;
    }

    // Add element to queue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
            return;
        }
        rear++;
        arr[rear] = value;
        cout << value << " enqueued." << endl;
    }

    // Remove element from queue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << arr[front] << " dequeued." << endl;
        front++;
    }

    // Display queue elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

// Main function
int main() {
    Queue q(5);

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.display();

    q.dequeue();
    q.display();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Will be full here
    q.display();

    return 0;
}
