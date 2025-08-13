#include <iostream>
using namespace std;

class Stack {
private:
    int top;        // index of top element
    int capacity;   // maximum size of stack
    int* arr;       // array to store elements

public:
    // Constructor
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        top = -1; // stack is empty
    }

    // Destructor
    ~Stack() {
        delete[] arr;
    }

    // Check if stack is empty
    bool isEmpty() {
        return top == -1;
    }

    // Check if stack is full
    bool isFull() {
        return top == capacity - 1;
    }

    // Push element onto stack
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        arr[++top] = value;
        cout << value << " pushed into stack." << endl;
    }

    // Pop element from stack
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
            return;
        }
        cout << arr[top--] << " popped from stack." << endl;
    }

    // Peek top element
    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return -1; // error value
        }
        return arr[top];
    }
};

int main() {
    Stack s(5); // stack of size 5

    s.push(10);
    s.push(20);
    s.push(30);

    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop(); // will show underflow

    return 0;
}
