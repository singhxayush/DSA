// this question talks about the only odd occuring
// note that for this to happen the nomber of elements in the array also has to be odd
#include<bits/stdc++.h>
using namespace std;

#define ip(x) int x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)

int oddoc(int arr[], int n){
    int t = 0;
    for(int i=0; i<n; i++){
        t = t^arr[i];
    }
    return t;
}
int main(){
    //xor - method
    ip(n)
    int arr[n];
    for(auto & elm : arr)cin>>elm;
    int x = oddoc(arr, n);
    cout<<x;
}