///// INTERSECTION OF TWO SORTED ARRAYS /////

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int a[] = {3, 5, 10, 10, 10, 15, 15, 20};
    int b[] = {5, 10, 10, 15, 30};

    int m = sizeof(a)/sizeof(a[0]);
    int n = sizeof(b)/sizeof(b[0]);

    int o = max(a[m-1], b[n-1]) + 1;
    int arr[o] = {0};

    for(int i=0; i<m; i++) arr[a[i]]=1;
    for(int i=0; i<n; i++) if(arr[b[i]]==1) arr[b[i]]=2;;

    for(int i=0; i<o; i++) if(arr[i]==2) cout<<i<<" ";
}

/* 

    My implementation : limitations

    1. cant deal with negative numbers : but can be optimized to do so
    2. wont ever print the reverse sorted aray back in same order, always prints in asccending order
    3. space complexity will be fucked for bigger numbers or might also get segmentaion fault for numbers > 1e5

*/