#include"slidingwindow.h"
int main()
{
    //? Maximum sum subarray of size K
    // int a[] = {1, 4, 2, 5, 3, 2, 7, 8, 4, 9, 2, 1};
    // int n = sz(a);
    // int k = 3;
    // cout<<Maximum_Sum_Subarray_of_size_K(n, a, k)<<"\n";


    //? First Negative Number in every Window of Size K
    // if not present print 0
    int a[] = {1, -1, 2, -4, 3, -2, 9, 8, 4, -3, 2, -1};
    int n = sz(a);
    int k = 4;
    First_Negative_Number_in_every_Window_of_Size_K(n, a, k);
}