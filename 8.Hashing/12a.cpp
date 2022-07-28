///// LONGEST SUBARRAY WITH EQUAL NUMBERS OF 0's AND 1's /////


// SOLUTION APPROACH (TO SOLVE THIS AS LONGEST SUBARRAY WITH A GIVEN SUM WE RELPLACE ALL ZEROS WITH -1, HENCE THE QUESTION NOW BECOMES LONGERST LENGTH OF SUBARRAY WITH GIVEN SUM AS 0)


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
      if(!a[i]) a[i] = -1;
      pre_sum += a[i];

      if(pre_sum == 0) res = i+1;

      if(s.find(pre_sum) == s.end()) s.insert(pre_sum);

      if(s.find(pre_sum) != s.end()) res = max(res, i+1-pre_sum);
   }

   cout<<res;
}