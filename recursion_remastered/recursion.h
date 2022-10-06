#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;


void oneton(int n)
{
    if(n==0) return;
    oneton(n-1);
    cout<<n<<" ";
}
void ntoone(int n)
{
    if(n==0) return;
    cout<<n<<" ";
    ntoone(n-1);
}

// // sorting using recursive insertion sort

// void insert_r(vector<int> &v, int key) {
//     if(v.size()==0 || v.back()<=key){ 
//         v.push_back(key);
//         return; 
//     }
//     int val = v.back();
//     v.pop_back();
//     insert_r(v, key);
//     v.push_back(val);
//     return;
// }
// void sortarray(vector<int> &v) {
//     if(v.size()==1) return;
//     int key = v.back();
//     v.pop_back();
//     sortarray(v);
//     insert_r(v, key);
// }

int top;
void insert_r(int a[], int key, int top) 
{
    cout<<"top :"<<top<<endl;
    dbg(a[top])

    if(top==0 || a[top]<=key) {
        a[top] = key;
        return;
    }
    int val = a[top--];
    insert_r(a, key, top);
    a[++top] = val;
    return;
}
void sortarray(int a[], int n) {
    if(n==0) return;
    sortarray(a, n-1);
    top = n-1;
    int key = a[top];
    insert_r(a, key, top);
}