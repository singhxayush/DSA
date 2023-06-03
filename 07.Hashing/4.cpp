///// UNORDERED SET IN C++ STL /////

/* 
    >UNORDERED SET is based on hashing => search insert and del is O(N) on avg
     set does not maintain any order of the elemnts, for different compilers you may get different orders

    > only a unique value is present in the unordered set

    >but set is based on RED BLOOD TREE
*/


/*------------> IMPORTANT POINT TO NOTE : DELETE, SEARCHING, COUNT AND INSERT IN CONSANT TIME IN UNORDERED SET!!! <------------*/
#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

int main()
{
    unordered_set<int> s;
    s.insert(1);
    s.insert(3);
    s.insert(15);
    s.insert(12);
    s.insert(10);
    s.insert(12);
    s.insert(3);

    for(auto x : s) cout<<x<<" "; // output : 5 12 10 15 3 1
    cout<<endl;
}