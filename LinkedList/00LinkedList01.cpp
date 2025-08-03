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

// Function to reverse the linkedlist
void reverseLL(Node*& head){
    Node *prev = nullptr;
    Node *current = head;
    Node *next = nullptr;

    while(current!=nullptr){
        next= current->next; // stored current's next in 'next'
        current-> next = prev; // changes current's next to prev
        prev = current;
        current = next;
    }
    head= prev;
}

//Function to finding middle element
int midleelem(Node*& head){
    Node* temp = head;
    Node* temp1 = head;
    int n =0;
    while(temp!= nullptr){
        n++;
        temp= temp->next;
    }
    temp =head;
    for(int i=0; i<n/2; i++){
        temp= temp->next;
    }
    return temp->data;
}

//Merge Two Lists
Node* mergeTwoList(Node* l1, Node* l2){
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    
    if(l1->data <= l2->data){
        l1->next = mergeTwoList(l1->next, l2);
        return l1;
    }
    else {
        l2->next = mergeTwoList(l1, l2->next);
        return l2;
    }
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
   
   Node* newlist = nullptr;
   insertAtEnd(newlist, 12);
   insertAtEnd(newlist, 15);
   insertAtEnd(newlist, 19);
   

   cout<<"Inserted Elements :";
   displayList(head);
   
  int index = searchElm(head, 15);
  cout<<"\nSearch Element: "<<index;
   
//   reverseLL(head);
//   cout<<"\nReversed LL: ";
//   displayList(head);
   
  cout<<"\nMiddle Elm: "<<midleelem(head);
   
   Node* mergedHead = mergeTwoList(head, newlist);
   cout << "\nMerged List: ";
   displayList(mergedHead);
   cout << endl;
}


