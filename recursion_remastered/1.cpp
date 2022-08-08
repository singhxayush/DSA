// 

#include<iostream>
using namespace std;
void one_to_n(int n)
{
    if(n)
    {
        one_to_n(n-1);
        cout<<n<<"\n";
    }
}

void n_to_one(int n)
{
    if(n)
    {
        cout<<n<<"\n";
        n_to_one(n-1);
    }
    cout<<0<<"\n";
    return;
}
int main()
{
    // one_to_n(5);
    n_to_one(5);
}