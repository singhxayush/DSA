#include<bits/stdc++.h>
using namespace std;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;
#define pr(x) cout<<x<<" ";
#define endl "\n"
#define MAX 1000

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
    int n = a.size();
    for(auto x : a) cout<<x<<"\t"; cout<<endl;

    stack<pair<int, int>> t;
    vector<int> l;
    int c = 0;
    for(auto x : a) // left part
    {
        while(!t.empty() && t.top().first>=x) t.pop();

        if(t.empty()) l.push_back(c+1);
        else l.push_back(c - t.top().second);
        t.push({x, c++});
    }
    for(auto x : l) cout<<x<<"\t"; cout<<endl;

    stack<pair<int, int>> s;
    vector<int> r;
    c = 0;
    for(int i=n-1; i>=0; i--) // right part
    {
        while(!s.empty() && s.top().first>=a[i]) s.pop();
        if(s.empty()) r.push_back(1);
        else r.push_back(s.top().second - i);
        s.push({a[i], i});
    }
    reverse(r.begin(), r.end());
    for(auto x : r) cout<<x<<"\t"; cout<<endl;

    int xx = 0;
    for(int i=0; i<n; i++){
        int k = a[i]*(r[i]+l[i]-1);
        cout<<k<<"\t";
        xx = max(xx, k);
    } cout<<endl;
    cout<<"\nMAX AREA : "<<xx<<"\n";
}

void max_area_histogram2(vector<int> a)
{
    int n = a.size();

    stack<pair<int, int>> l;
    stack<pair<int, int>> r;
    vector<int> v(n, 0);

    for(int i=0; i<n; i++)
    {
        while(!l.empty() && l.top().first>=a[i]) l.pop();
        while(!r.empty() && r.top().first>=a[n-1-i]) r.pop();

        if(l.empty()) v[i] += i+1;
        else v[i] +=  i - l.top().second;
        l.push({a[i], i});

        if(r.empty()) v[n-1-i] += i+1;
        else v[n-1-i] += r.top().second - (n-1-i);
        r.push({a[n-1-i], n-1-i});
    }
    for(int i=0; i<n; i++) v[i] = a[i]*(v[i]-1);
    
    cout<<*max_element(v.begin(), v.end());
}


// max area of rectangle in a binary matrix of size n x m
/* 
    consider a 4x4 matrix
    4 4
    0 1 1 0
    1 1 1 1
    1 1 1 1
    1 1 0 0

    max are of rectangle is 8
    1 1 1 1
    1 1 1 1

    - this problem follows maximum histogram area problem
    - where each row can be considered as histogram with height till sum of continuous 1s upward
    - for example in the above case 4 histograms are

        histogram |  max area of histogram 
        {0 1 1 0} |     2
        {1 2 2 1} |     4
        {2 3 3 2} |     8
        {3 4 0 0} |     6

        hence 8 answer
*/
int solve(vector<int> a)
{
    int n = a.size();

    stack<pair<int, int>> l;
    stack<pair<int, int>> r;
    vector<int> v(n, 0);

    for(int i=0; i<n; i++)
    {
        while(!l.empty() && l.top().first>=a[i]) l.pop();
        while(!r.empty() && r.top().first>=a[n-1-i]) r.pop();

        if(l.empty()) v[i] += i+1;
        else v[i] +=  i - l.top().second;
        l.push({a[i], i});

        if(r.empty()) v[n-1-i] += i+1;
        else v[n-1-i] += r.top().second - (n-1-i);
        r.push({a[n-1-i], n-1-i});
    }
    for(int i=0; i<n; i++) v[i] = a[i]*(v[i]-1);
    
    return (*max_element(v.begin(), v.end()));
}
void max_area_rectangle_in_binary_matrix(int a[MAX][MAX], int n, int m)
{
    int res = 0;

    for(int i=0; i<n; i++){
        vector<int> arr;
        for(int j=0; j<m; j++){
            if(i && a[i][j]) a[i][j] += a[i-1][j];
            arr.push_back(a[i][j]);
        }
        res = max(res, solve(arr));
    }
    cout<<"MAX area : "<<res<<endl;
}

// Rain water trapping
/*  
    - basically we have to trap rain water between the blocks
    - sizes of some conseutive blocks and rain water has to be stored in between them
    - for example

        3   0   0   2   0   4
        _                   _
        _           _       _
        _           _       _
        _____________________

        it will store 2*2 = 4 units of water between 3 & 2
        and 1*2 = 2 units of water between 2 & 4
        Hence the result is 4+2 = 6 units of water
*/
void rain_water_trapping(vector<int> a)
{
    int n = a.size();
    int ml = 0, mr = 0;
    vector<int> l(n), r(n);
    for(int i=0; i<n; i++){
        if(ml<a[i]) ml = a[i];
        l[i] = ml;
        if(mr<a[n-1-i]) mr = a[n-1-i];
        r[n-1-i] = mr;
    }
    int res = 0;
    for(int i=0; i<n; i++) res += min(l[i], r[i])-a[i];
    cout<<"total water stored : "<<res<<"\n";
}

