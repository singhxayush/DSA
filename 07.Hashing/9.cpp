///// SUB ARRAY WITH 0 SUM /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])

int main()
{
   int a[] = {10, 10, 20, -5, 15, -51, 80};
   int n = soa(a);

   int prefix_sum = 0;

   unordered_set<int> s;

   for(int i=0; i<n; i++)
   {
      prefix_sum+=a[i];

      if(s.find(prefix_sum) != s.end() || prefix_sum == 0) {cout<<"YES"; return 0;}
      else s.insert(prefix_sum);
   }
   cout<<"NO";
}