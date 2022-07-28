///// UNION OF TWO SORTED ARRAY /////

#include<bits/stdc++.h>
using namespace std;

void array_union(int a[], int b[], int m, int n)
{
    int i=0, j=0, c=0;
    while(i<m && j<n)
    {
        c++;
        if(i && a[i]==a[i-1]) { i++; continue; }
        if(j && b[j]==b[j-1]) { j++; continue; }

        if(a[i]<b[j]) {cout<<a[i]<<" "; i++;}
        else if(a[i]>b[j]) {cout<<b[j]<<" "; j++;}
        else {cout<<a[i]<<" "; i++; j++;}

        if(i==m || j==n)
        {
            if(i==m) while(j<n) { c++; if(j && b[j]!=b[j-1]) cout<<b[j]<<" "; j++; }
            if(j==n) while(i<m) { c++; if(i && a[i]!=a[i-1]) cout<<a[i]<<" "; i++; }
        }
    }

    cout<<endl<<"loop ran : "<<c<<" times\n";
}
int main()
{
    int a[] = {3, 5, 8};
    int b[] = {2, 8, 9, 9, 10, 15};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    array_union(a, b, m, n);
}