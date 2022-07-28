///// LONGEST SUBARRAY WITH A GIVEN SUM /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
   int a[]{5, 8, -4, -4, 9, -2, 2}; int sum = 0;
   // int a[]{3, 1, 0, 1, 8, 2, 3, 6}; int sum = 5;
   int n = soa(a);

   int pre_sum = 0, res = INT_MIN;

   unordered_map<int,int> m;

   for(int i=0; i<n; i++)
   {
      pre_sum += a[i];

      if(pre_sum == sum) res = i+1;

      if(m.find(pre_sum) == m.end()) m.insert({pre_sum, i});

      if(m.find(pre_sum-sum) != m.end()) res = max(res, i - m[pre_sum - sum]);
   }

   cout<<res<<"\n";
}