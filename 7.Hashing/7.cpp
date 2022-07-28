///// intersection of two array /////

#include<bits/stdc++.h>
using namespace std;

int main()
{

   int a[] = {10, 15, 20, 5, 30, 80};
   int b[] = {30, 5, 30, 80};

   int n = 6, m = 4;

   set<int> s1, s2;

   for(int i=0; i<n; i++) s1.insert(a[i]);
   for(int i=0; i<m; i++) s2.insert(b[i]);

   int res = 0;
   set<int> :: iterator it = s1.begin();
   for(it=s1.begin(); it!=s1.end(); ++it) if(s2.find(*it) != s2.end()) res++;
   cout<<res<<"\n";

}