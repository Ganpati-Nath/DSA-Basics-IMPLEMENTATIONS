#include <bits/stdc++.h>

using namespace std;

class Node{

    public:

        int data;
        Node* next;

        Node(int data){

            this->data = data;
            this->next = NULL;

        }

        ~Node(){

            cout << "Node " << this->data << " deleted !...." << endl;

        }

};

void printSLinkedL(Node* & head){

    Node* temp = head;

    while(temp != NULL){

        cout << temp->data << "     ";
        temp = temp->next;

    }

    cout << endl;

}

int lengthSLinkedL(Node* & head){

    int length = 0;
    Node* temp = head;

    while(temp != NULL){

        length++;
        temp = temp->next;

    }

    return length;
    
}

void insertionAtPositionSLinkedL(Node* & head, Node* & tail, int data, int position){

    if(head == NULL && tail == NULL){

        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
        return;

    }

    if(position < 1){

        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return;

    }

    int length = lengthSLinkedL(head);

    if(position >= length){

        Node* newNode = new Node(data);
        tail->next = newNode;
        tail = newNode;
        return;

    }

    Node* prevNode = head;
    int i = 1;

    while(i < position){

        prevNode = prevNode->next;
        i++;

    }

    Node* currNode = prevNode->next;
    Node* newNode = new Node(data);
    newNode->next = currNode;
    prevNode->next = newNode;
    return;

}

void deletionAtPosition(Node* & head, Node* & tail, int position){

    if(head == NULL && tail == NULL){

        return;

    }

    if(position == 1){

        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;

    }

    int length = lengthSLinkedL(head);

    if(position == length){

        Node* prevNode = head;
        int i = 1;

        while(i < position - 1){

            prevNode = prevNode->next;
            i++;

        }

        prevNode->next = NULL;
        delete tail;
        tail = prevNode;
        return;

    }

    int i = 1;
    Node* prevNode = head;

    while(i < position - 1){

        prevNode = prevNode->next;
        i++;

    }

    Node* currNode = prevNode->next;
    prevNode->next = currNode->next;
    currNode->next = NULL;
    delete currNode;
    return;

}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertionAtPositionSLinkedL(head, tail, 5, 0);
    insertionAtPositionSLinkedL(head, tail, 4, 0);
    insertionAtPositionSLinkedL(head, tail, 2, 0);
    insertionAtPositionSLinkedL(head, tail, 1, 0);
    insertionAtPositionSLinkedL(head, tail, 3, 2);
    insertionAtPositionSLinkedL(head, tail, 6, 5);

    deletionAtPosition(head, tail, 1);
    deletionAtPosition(head, tail, 5);
    deletionAtPosition(head, tail, 2);

    cout << "Length of current Linked List is : " << lengthSLinkedL(head) << endl;
    cout << "Printing..." << endl;

    printSLinkedL(head);

    cout << "Head : " << head->data << endl;
    cout << "Tail : " << tail->data << endl;

    return 0;

}