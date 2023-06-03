/////// DOUBLY LINKED LIST ///////

#include<iostream>
using namespace std;

struct node
{
    int data;
    struct node *l;
    struct node *r;
    
    node(int x)
    {
        data = x;
        l = NULL;
        r = NULL;
    }
    node()
    {
        l = NULL;
        r = NULL;
    }
};
typedef node* Node;

Node insert_begin(int data, Node head)
{
    Node temp = new node(data);
    temp->l = NULL;
    temp->r = head;
    head->l = temp;
    
    return temp;
}

Node insert_end(int data, Node head)
{
    Node cur = head;
    Node temp = new node(data);
    while(cur->r != NULL)
    {
        cur = cur->r;
    }
    temp->l = cur;
    temp->r = NULL;
    cur->r = temp;

    return head;
}
void display_list(Node head)
{
    Node itr = head;
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->r;
    }
}
int main()
{
    // Node head = new node();

    Node n1 = new node(1);
    // head->r = n1;
    // n1->l = head;

    Node n2 = new node(2);
    n1->r = n2;
    n2->l = n1;
    
    Node n3 = new node(3);
    n2->r = n3;
    n3->l = n2;

    Node n4 = new node(4);
    n3->r = n4;
    n4->l = n3;

    n1 = insert_begin(0, n1);
    n1 = insert_end(6, n1);
    display_list(n1);

    // Node head = new node();
    // Node tail = new node();

}