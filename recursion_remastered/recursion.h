#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;

#define el "\n"

void oneton(int n)
{
    if(n==0) return;
    oneton(n-1);
    cout<<n<<" ";
}
void ntoone(int n)
{
    if(n==0) return;
    cout<<n<<" ";
    ntoone(n-1);
}

//// sorting using recursive insertion sort ////

void insert_r(vector<int> &v, int key) {
    if(v.size()==0 || v.back()<=key){ 
        v.push_back(key);
        return; 
    }
    int val = v.back();
    v.pop_back();
    insert_r(v, key);
    v.push_back(val);
    return;
}
void sortarray(vector<int> &v) {
    if(v.size()==1) return;
    int key = v.back();
    v.pop_back();
    sortarray(v);
    insert_r(v, key);
}

// int top = 0;
// void insert_r(int a[], int key) 
// {
//     // cout<<top<<" "<<a[top]<<" "<<key<<endl;

//     if(top==0 || a[top-1]<=key) {
//         a[top] = key;
//         return;
//     }
//     int val = a[top--];
//     insert_r(a, key);
//     a[++top] = val;
//     return;
// }
// void sortarray(int a[], int n) {
//     if(n==0) return;
//     sortarray(a, n-1);
//     int top;
//     top = n-1;
//     int key = a[top];
//     insert_r(a, key);
// }

void insert_r(stack<int> &s, int key)
{
    if(s.empty() || s.top()<=key)
    {
        s.push(key);
        return;
    }
    int val = s.top();
    s.pop();
    insert_r(s, key);
    s.push(val);
    return;
}
void sort_stack(stack<int> &s)
{
    if(s.size()==1) return;
    int key = s.top();
    s.pop();
    sort_stack(s);
    insert_r(s, key);
}

void delete_midelm_stack(stack<int> &s, int pos)
{
    if(s.size()==pos)
    {
        s.pop();
        return;
    }
    
    int key = s.top();
    s.pop();
    delete_midelm_stack(s, pos);
    s.push(key);
}

void sort_stack_rev(stack<int> &s)
{
    if(s.size()==1) return;
    int key = s.top();
    s.pop();
    sort_stack_rev(s);  

    //insert section
    stack<int> temp;
    while(!s.empty() && key<s.top())
    {
        temp.push(s.top());
        s.pop();
    }
    s.push(key);
    while(!temp.empty())
    {
        s.push(temp.top());
        temp.pop();
    }
    return;
}

void insert(stack<int> &s, int key)
{
    if(s.empty()){
        s.push(key);
        return;
    }
    
    int x = s.top();
    s.pop();

    insert(s, key);

    s.push(x);
}
void reverse_stack(stack<int> &s)
{
    if(s.size()==1) return;

    int key = s.top();
    s.pop();
    reverse_stack(s);

    insert(s, key);
}

void toh(int n, int a, int b, int c) // s a d
{
    if(n==1) 
    {
        cout<<"move plate 1 from "<<a<<" to "<<c<<"\n";
        return;
    }
    toh(n-1, a, c, b);
    cout<<"move plate "<<n<<" from "<<a<<" to "<<c<<"\n";
    toh(n-1, b, a, c);
}

void subset(string ip, string op="")
{
    if(ip.empty())
    {
        cout<<op<<"\n";
        return;
    }

    string temp = ip;
    temp.erase(temp.begin() + 0);
    subset(temp, op);
    subset(temp, op+ip[0]);
}

void spaced_permutation(string op, string ip)
{
    if(ip.length()==0)
    {
        cout<<op<<"\n";
        return;
    }

    string op1 = op; // op1 includes space
    string op2 = op; // op2 does not

    op1 += "_";
    op1 += ip[0];
    op2 += ip[0];

    ip.erase(ip.begin()+0);

    spaced_permutation(op1, ip);
    spaced_permutation(op2, ip);
}

void permutation_with_case_change(string ip, string op="")
{
    if(ip.length()==0)
    {
        cout<<op<<"\n";
        return;
    }

    string op1, op2;
    op1 = op;
    op2 = op;

    op1 += ip[0]; // simple output

    char c = ip[0];
    if(islower(c)) c = toupper(c);
    else if(isupper(c)) c = tolower(c);
    op2 += c; // changed case output

    ip.erase(ip.begin()+0); // decreasing ip size

    permutation_with_case_change(ip, op2);
    permutation_with_case_change(ip, op1);
}

void letter_case_permutation(string ip, string op="")
{
    if(ip.length()==0)
    {
        cout<<op<<el;
        return;
    }

    string op1, op2;
    op1 = op;
    op2 = op;

    while(ip.length()>0 && isdigit(ip[0])) // ignoring the digits
    {
        op1 += ip[0];
        op2 += ip[0];
        ip.erase(ip.begin()+0);
    }
    if(ip.length()==0) 
    {
        cout<<op1<<el;
        return;
    }

    op1 += ip[0]; // simple output

    char c = ip[0];
    if(islower(c)) c = toupper(c);
    else if(isupper(c)) c = tolower(c);
    op2 += c; // changed case output

    ip.erase(ip.begin()+0); // decreasing ip size
    
    letter_case_permutation(ip, op2);
    letter_case_permutation(ip, op1);
}

