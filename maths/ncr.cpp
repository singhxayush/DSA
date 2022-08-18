// https://practice.geeksforgeeks.org/problems/ncr1019/1


//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
const int mod = 1e9+7;
class Solution{
public:
    int nCr(int n, int r){
        // code here
        if(r>n)
        {
            return 0;
        }
        if(n==r || r==0)
        {
            return 1;
        }
        if(r>n-r) r = n-r;
        unordered_map<int, int> m;
        for(int j=0; j<r; j++)
        {
            int k = n-j;
            while (k % 2 == 0)
            {
                m[2]++;
                k = k/2;
            }
        
            for (int i = 3; i <= sqrt(k); i = i + 2)
            {
                while (k % i == 0)
                {
                    m[i]++;
                    k = k/i;
                }
            }
            if (k > 2) m[k]++;
        }
        for(int j=2; j<=r; j++)
        {
            int k = j;
            while (k % 2 == 0)
            {
                m[2]--;
                k = k/2;
            }
        
            for (int i = 3; i <= sqrt(k); i = i + 2)
            {
                while (k % i == 0)
                {
                    m[i]--;
                    k = k/i;
                }
            }
            if (k > 2) m[k]--;
        }
        long long int res = 1, num = 1;
        for(auto it = m.begin(); it!=m.end(); ++it)
        {
            if(it->second > 0){
                num = pow((it->first), (it->second));
                res = (res*num)%mod;
            }
        }
        res = res%mod;
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends