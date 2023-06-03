/////// linked list traversal in c++ ///////

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
    // sorter version of implementation!

    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    printlist(head);
}