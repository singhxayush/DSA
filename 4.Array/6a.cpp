#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n; cin>>n;
    int a[n];
    for(auto & elm : a) cin>>elm;

    int res = a[0], max_ending = a[0];
    for(int i=0; i<n; i++)
    {
        max_ending = max(max_ending + a[i], a[i]);
        res = max(res, max_ending);
    }

    cout<<res<<"\n";
}