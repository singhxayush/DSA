///// INTERSECTION OF TWO SORTED ARRAYS /////

#include<bits/stdc++.h>
using namespace std;


void intersection(int a[], int b[], int m, int n)
{
    int x = 0;
    for(int i=0; i<m; i++)
    {
        if(i>0 && a[i]==a[i-1]) continue;

        for(int j=x; j<n; j++)
        {
            if(b[j]==a[i])
            {
                cout<<a[i]<<" ";
                break;
                x = j+1;
            }
        }
    }
}
int main()
{
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);
    intersection(a, b, m, n);
}