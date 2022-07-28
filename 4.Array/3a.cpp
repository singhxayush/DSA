// O(n) solution

#include<iostream>
using namespace std;
typedef long long  ll;

    
int main(){
    int n; cin>>n;
    int a[n];

    for(auto & elm : a) cin>>elm;

    int maxVal = a[1]-a[0], minVal = a[0];
    for(int i=1; i<n; i++){
        maxVal = max(maxVal, a[i]-minVal);
        minVal = min(minVal, a[i]);
    }
    cout<<maxVal<<endl;
}