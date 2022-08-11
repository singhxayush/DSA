// { Driver Code Starts
// Initial Template for C++

// ab ac bc ab ca cb ab ac bc ba ca bc ab ac bc

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int move_counts = 0;
    vector<int> v;
    vector<int> shiftPile(int N, int n){
        toh(N, 1, 2, 3, n);
        return v;
    }
    void toh(int N, int a, int b, int c, int n)
    {
        if(N==1)
        {
            
            move_counts++;
            if(move_counts == n)
            {
                v.push_back(a);
                v.push_back(c);
                return;
            }
            return;
        }
        toh(N-1, a, c, b, n);
        move_counts++;
        if(move_counts == n)
        {
            v.push_back(a);
            v.push_back(c);
            return;
        }
        toh(N-1, b, a, c, n);
    }
};
//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, n;
        cin>>N>>n;
        
        Solution ob;
        vector<int> ans = ob.shiftPile(N, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}
// } Driver Code Ends