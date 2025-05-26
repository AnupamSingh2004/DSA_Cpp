#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(){
        this->data = 0;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void printList(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }
}


void insertAtHead(Node* &head,Node* &tail, int data){
    Node* newNode = new Node(data);

    newNode->next = head;

    

    if (head == NULL)
    {
        tail = newNode;
    }
    
    head = newNode;
}

void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);
    if (head == NULL) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

int main(){

    // Node* first = new Node(10);
    // Node* second = new Node(20);

    // first->next = second;

    // printList(first);

    Node* head = new Node();
    Node* tail = new Node();

    insertAtHead(head,tail, 30);
    insertAtHead(head,tail, 10);
    insertAtHead(head,tail, 50);



    insertAtTail(head,tail,20);
    insertAtTail(head,tail,5);


    printList(head);

    cout << endl;

    printList(tail);

}