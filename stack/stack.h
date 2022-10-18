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
    while(!soln.empty()) { cout<<soln.top()<<" "; soln.pop(); } }

// prev largest element or nearest greater to left
void prev_largest_elm(vector<int> a)
{
    stack<int> t;
    vector<int> s;
    for(auto x : a)
    {
        while(!t.empty() && t.top()<x) t.pop();
        if(!t.empty()) s.push_back(t.top());
        else s.push_back(-1);
        t.push(x);
    }
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
    for(auto x : a) cout<<x<<"\t";cout<<"\n";
    while(!s.empty()) { cout<<s.top()<<"\t"; s.pop(); } cout<<"\n";
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
    for(auto x : a) cout<<x<<"\t";
    for(auto x : s) cout<<x<<"\t";
}

// stock span problem
// follows same pattern as nearest greater to left
void stock_span(vector<int> a)
{
    stack<pair<int, int>> t;
    vector<int> res;
    int c = 0;
    for(auto x : a){
        while(!t.empty() && t.top().first<=x) t.pop();

        if(t.empty()) res.push_back(c+1);
        else res.push_back(c - t.top().second);
        t.push({x, c++});
    }
    for(auto x : a) cout<<x<<"\t";cout<<endl;
    for(auto x : res) cout<<x<<"\t";cout<<endl;
}

// Maximum Area of histogram : most popular qsn of stack
// follows same pattern as next and prev nearest smaller
// same as stock span, but here we have to take greater or equal limit
// and check in adjacent sides instead of just one
/* 

    histogram considered : vector v1

        6   2   5   4   5   2   6
        _                       _
        _       _       _       _
        _       _   _   _       _
        _       _   _   _       _
        _   _   _   _   _       _
        _   _   _   _   _   _   _
       ___________________________

*/
void max_area_histogram(vector<int> a)
{
    stack<pair<int, int>> t;
    stack<pair<int, int>> s;
    vector<int> l, r;
    int c = 0;
    for(auto x : a){
        while(!t.empty() && t.top().first<=x) t.pop();

        if(t.empty()) l.push_back(c+1);
        else l.push_back(c - t.top().second);
        t.push({x, c++});
    }
    c = 0;
    for(int i=a.size()-1; i>=0; i--) {
        while(!s.empty() && s.top().first<=a[i]) t.pop();
        if(t.empty()) r.push_back(i+1);
        else r.push_back(abs(s.top().second - i));
        s.push({a[i], i});
    }
    int res = -1;
    for(int i = 0; i<r.size()-1; i++){
        int xx = abs(r[a.size()-i-1]-l[i]-1);
        res = max(res, xx);
    }
    cout<<res;
}