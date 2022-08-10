// 
#include<iostream>
using namespace std;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;

void one_to_n(int n)
{
    if(n)
    {
        one_to_n(n-1);
        cout<<n<<"\n";
    }
    return;
    cout<<0<<"\n";
}
void n_to_one(int n)
{
    if(n)
    {
        cout<<n<<"\n";
        n_to_one(n-1);
    }
    return;
    cout<<0<<"\n";
}
int main()
{
    // one_to_n(5);
    n_to_one(5);
}
