#include<bits/stdc++.h>
using namespace std;

#define ip(x) int x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)
int main(){
    ip(n)
    int arr[n];
    for(auto & elm : arr) cin >> elm;
    int t=0;

    for (int i = 0; i < n; i++)
    {
        t = t ^ arr[i];
    }
    for(int i=1; i<=n+1; i++)
    {
        t = t ^ i;
    }
    cout << t;
}