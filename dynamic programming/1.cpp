#include"DynamicProgramming.h"

int main()
{
    int n = 7;
    int w = 9;
    int wt[n] = {3, 1, 7, 4, 2, 8, 6};
    int val[n] = {1, 4, 9, 3, 10, 4, 6};


    // Normal recursive Knapsack - Brute force
    // cout<<knapsack_recursive(wt, val, w, n)<<"\n";


    // Recursive memoization Knapsack
    // memset(dp_knapsack, -1, size/of(dp_knapsack));
    // knapsack_dp_memoization(wt, val, w, n);
    // cout<<dp_knapsack[n][w]<<"\n";


    // Iterative bottom Up knapsack
    // cout<<knapsack_dp_bottomup(wt, val, w, n)<<"\n";


    int arr[7] = {3, 4, 3, 5, 2, 2, 7};
    cout<<subsetsum(arr, 7, 24)<<"\n";
    // cout<<equal_partition(arr, 7);

    // cout<<numofSubsets(arr, 7, 20);
}