// Maximum difference -> O(n^2)
#include<iostream>
using namespace std;
typedef long long  ll;

    
int main(){
    int n; cin>>n;
    int a[n];

    for(auto & elm : a) cin>>elm;
    
    int i, j, m = INT32_MIN;
    for(i=0; i<n-1; i++)
    for(j=i+1; j<n; j++)
    {
        if(a[j]<=a[j-1])
        {
            continue;
        }
        else{
            m = max(m, (a[j]-a[i]));
        }
    }
    cout<<m;
}