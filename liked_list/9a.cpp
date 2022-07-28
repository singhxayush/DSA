/////// Circular Linked list : with O(1) insertion : EFFICIENT ///////

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
    node(){ next = NULL; }
    node(int x){ data = x; next = NULL; }
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
}

Node insert_begin(int data, Node head)
{
    Node temp = new node(data);
    if(head==NULL)
    {
        temp->next = temp;
        return temp;
    }
    int t = head->data;
    head->data = temp->data;
    temp->data = t;

    temp->next = head->next;
    head->next = temp;
    return head;
}

Node insert_end(int data, Node head)
{
    Node temp = new node(data);
    if(head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    temp->next = head->next;
    head->next = temp;

    int t = head->data;
    head->data = temp->data;
    temp->data = t;

    return temp;
}

Node delete_begin(Node head)
{
    if(head == NULL) return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    Node itr = head->next;
    head->data = itr->data;
    head->next = itr->next;
    delete itr;
    return head;
}
int main()
{
    Node head;

    head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = head;

    // head = insert_begin(0, head);
    // head = insert_end(6, head);
    // head = delete_begin(head);
    
    display_list(head);
}