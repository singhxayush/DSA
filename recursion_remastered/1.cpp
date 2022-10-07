#include<bits/stdc++.h>
#include"recursion.h"

int main()
{
    //print 1 to N and reverse
    // oneton(4);
    // ntoone(6);

    //sort array
    // int n = 7;
    // int a[n] = {5, 19, -1, 0, 5, 3, 1};
    // sortarray(a, n); for(int i=0; i<n; i++) cout<<a[i]<<" ";

    // int n = 1;
    // int a[n] = {2};
    // sortarray(a, n); for(int i=0; i<n; i++) cout<<a[i]<<" ";

    //sort vector
    // vector<int> v{5, 19, -1, 0, 5, 3, 1};
    // sortarray(v);
    // for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";

    //sort stack
    stack<int> s;
    s.push(1);
    s.push(4);
    s.push(0);
    s.push(-1);
    s.push(2);
    s.push(0);

    // sort_stack(s);
    // int pos = s.size()/2+1;
    // delete_midelm_stack(s, pos);
    // sort_stack_rev(s);
    reverse_stack(s);
    while(!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }
}