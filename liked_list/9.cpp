/////// Circular Linked list : NAIVE ///////

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
    cout<<"\n";
}

Node insert_begin(Node head, int data)
{
    Node temp = new node(data);
    if(head==NULL)
    {
        temp->next = temp;
        return temp;
    }
    Node cur = head;
    while(cur->next != head) cur = cur->next;
    temp->next = head;
    cur->next = temp;
    return temp;
}

Node insert_end(int data, Node head)
{
    Node temp = new node(data);
    if(head == NULL)
    {
        temp->next = temp;
        return temp;
    }
    Node cur = head;
    while(cur->next != head) cur = cur->next;
    temp->next = cur->next;
    cur->next = temp;
    return head;
}

Node delete_begin(Node head)
{
    if(head == NULL) return NULL;
    if(head->next == head)
    {
        delete head;
        return NULL;
    }
    Node itr = head;
    while(itr->next != head) itr = itr->next;
    itr->next = head->next;
    delete head;
    return itr->next;
}

Node delete_kth_elm(int k, Node head)
{
    
}
int main()
{
    Node head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = head;


    // head = insert_begin(head, 0);
    // head = insert_end(6, head);
    head = delete_begin(head);

    display_list(head);
}