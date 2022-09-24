///// SUB ARRAY SUM EQUAL TO A GIVEN SUM /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])
int main()
{
   int a[] = {10, 10, 20, -5, 15, -51, 80};
   int n = soa(a);

   int pre_sum = 0, sum = -1;

   unordered_set<int> s;

   for(int i = 0; i < n; i++)
   {
      pre_sum += a[i];

      if(pre_sum == sum || s.find(pre_sum - sum) != s.end())
      {
         cout<<"True";
         return 0;
      }
      else s.insert(pre_sum);
   }
   cout<<"False";
}
