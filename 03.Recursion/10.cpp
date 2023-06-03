// KK

#include<iostream>
#include<algorithm>
using namespace std;
void message(int n) { cout<<"Hello "<<n<<"\n"; if(--n)message(n); }
int main()
{
    int n;
    message(n = 3);
}