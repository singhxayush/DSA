#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n, res=0, k=0; cin>>n;
    int a[n];
    for(auto & elm : a) cin>>elm;

    for(int i=k+1; i<n; i++)
    {   
        if(a[k]<=a[i])
        {
            res = res - (a[i]-a[k])*(k-i);
            k = i;
        }
        else
        {
            res+=a[k+i]; 
        }
        
        cout<<res<<"\n";

    }
}