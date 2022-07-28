#include<bits/stdc++.h>
using namespace std;

#define ip(x) int x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)

bool ispow(int n){
    if(n==0) return false;
    while(n!=1){
        if(n%2!=0) return false;
        n = n/2;
    }
    return true;
}
bool countsetbit(int n){
    if(n==0) return false;
    int res=0;
    while(n>0){
        n = n & (n-1);
        res++;
        if(res>1) return false;
    }
    return true;
}
bool ispow2(int x){
    if ((x & (x - 1)) != 0)
		return false;
	return true;
}
int main(){
    //naive solution
    cout<<"Naive solution\n";
    ip(n)
    if(ispow(n)) cout<<"yes\n";
    else cout<<"no\n";


    //set bit logic(if set bit = 1, then its a power of 2)
    cout<<"SET BIT solution\n";
    ip(n1)
    if(countsetbit(n1)) cout<<"yes\n";
    else cout<<"no\n";


    //unsetting set bits -> if its pow of 2 then only 1 set bit, so unsetting will give 0
    cout<<"unsetting set bits\n";
    ip(n2)
    cout << ((ispow2(n2)) ? "Yes" : "No") << std::endl;
}