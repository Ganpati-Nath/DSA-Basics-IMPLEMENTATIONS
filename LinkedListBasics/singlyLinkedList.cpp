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
            cout << this->val << endl;
        }

};

void printSLL(ListNode* & head){

    ListNode* temp = head;

    while(temp != NULL){

        cout << temp->val << "    ";
        temp = temp->next;

    }

    cout << endl;

}

int lengthSLL(ListNode* & head){

    int length = 0;
    ListNode* temp = head;

    while(temp != NULL){

        length++;
        temp = temp->next;

    }

    return length;
    
}

void insertionAtPosition(ListNode* & head, ListNode* & tail, int position, int val){

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

    int length = lengthSLL(head);

    if(position >= length){

        ListNode* newNode = new ListNode(val);
        tail->next = newNode;
        tail = newNode;
        return;

    }

    int i = 1;
    ListNode* prevNode = head;

    while(i < position){

        prevNode = prevNode->next;
        i++;

    }

    ListNode* currNode = prevNode->next;
    ListNode* newNode = new ListNode(val);
    newNode->next = currNode;
    prevNode->next = newNode;
    return;

}

void deletionAtPosition(ListNode* & head, ListNode* & tail, int position){

    if(head == NULL && tail == NULL){

        return;

    }

    if(head == tail){

        ListNode* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;

    }
}

int main(){

    ListNode* head = NULL;
    ListNode* tail = NULL;

    insertionAtPosition(head, tail, 0, 10);

    deletionAtPosition(head, tail, 0);

    printSLL(head);

    return 0;
    
}