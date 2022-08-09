// sort array
#include<iostream>
#include<vector>
using namespace std;
#define pl(x) cout<<(x)<<"\n";
#define ps(x) cout<<(x)<<" ";
#define  dbg(x) cout<<'d'<<'b'<<'g'<<'-'<<'>'<<x<<endl;

void insert(vector<int> &v, int temp)
{
    for(int i=0; i<v.size(); i++) ps(v[i])
    pl("");
    if(v.size()==0 || v[v.size()-1]<=temp)
    {
        v.push_back(temp);
        return;
    }
    int val = v[v.size()-1];
    v.pop_back();
    insert(v, temp);
    v.push_back(val);
    return;
}
void sort(vector<int> &v)
{
    if(v.size()-1)
    {
        int temp = v[v.size()-1];
        v.pop_back();
        sort(v);
        insert(v, temp);
    }
    return;
}
int main()
{
    vector<int> v{4, 3, 2, 1, 0};
    int n = v.size();
    sort(v);
    for(int i=0; i<n; i++) ps(v[i])
}