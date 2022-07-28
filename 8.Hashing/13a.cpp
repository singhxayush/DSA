///// EFFICINET - Longest common span with same sum in binary array /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
   int a1[] {0, 1, 0, 0, 0, 0};
   int a2[] {1, 0, 1, 0, 0, 1};
   int n = soa(a1);

   int aux_array[6];
   int pre_sum = 0, res = 0;
   unordered_map<int, int> s;

   for(int i=0; i<n; i++)
   {
      aux_array[i] = a1[i]-a2[i];
      pre_sum += aux_array[i];
      if(pre_sum == 0) res = i+1;
      if(s.find(pre_sum)!=s.end()) res = max(res, i - s[pre_sum]);
      else s[pre_sum] = i;
   }
   cout<<res;
}