/////// Middle of Linked list (Slow and Fast pointer traversal) ///////
// Nth node from end of linked list
// Reverse the Linked List
// Reverse the Linked List : Recursive Approach!
// Make Unique!
// Reverse a linked list in groups of size k

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
typedef struct node* Node;

void display_list(node * head)
{
    node * itr = head;
    while(itr != NULL)
    {
        cout<<itr->data<<" ";
        itr = itr->next;
    }
    cout<<endl;
}

void print_middle(Node head)
{
    if(head == NULL) return;
    Node slow, fast;
    slow = fast = head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<slow->data<<"\n";
}

void kth_node_from_end(Node head, int k)
{
    Node front, rear;
    front = rear = head;
    for(int i=0; i<k; i++)
    {
        if(front == NULL) {cout<<"over the range\n"; return;}
        front = front->next;
    }
    while(front != NULL)
    {
        front = front->next;
        rear = rear->next;
    }
    cout<<rear->data<<"\n";
}

Node reverse_list(Node head)
{
    if(head == NULL) return NULL;

    Node prev = NULL; // tailing iterative node
    Node curr = head; // a iterarive node ahead 1 node by curr
    Node next;
    while(curr!=NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

Node reverse_list_recursive(Node curr, Node prev)
{
    
        Node next = curr->next;
        curr->next = prev;
        return reverse_list_recursive(next, curr);
}

void make_unique(Node head)
{
    Node itr = head;
    while(itr != NULL && itr->next != NULL)
    {
        if(itr->data == itr->next->data)
        {
            Node temp = itr->next;
            itr->next = itr->next->next;
            free(temp);
        }
        else itr = itr->next;
    }
}

void doit(Node head, int k)
{
    Node temp, prev, curr, next;
    int c = 0;
    while(curr!=NULL)
    {
        
    }
}

int main()
{
    Node head = new node(1);
    head->next = new node(2);
    head->next->next = new node(2);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);
    head->next->next->next->next->next = new node(5);
    
    // print_middle(head);
    // kth_node_from_end(head, 2);
    // head = reverse_list(head);
    // make_unique(head);
    
    display_list(head);
}