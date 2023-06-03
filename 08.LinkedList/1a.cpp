/////// linked list implementation in c++ ///////

#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};
int main()
{
    // sorter version of implementation!

    Node * head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
}