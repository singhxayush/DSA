#include<bits/stdc++.h>
using namespace std;

typedef long long        ll;
typedef long double      ld;
typedef vector<int>      vi;
typedef vector<ll>       vll;
typedef vector<string>   vst;
typedef set<int>         si;
typedef set<ll>          sll;
typedef map<ll,ll>       mll;
typedef map<string,ll>   msl;
typedef pair<ll,ll>      pll;
typedef vector<pll>      vpll;
typedef forward_list<ll> fll;

#define ip(x) int x; cin >> x;
#define all(x) x.begin(), x.end()
#define logab(a, b) log(a)/log(b)
#define tc int tt; cin>>tt; while(tt--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll findmex(vll v, ll N)
{
	ll min = *min_element(v.begin(), v.end()), max = *max_element(v.begin(), v.end());
    cout<<"min"<<min<<" max"<<max<<endl;
    ll h[max] = {0}, mex;
    if(min>0) return 0;
    else{
        for (ll i = 0; i < N; i++)
        h[v[i]] = 1;

        for (ll i = 0; i < max; i++) {
            if (h[i] == 0) {
                mex = i;
                break;
            }
        }
        return mex;
    }
}
int main(){
fastio
    ll n, i, j, k; cin>>n;
    ll a[n];
    // for(auto & elm : a) cin>>elm;


    for(i=0; i<n; i++)
    for(j=i; j<n; j++){
        vll vec;
        for(k=i; k<=j; k++){
        vec.push_back(a[k]);
        }
        
    }

    // for(i=0, j=0; i<vec.size(); i+=n-j){
    //     vll temp;
    //     temp.insert(temp.end(), vec.begin()+i, vec.end());
    //     for(auto & elm1 : temp)cout<<elm1<<" ";
    //     cout<<endl;
    //     j++;
    // }
}