///// NAIVE - Longest Consecutive Subsequence /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
   // int a[] = {1, 9, 3, 4, 2, 20};
   int a[] = {2, 9, 4, 3, 10};
   int n = soa(a);

   sort(a, a+n);

   int c = 1, res = 0;

   for(int i=0; i<n; i++)
   {
      if(a[i+1]-a[i] == 1) c++;
      else
      {
         res = max(res, c);
         c = 1;
      }
   }
   cout<<res<<"\n";
}