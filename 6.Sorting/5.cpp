///// NAIEVE SOLN : INVERSIONS IN ARRAY : O(N*N) /////

#include<bits/stdc++.h>
using namespace std;

int main()
{
    // int a[] = {2, 4, 1, 3, 5};
    int a[] = {4, 3, 2, 1};

    int n = sizeof(a)/sizeof(a[0]), c = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[j]<a[i]) c++;
        }
    }

    cout<<c<<endl;
}