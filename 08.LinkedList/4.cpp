/////// INSERT AT THE END ///////

#include<iostream>
using namespace std;

struct node{
    int data;
    node * next;
    node(int x)
    {
        data = x;
        next = NULL;
    }
};
void display(node * head){
    node * itr = head;
    while(itr != NULL)
    {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<endl;
}
node * insert_end(node * head, int x){
    node * temp = new node(x);
    if(head == NULL) return temp;
    node * itr = head;
    while(itr->next!=NULL)
    {
        itr = itr->next;
    }
    itr->next = temp;
    return head;
}
int main()
{
    node *head = NULL;
    head = insert_end(head, 1);
    head = insert_end(head, 2);
    head = insert_end(head, 3);

    display(head);
}