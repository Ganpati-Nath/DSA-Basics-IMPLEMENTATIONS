#include <bits/stdc++.h>

using namespace std;

class Node{

    public:

        int val;
        Node* prev;
        Node* next;

        Node(int val){

            this->val = val;
            this->prev = NULL;
            this->next = NULL;

        }

        ~Node(){

            cout << "Node " << this->val << " DELETED... !..." << endl;

        }

};

void printDoublyLL(Node* &head){

    Node* temp = head;

    while(temp != NULL){

        cout << temp->val << "   ";
        temp = temp->next;

    }

    cout << endl;

}

int lengthOfDoublyLL(Node* &head){

    Node* temp = head;
    int length = 0;

    while(temp != NULL){

        length++;
        temp = temp->next;

    }

    return length;
    
}

void insertionAtPositionDoublyLL(Node* &head, Node* &tail, int val, int position){

    if(head == NULL && tail == NULL){

        Node* newNode = new Node(val);
        head = newNode;
        tail = newNode;
        return;

    }

    if(position <= 0){

        Node* newNode = new Node(val);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        return;

    }

    int length = lengthOfDoublyLL(head);

    if(position >= length){

        Node* newNode = new Node(val);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        return;

    }

    Node* prevNode = head;
    int i = 1;

    while(i < position){

        prevNode = prevNode->next;
        i++;

    }

    Node* newNode = new Node(val);
    newNode->next = prevNode->next;
    prevNode->next->prev = newNode;
    prevNode->next = newNode;
    newNode->prev = prevNode;
    return;

}

void deletionAtPositionDoublyLinkedList(Node* &head, Node* &tail, int position){

    if(head == NULL && tail == NULL){

        return;

    }

    if(head == tail){

        Node* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;

    }

    if(position == 1){

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
        return;

    }

    int length = lengthOfDoublyLL(head);

    if(position == length){

        Node* temp = tail->prev;
        temp->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = temp;
        return;

    }

    Node* prevNode = head;
    int i = 1;

    while(i < position - 1){

        prevNode = prevNode->next;
        i++;

    }

    Node* currNode = prevNode->next;
    prevNode->next = currNode->next;
    currNode->next->prev = prevNode;
    currNode->next = NULL;
    currNode->prev = NULL;
    delete currNode;
    return;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertionAtPositionDoublyLL(head, tail, 5, 0);
    insertionAtPositionDoublyLL(head, tail, 10, 1);
    insertionAtPositionDoublyLL(head, tail, 7, 1);
    insertionAtPositionDoublyLL(head, tail, 6, 1);
    insertionAtPositionDoublyLL(head, tail, 8, 3);
    insertionAtPositionDoublyLL(head, tail, 9, 4);

    deletionAtPositionDoublyLinkedList(head, tail, 1);
    deletionAtPositionDoublyLinkedList(head, tail, 5);
    deletionAtPositionDoublyLinkedList(head, tail, 2);
    deletionAtPositionDoublyLinkedList(head, tail, 3);
    deletionAtPositionDoublyLinkedList(head, tail, 1);
    deletionAtPositionDoublyLinkedList(head, tail, 1);

    cout << "Length of current doubly linked list is : " << lengthOfDoublyLL(head) << endl;

    // cout << "Head is : " << head->val << endl;
    // cout << "Tail is : " << tail->val << endl;

    printDoublyLL(head);

    return 0;

}