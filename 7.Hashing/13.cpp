/////  NAIVE - Longest common span with same sum in binary array /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
   array<int, 6> a1 {0, 1, 0, 0, 0 , 0};
   array<int, 6> a2 {1, 0, 1, 0, 0 , 1};
   int n = a1.size();

   int sum1=0, sum2=0, res = 0;

   for(int i=0; i<n; i++)
   {
      sum1 = 0, sum2 = 0;
      
      for(int j=i; j<n; j++)
      {
         sum1 += a1[j];
         sum2 += a2[j];

         if(sum1 == sum2) res = max(res, j-i+1);
      }
   }

   cout<<res;
}