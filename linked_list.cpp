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


Node* convertArrToLL(vector<int>& arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    
    return head;

}

int lenghtOfLL(Node* head){
    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    
    return count;
}

bool checkIfPresent(Node* head, int value){
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == value)
        {
            return true;
        }
        temp = temp->next;
    }

    return false;
    
}

Node* removeHead(Node* head){
    if (head == NULL)
    {
        return head;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    return head;
    
}


int main(){

    vector<int> arr = {2, 5, 8, 10};

    Node* head = convertArrToLL(arr);

    cout << lenghtOfLL(head) << endl;

    cout << (checkIfPresent(head,8) ? "Present" : "Not Present" )<< endl;

    printList(head);    

}