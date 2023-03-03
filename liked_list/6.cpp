/////// INSERT & DELETE AT POSITION (SLL) ///////

#include<iostream>
using namespace std;

struct Node
{
    int data;
    Node * next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void printlist(Node *head)
{
    Node *itr = head;
    while(itr != NULL)
    {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<"\n";
}

Node * insert_at(int pos, Node * head, int data)
{
    Node * temp = new Node(data);
    Node * curr = head;
    int c = 1;

    if(pos == 1)
    {
        temp->next = head;
        return temp;
    }
    while(c != pos-1 && curr->next != NULL)
    {
        c++;
        curr = curr->next;
    }
    temp->next = curr->next;
    curr->next = temp;

    return head;
}

Node * delete_at(int pos, Node * head)
{
    if(pos<=0) {
        cout<<"Invalid position\n";
        return head;
    }

    if(head == NULL) return NULL;

    if(pos == 1)
    {
        Node * temp = head->next;
        delete head;
        return temp;
    }

    int c = 0;
    Node * curr = head;

    while(curr != NULL && ++c < pos-1) curr = curr->next;

    if(curr == NULL || curr->next == NULL) {
        cout<<"Invalid position\n";
        return head;
    }

    Node * temp = curr->next->next;
    delete(curr->next);
    curr->next = temp;

    return head;
}

int main()
{
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = insert_at(1, head, 0);
    head = insert_at(3, head, 15);

    head = delete_at(7, head);
    printlist(head);
}