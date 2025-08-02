#include<bits/stdc++.h>
using namespace std;

// structure data structue 
struct Node{
    int data;
    Node* next;
    // Constructors
    Node(): data(0), next(nullptr) {}
    Node(int x): data(x), next(nullptr) {}
    Node(int x, Node* next): data(x), next(next) {}
};

// insert node at end
void insertAtEnd(Node*& head, int value){
  Node* newNode = new Node(value);  // we created the node of Value
  Node*temp = head;  // temporary use
    if(head == nullptr){
        head = newNode;
    }
    else{
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
    }
}

// Search Element
int searchElm(Node*head, int value){
    Node*temp = head;
    int cnt=0;
    while(temp!=nullptr){
        cnt++;
        if(temp->data == value){
            return cnt;
        }
        temp= temp->next;
    }
    return 0;
}

// display list
void displayList(Node*& head){
    Node* temp = head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main(){
   Node* head = nullptr;
   insertAtEnd(head, 5);
   insertAtEnd(head, 10);
   insertAtEnd(head, 15);

   displayList(head);
   
   int index = searchElm(head, 15);
   cout<<index;
}
