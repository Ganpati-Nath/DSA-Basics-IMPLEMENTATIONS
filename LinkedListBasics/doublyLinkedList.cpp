#include <bits/stdc++.h>

using namespace std;

class Node{

    public:

        int data;
        Node* prev;
        Node* next;

        Node(int data){

            this->data = data;
            this->prev = NULL;
            this->next = NULL;

        }

        ~Node(){

            cout << "Current Node " << this->data << " deleted !..." << endl;

        }

};

void printDLL(Node* & head){

    Node* temp = head;

    while(temp != NULL){

        cout << temp->data << "     ";
        temp = temp->next;

    }
    
    cout << endl;

}

int lengthDLL(Node* & head){

    int length = 0;
    Node* temp = head;

    while(temp != NULL){

        length++;
        temp = temp->next;

    }
    // cout << length;
    
    return length;
    
}

void insertionAtHead(Node* & head, Node* & tail, int data){

    if(head == NULL && tail == NULL){

        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;

    }

    Node* newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
    return;

}

int main(){

    // Node* first = new Node(10);
    // Node* second = new Node(20);
    // Node* third = new Node(30);

    // first->next = second;
    // second->prev = first;

    // second->next = third;
    // third->prev = second;

    // printDLL(first);

    cout << endl;

    // cout << "Length is : " << lengthDLL(first) << endl;

    Node* head = NULL;
    Node* tail = NULL;

    insertionAtHead(head, tail, 5);
    insertionAtHead(head, tail, 4);
    insertionAtHead(head, tail, 3);

    cout << head->data << " _________ " << tail->data << endl;

    printDLL(head);

    return 0;

}