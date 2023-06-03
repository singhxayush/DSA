///// PAIR WITH A GIVEN SUM IN UMSORTED ARRAY /////

#include<bits/stdc++.h>
using namespace std;
#define soa(x) sizeof(x)/sizeof(x[0])
int main()
{
   int a[] = {3, 2, 8, 2, 5, 6, 2, 8, 9, 11, 18};
   int sum = 12;
   int n = soa(a);

   unordered_set<int> s;
   bool b = false;

   for(int i=0; i<n; i++)
   {
      // s.insert(a[i]);

      if(s.find(sum-a[i])!=s.end())
      {
         cout<<"TRUE\n";
         b = true;
         // break;
      }
      else s.insert(a[i]);
   }
   if(!b) cout<<"FALSE\n";
}