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

    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }
};

void printList(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << endl;
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

Node* removeTail(Node* head){
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    
    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;

    temp->next = NULL;

    return head;
    
}


Node* removeK(Node* head, int k){
    if (head == NULL)
    {
        return head;
    }
    if (k == 1)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    
    return head;
    
    
}


Node* removeElement(Node* head, int element){
    if (head == NULL)
    {
        return head;
    }
    if (head->data == element)
    {
        Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    int count = 0;
    Node* temp = head;
    Node* prev = NULL;

    while (temp != NULL)
    {
        count++;
        if (temp->data == element)
        {
            prev->next = prev->next->next;
            free(temp);
            break;
        }

        prev = temp;
        temp = temp->next;
    }
    
    return head; 
}

Node* insertHead(Node* head,int data){
    Node* temp = new Node(data,head);
    return temp;
}

Node* insertTail(Node* head, int data){
    if(head == NULL) return new Node(data);

    Node* temp = head;

    while(temp->next != NULL){
        temp = temp->next;
    }

    Node* newNode = new Node(data);

    temp->next = newNode;

    return head;

}

Node* insertAtK(Node* head,int element, int k){
    if(head == NULL){
        if (k == 1)
        {
            return new Node(element);
        }else{
            return NULL;
        }
    }

    if (k == 1)
    {
        Node* temp = new Node(element);
        temp->next = head;
        return temp;
    }

    int count = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node* x = new Node(element);
            x->next = temp->next;
            temp->next = x;
            break;
        }

        temp = temp->next;
    }

    return head;
}


int main(){

    vector<int> arr = {2, 5, 8, 10};

    Node* head = convertArrToLL(arr);

    cout << lenghtOfLL(head) << endl;

    head = removeHead(head);

    cout << (checkIfPresent(head,8) ? "Present" : "Not Present" )<< endl;

    printList(head);    

    vector<int> arr2 = {2,5,7,7,4,25,56};

    Node* head2 = convertArrToLL(arr2);

    head2 = removeTail(head2);

    head2 = removeK( head2, 2);

   head2 = insertAtK(head2,100,1);

    printList(head2);

}