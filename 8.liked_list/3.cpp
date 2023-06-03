/////// INSERT AT START ///////

#include<iostream>
using namespace std;

struct node {
    int data;
    node * next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void printlist(node *head)
{
    node *itr = head;
    while(itr != NULL)
    {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<"\n";
}
node * insert_begin(node * head, int x)
{
    node * temp = new node(x);
    temp->next = head;
    return temp;

}
int main()
{
    node * head = NULL;
    head = insert_begin(head, 10);
    head = insert_begin(head, 5);
    head = insert_begin(head, 2);
    printlist(head);
}