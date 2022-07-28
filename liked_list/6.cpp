/////// INSERT AT POSITION ///////

#include<iostream>
using namespace std;

struct Node
{
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
int main()
{
    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    head = insert_at(1, head, 5);
    head = insert_at(3, head, 5);
    printlist(head);
}