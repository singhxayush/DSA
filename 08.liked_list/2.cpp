/////// linked list Traversal in c++ ///////

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

int main()
{
    Node * head = new Node(10);

    Node * temp1 = new Node(20);
    head->next = temp1;

    Node * temp2 = new Node(30);
    temp1->next = temp2;

    printlist(head);
}