#include"DynamicProgramming.h"

int main()
{
    //*------------------|Knapsack|------------------

    // int n = 7;
    // int w = 9;
    // int wt[n] = {3, 1, 7, 4, 2, 8, 6};
    // int val[n] = {1, 4, 9, 3, 10, 4, 6};

    ////? Normal recursive Knapsack - Brute force
    // cout<<knapsack_recursive(wt, val, w, n)<<"\n";

    ////? Recursive memoization Knapsack
    // memset(dp, -1, sizeof(dp));
    // knapsack_dp_memoization(wt, val, w, n);
    // displaydp(n, w);
    // cout<<dp[n][w]<<"\n";

    ////? Iterative bottom Up knapsack
    // cout<<knapsack_dp_bottomup(wt, val, w, n)<<"\n";


    ////? Subset Sum problems
    // int arr[7] = {3, 4, 3, 5, 2, 1, 7};
    // cout<<subsetsum(arr, 7, 24)<<"\n";
    // cout<<equal_partition(arr, 7)<<"\n";
    // cout<<numofSubsets(arr, 7, 20)<<"\n";

    // int arr1[3] = {6, 7, 2};
    // cout<<minSubsetSumDiff(arr1, 3)<<"\n";
    // cout<<minSubsetSumDiff(arr, 7)<<"\n";

    // int arr2[] = {1, 2, 1, 3};
    // cout<<numofSubset_with_a_givenDifference(arr2, 4, 2)<<"\n";
    // cout<<numofSubset_with_a_givenDifference(arr, 7, 3)<<"\n";
    // cout<<target_sum(arr2, 4, 2);




    //*----------------|Unbounded Knapsack|----------------

    ////? Rod cutting and coin change problem
    // int L = 11, n =  5;
    // int len[n] = {1, 3, 5, 7, 8};
    // int price[n] = {2, 6, 3, 4, 6};
    // cout<<knapsack_dp_bottomup(len, price, L, n); 
    // cout<<maxProfit_by_CuttingRods(len, price, n, L)<<"\n";

    // int coins[6] = {2, 4, 8, 5, 1, 9};
    // sort(coins, coins+6);
    // int sum = 3;
    // cout<<coinChange(coins, sz(coins), sum);
    // cout<<coinChange2(coins, sz(coins), sum)<<"\n";




//*-----------------------|L C S|-----------------------
    
    ////? LCS RECURSVE
    // string s1 = "abcdgh";
    // string s2 = "abedfhr";

    // s1 = "abcde";
    // s2 = "pqrsc";

    // s1 = "abcdaf";
    // s2 = "acbcf";

    // cout<<"len(LCS) of "<<s1<<" & "<<s2<<" : "
    // <<LCS_recursive(s1, s2, s1.length(), s2.length());

    ////? LCS Bottom Up(Memoization)
    // memset(dp, -1, sizeof(dp));
    // cout<<"len(LCS) of "<<s1<<" & "<<s2<<" : "
    // <<LCS_bottomUp(s1, s2, s1.length(), s2.length());




//*-----------------------|M C M|-----------------------

    // int a[5] = {4, 2, 6, 7, 3};
    // int l=0, r=sz(a)-1;

    ////? MCM (Recursive)
    // pr(mcm_recursive(a, l, r));

    ////? MCM (Bottom up)
    // memset(dp, -1, sizeof(dp));
    // pr(mcm(a, l, r));
    // displaydp(10, 10);



//*-----------------------|P S P|-----------------------

    // string s = "nitik";
    // int l = 0, r = s.length()-1;

    ////? PSP (Recursive)
    // pr(psp_recursive(s, l, r));

    ////? PSP (Bottom up & Optimised)
    // memset(dp, -1, sizeof(dp));
    // pr(psp(s, l, r));
    // pr(pspOptimised(s, l, r));
    // displaydp(6, 6);
    // pr(counter);


    //*-----------------------|E S T|-----------------------

    // string s = "T^F&F^T|F";
    // int l = 0, r = s.length()-1;

    ////? EST (Recursive)
    // pr(est_recusive(s, l, r, 'T'));

    ////? EST (Bottom up)
    // pr(est(s, l, r, 'T'));
    // for(auto x : mp) cout<<x.first.first<<" "<<x.first.second<<" - "<<x.second<<"\n";


    //*-----------------------|Scr str|-----------------------
    string a = "great";
    string b = "rgate";
    // string b = "rgtae";
    // string b = "aetrg";
    // string b = "arteg";
    // string b = "rartg";

    ////? SrcStr (Recursive)
    // if(scramble_string(a, b)) cout<<"Scrambled\n";
    // else cout<<"Not Scrambled\n";

    ////? SrcStr (Bottom)
    if(scramble_string_BottomUp(a, b)) cout<<"Scrambled\n";
    else cout<<"Not Scrambled\n";
}