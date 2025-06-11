#include<bits/stdc++.h>

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


Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* current = head;

    while(current != NULL){
            prev = current->back;
            current->back = current->next;
            current->next = prev;
            current = current->back;
    }

    return prev->back;
};


void printList(Node* head){
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    
    cout << endl;
}

int main(){

    vector<int> arr = {2, 5, 8, 10};

    Node* head = convertToDLL(arr);
    
    printList(head);
    
    head = reverseDLL(head);

    printList(head);

}