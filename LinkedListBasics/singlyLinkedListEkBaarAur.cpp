#include <bits/stdc++.h>

using namespace std;

class ListNode{

    public:

        int val;
        ListNode* next;

        ListNode(int val){

            this->val = val;
            this->next = NULL;

        }

        ~ListNode(){

            cout << "ListNode " << this->val << "  DELETED... !...." << endl;

        }

};

void printSinglyLL(ListNode* &head){

    ListNode* temp = head;

    while(temp != NULL){

        cout << temp->val << "    ";
        temp = temp->next;

    }

    cout << endl;

}

int lengthOfSinglyLL(ListNode* &head){

    ListNode* temp = head;
    int length = 0;

    while(temp != NULL){

        length++;
        temp = temp->next;

    }

    return length;
    
}

void insertionAtPositionSinglyLinkedList(ListNode* &head, ListNode* &tail, int val, int position){

    if(head == NULL && tail == NULL){

        ListNode* newNode = new ListNode(val);
        head = newNode;
        tail = newNode;
        return;

    }

    if(position <= 0){

        ListNode* newNode = new ListNode(val);
        newNode->next = head;
        head = newNode;
        return;

    }

    int length = lengthOfSinglyLL(head);

    if(position >= length){

        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
        return;

    }

    ListNode* prevNode = head;
    int i = 1;

    while(i < position){

        prevNode = prevNode->next;
        i++;

    }

    ListNode* newNode = new ListNode(val);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
    return;

}

void deletionAtPositionSinglyLinkedList(ListNode* &head, ListNode* &tail, int position){

    if(head == NULL && tail == NULL){

        return;

    }

    if(head == tail){

        ListNode* temp = head;
        head = NULL;
        tail = NULL;
        delete temp;
        return;

    }

    if(position == 1){

        ListNode* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;

    }

    int length = lengthOfSinglyLL(head);

    if(position == length){

        ListNode* prevNode = head;
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

    ListNode* prevNode = head;
    int i = 1;

    while(i < position - 1){

        prevNode = prevNode->next;
        i++;

    }

    ListNode* currNode = prevNode->next;
    prevNode->next = currNode->next;
    currNode->next = NULL;
    delete currNode;
    return;
        
}

int main(){

    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertionAtPositionSinglyLinkedList(head, tail, 40, 0);
    insertionAtPositionSinglyLinkedList(head, tail, 60, 1);
    insertionAtPositionSinglyLinkedList(head, tail, 50, 1);
    insertionAtPositionSinglyLinkedList(head, tail, 70, 3);

    deletionAtPositionSinglyLinkedList(head, tail, 4);
    deletionAtPositionSinglyLinkedList(head, tail, 1);
    deletionAtPositionSinglyLinkedList(head, tail, 2);
    deletionAtPositionSinglyLinkedList(head, tail, 1);
    deletionAtPositionSinglyLinkedList(head, tail, 4);

    cout << "Length of current Linked List is : " << lengthOfSinglyLL(head) << endl;

    printSinglyLL(head);

    return 0;

}