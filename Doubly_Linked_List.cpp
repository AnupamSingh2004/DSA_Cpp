#include <bits/stdc++.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node* back;

    Node(){
        this->data = 0;
        this->next = NULL;
        this->back = NULL;
    }

    Node(int data){
        this->data = data;      
        this->next = NULL;
        this->back = NULL;
    }

    Node(int data,Node* next,Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }
};

Node* convertToDLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1;i < arr.size(); i++){
        Node* temp = new Node(arr[i],NULL,prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

Node* deleteHead(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }
    Node* prev = head;
    head = head->next;
    head->back = NULL;
    prev->next = NULL;
    delete prev;

    return head;
}


Node* deleteTail(Node* head){
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    Node* tail = head;

    while(tail->next != NULL){
        tail = tail->next;
    }

    Node* prev = tail->back;
    prev->next = NULL;
    tail->next = NULL;

    delete tail;

    return head;
}


Node* removeKthElement(Node* head,int k){
    if(head == NULL) return NULL;

    int count = 0;
    Node* kNode = head;

    while(kNode != NULL){
        count++;
        if(count == k) break;
        kNode = kNode->next;
    }

    Node* prev = kNode->back;
    Node* front = kNode->next;

    if(prev == NULL && front == NULL){
        return NULL;
    }else if(prev == NULL){
        return deleteHead(head);
    }else if(front == NULL){
        return deleteTail(head);
    }

    prev->next = front;
    front->back = prev;
    kNode->next = NULL;
    kNode->back = NULL;

    delete kNode;

    return head;
}

Node* insertBeforeHead(Node* head,int value){
    Node* newHead = new Node(value,head,NULL);
    head->back = newHead;
    return newHead;
}

Node* insertBeforeTail(Node* head,int value){
    if(head->next == NULL){
        return insertBeforeHead(head,value);
    }

    Node* temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }

    Node* prev = temp->back;

    Node* newNode = new Node(value,temp,prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}


Node* insertBeforeKthElement(Node* head,int k, int value){
    if(k == 1){
        return insertBeforeHead(head,value);
    }

    int count = 0;
    Node* temp = head;
    
    while(temp != NULL){
        count++;
        if(count == k) break;
        temp = temp->next;
    }

    Node* prev = temp->back;
    Node* newNode = new Node(value,temp,prev);
    
    prev->next = newNode;
    temp->back = newNode;

    return head;
}


Node* insertBeforeNode(Node* node,int value){
    Node* prev = node->back;
    Node* newNode = new Node(value,node,prev);
    prev->next = newNode;
    node->back = newNode;
}

void printList(Node* head){
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    
}

int main(){

     vector<int> arr = {2, 5, 8, 10};

    Node* head = convertToDLL(arr);

    head = removeKthElement(head,3);

    head = insertBeforeTail(head,100);

    head = insertBeforeKthElement(head,3,1000);

    insertBeforeNode(head->next->next,8423);

    printList(head);
    return 0;
}