#include <iostream>
#include <stack>
using namespace std;

// Insert element into the sorted stack
void insertSorted(stack<int> &st, int element) {
    if (st.empty() || element > st.top()) {
        st.push(element);
        return;
    }
    int top = st.top();
    st.pop();
    insertSorted(st, element);
    st.push(top);
}

// Sort the stack recursively
void sortStack(stack<int> &st) {
    if (st.empty()) return;
    int top = st.top();
    st.pop();
    sortStack(st);
    insertSorted(st, top);
}

int main() {
    stack<int> st;
    st.push(34);
    st.push(3);
    st.push(31);
    st.push(98);
    st.push(92);
    st.push(23);

    sortStack(st);

    cout << "Sorted stack (top to bottom): ";
    while (!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
