///// check if kth bit is set or not /////

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, k; cin>>n>>k;
    if(((1<<k)&n)) cout<<"set\n";
    else cout<<"not set\n";
}