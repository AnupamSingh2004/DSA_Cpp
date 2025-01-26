#include<bits/stdc++.h>

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
		cout << temp->data << " ";
		temp = temp->next;

	}
}

int main(){

	Node* first = new Node();
	Node* second = new Node();
	Node* third = new Node();

	first->next = second;
	second->next = third;

	printList(first);

	return 0;
}