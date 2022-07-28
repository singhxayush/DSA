///// LONGEST SUBARRAY WITH EQUAL NUMBERS OF 0's AND 1's /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
   int a[] {1, 0, 1, 1, 1, 0, 0};
   int n = soa(a);

   int res = 0;
   unordered_set<int> s;
   int pre_sum = 0;

   for(int i=0; i<n; i++)
   {

      pre_sum += a[i];
      if(pre_sum == (i+1+1)/2) res = (i+2)/2-pre_sum;

      if(s.find(pre_sum) == s.end()) s.insert(pre_sum);

      if(s.find((i+2)/2 - pre_sum) != s.end()) res = max(res, i+1-pre_sum);

      // if(a[i]!=a[i+1] && l<=c) c++;
      // else
      // {
      //    l = c;
      //    res = max(res, l);
      //    c = 1;
      // }

   }

   cout<<res<<"\n";
}