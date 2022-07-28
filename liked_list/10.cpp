/////// Doubly Circular LL ///////

#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next, *prev;

    node(int x)
    {
        data = x;
        next = prev = NULL;
    }
    node()
    {
        next = prev = NULL;
    }
};
typedef node* Node;

void display_list(Node head)
{
    if(head == NULL) return;

    Node itr = head;

    do
    {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    while(itr != head);
    cout<<"\n";
}

Node insert_head(int x, Node head)
{
    Node temp = new node(x);
    if(head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
    }
    temp->next = head->next;
    temp->prev = head;
    head-> next = temp;

    int t = head->data;
    head->data = x;
    temp->data = t;

    return head;
}

Node insert_tail(int x, Node head)
{
    Node temp = new node(x);
    if(head == NULL)
    {
        temp->next = temp;
        temp->prev = temp;
    }
    temp->next = head->next;
    temp->prev = head;
    head-> next = temp;

    int t = head->data;
    head->data = x;
    temp->data = t;

    return head->next;
}


int main()
{
    Node head = new node(1);
    Node n1 = new node(2);
    Node n2 = new node(3);
    Node n3 = new node(4);
    Node n4 = new node(5);    


    head->next = n1;
    n1->next=n2;
    n2->next=n3;
    n3->next=n4;
    n4->next=head;
    
    head->prev = n4;
    n1->prev=head;
    n2->prev=n1;
    n3->prev=n2;
    n4->prev=n3;

    cout<<"initial list : ";
    display_list(head);

    head = insert_head(0, head);
    head = insert_tail(6, head);
    
    cout<<"final list   : ";
    display_list(head);
}