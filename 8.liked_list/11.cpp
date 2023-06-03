/////// Sorted Insert ///////

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};

typedef node * Node;

Node sorted_insert(int x, Node head)
{
    Node temp = new node(x);
    if(head == NULL) return temp;
    if(x < head->data)
    {
        temp->next = head;
        return temp;
    }
    
    Node itr = head;
    while(itr->next != NULL && itr->data < x) itr = itr->next;
    temp->next = itr->next;
    itr->next = temp;
    return head;
}

void display_list(Node head)
{
    if(head == NULL) return;

    Node itr = head;

    do
    {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    while(itr != NULL);
    cout<<"\n";
}

int main()
{
    Node head;
    head = sorted_insert(4, head);
    head = sorted_insert(1, head);
    head = sorted_insert(7, head);
    head = sorted_insert(0, head);
    head = sorted_insert(9, head);
    head = sorted_insert(9, head);
    head = sorted_insert(-9, head);
    head = sorted_insert(-9, head);

    display_list(head);
}