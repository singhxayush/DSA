/////// Doubly Linked list : reverse && delete first & last ///////

#include<iostream>
#include<algorithm>
using namespace std;

struct node
{
    int data; 
    struct node *left, *right;

    node(int x)
    {
        data = x;
        left = right = NULL;
    }
    node(){ left = right = NULL; }
};
typedef node* Node;

void display_list(Node head)
{
    Node itr = head;
    while(itr != NULL)
    {
        cout << itr->data << " ";
        itr = itr->right;
    }
    cout<<"\n";
}

Node reverse_list(Node Head)
{
    if(Head==NULL || Head->right==NULL)
    return Head;
    Node prev = NULL, curr = Head;
    while(curr!=NULL)
    {
        prev = curr->left;
        curr->left = curr->right;
        curr->right = prev;
        curr = curr->left;
    }
    return prev->left;
}

Node delete_head(Node head)
{
    if(head==NULL || head->right==NULL) return NULL;
    Node temp = head;
    temp = temp->right;
    temp->left = NULL;
    free(head);
    return temp;
}

Node delete_last(Node head)
{
    if(head==NULL || head->right==NULL) return NULL;
    Node curr = head;
    while(curr->right!=NULL) curr=curr->right;
    Node prev=curr->left;
    prev->right=NULL;
    free(curr);
    return head;
}
int main()
{

    Node head = new node(1);
    Node n1 = new node(2);
    head->right = n1;
    n1->left = head;

    Node n2 = new node(3);
    n1->right = n2;
    n2->left = n1;

    Node n3 = new node(4);
    n3->left = n2;
    n2->right = n3;

    cout<<"normal list : ";
    display_list(head);

    cout<<"reversed list : ";
    head = reverse_list(head);
    display_list(head); 

    // head = delete_head(head);
    // if(head==NULL) cout<<"empty list\n";
    // else display_list(head);

    // head = delete_last(head);
    // head = delete_last(head);
    // head = delete_last(head);
    // head = delete_last(head);
    // if(head==NULL) cout<<"empty list\n";
    // else display_list(head);
}