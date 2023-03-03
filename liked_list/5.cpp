/////// DELETE FROM START AND END ///////

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head){
    Node *itr = head;
    while(itr != NULL)
    {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<"\n";
}
Node * delete_begin(Node * head){
    if(head == NULL) return NULL;
    else{
        Node * temp = head->next;
        delete head;
        return temp;
    }
}
Node * delete_end(Node * head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node * itr = head;
    while(itr->next->next != NULL) itr = itr->next;
    delete (itr->next);
    itr->next=NULL;
    return head;
}

int main()
{
    Node * head = new Node(10);
    Node * temp1 = new Node(20);
    head->next = temp1;
    Node * temp2 = new Node(30);
    temp1->next = temp2;

    // head = delete_begin(head);
    // head = delete_end(head);
    Node * x = delete_end(head);
    cout<<x->data<<"\n";
    printlist(head);
}