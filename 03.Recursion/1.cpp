#include<iostream>
using namespace std;

#define ip(x) int x; cin >> x;
#define tc int tt; cin>>tt; while(tt--)
void func(int n)
{
    if(n==0) return;
    func(n-1);
    cout<<n<<endl;
}
int main(){
    func(5);
}