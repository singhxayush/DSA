///// LONGEST SUBARRAY WITH A GIVEN SUM (NAIVE APPROACH) /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
   // int a[] {5, 8, -4, -4, 9, -2, 2}; int sum = 0;
   int a[]{3, 1, 0, 0, 1, 8, 2, 3, 6}; int sum = 5;

   int n = soa(a);

   int cur_sum = 0, res = 0;

   for(int i=0; i<n; i++)
   {
      cur_sum = 0;

      for(int j=i; j<n; j++)
      {
         cur_sum += a[j];

         if(cur_sum == sum)
         {
            res = max(res, j-i+1);
         }
      }
   }

   cout<<res;
}