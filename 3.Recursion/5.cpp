// TOWER OF HANOI

#include<iostream>
using namespace std;

typedef long long  ll;

static int move_counts = 0;

void toh(int n, char a, char b, char c) // c -> destination, b -> auxillary tower
{
    move_counts++;
    if(n==1)
    {
        cout<<"move 1 from "<<a<<" to "<<c<<endl;
        return;
    }
    toh(n-1, a, c, b);
    cout<<"move "<<n<<" from "<<a<<" to "<<c<<endl;
    toh(n-1, b, a, c);
}
int main()
{
    int n; cout<<"Enter Number of Discs :"; cin>>n;
    toh(n, 'a', 'b', 'c');
    cout<<"Total number of moves :"<<move_counts<<endl;
}