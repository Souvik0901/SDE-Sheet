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
int searchElm(Node*& head, int value){
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

void reverseLL(Node*& head){
    Node *prev = nullptr; 
    Node *current = head;
    Node *next = nullptr;

    while(current!=nullptr){
        next= current->next; // stored current's next in 'next'
        current-> next = prev; // changes current's next to prev
        prev = current;   // upgrade 1 index to prev 
        current = next;  // upgrade 1 index to Current
    }
    head= prev;
}

int midleelem(Node*& head){
    Node* temp = head;
    int n =0;
    while(temp!= nullptr){
        n++;
        temp= temp->next;
    }
    for(int i=0; i<n/2; i++){
        head= head->next;
    }
    return head->data;
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
   insertAtEnd(head, 23);
   insertAtEnd(head, 45);

   cout<<"Inserted Elements :";
   displayList(head);
   
   int index = searchElm(head, 15);
   cout<<"\nSearch Element: "<<index;
   
   reverseLL(head);
   cout<<"\nReversed LL: ";
   displayList(head);
   
   
   cout<<"\nMiddle Elm: "<<midleelem(head);
   
}


