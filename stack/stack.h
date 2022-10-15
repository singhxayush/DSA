#include<bits/stdc++.h>
using namespace std;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;
#define pr(x) cout<<x<<" ";

//next largest element or nearest greater to right
void next_largest_elm(vector<int> a)
{
    stack<int> temp, soln;
    int n = a.size();
    for(int i = n-1; i>=0; i--)
    {
        while(!temp.empty() && temp.top()<a[i]) temp.pop();
        if(temp.empty()){
            soln.push(-1);
            temp.push(a[i]);
        }
        else{
            soln.push(temp.top());
            temp.push(a[i]);
        }
    }
    while(!soln.empty()) {
        cout<<soln.top()<<" ";
        soln.pop();
    }
}

// prev largest element or nearest greater to left
void prev_largest_elm(vector<int> a)
{
    int c = 0;
    stack<int> t;
    vector<int> s;
    for(auto x : a)
    {
        while(++c && !t.empty() && t.top()<x) t.pop();
        if(!t.empty()) {
            s.push_back(t.top());
            t.push(x);
        }
        else{
            s.push_back(-1);
            t.push(x);
        }
        c++;
    }
    cout<<"loop count : "<<c<<"\n";
    for(auto x : s) cout<<x<<" ";
}

// next smaller element or nearest smaller to right
void next_smallest_elm(vector<int> a)
{
    int c = 0;
    stack<int> t;
    stack<int> s;
    for(int i=a.size()-1; i>=0; i--)
    {
        while(!t.empty() && t.top()>=a[i]) t.pop();
        if(!t.empty()) s.push(t.top());
        else s.push(-1);
        t.push(a[i]);
    }
    for(auto x : a) pr(x);pr("\n");
    while(!s.empty()) { pr(s.top()); s.pop(); }
}

// prev smaller left or nearest smaller left
void prev_smallest_elm(vector<int> a)
{
    stack<int> t;
    vector<int> s;

    for(auto x : a)
    {
        while(!t.empty() && t.top()>=x) t.pop();
        if(!t.empty()) s.push_back(t.top());
        else s.push_back(-1);
        t.push(x);
    }
    for(auto x : s) cout<<x<<" ";
}