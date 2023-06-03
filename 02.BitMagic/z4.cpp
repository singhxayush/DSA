///// Maximum XOR subarray /////

// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
//User function Template for C++



class Solution{   
public:
    int maxSubarrayXOR(int N, int arr[]){    
        //code here

        int x = 0, max_xor = INT_MIN, curr_xor = 0;
        if(N==1) return arr[0];
        for(int i=1; i<N; i++)
        {
            x = curr_xor^arr[i];
            if(x >= curr_xor) curr_xor = arr[i]^curr_xor;
            else curr_xor = arr[i];

            max_xor = max(curr_xor, max_xor);
        }
        return max_xor;
    }
};

// { Driver Code Starts.
int main() 
{
    // int x = 4^3;
    // cout<<x;
    int t;
    cin>>t;
    while(t--)
    {
        int N, X;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.maxSubarrayXOR(N, arr) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends