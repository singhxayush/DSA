#include<bits/stdc++.h>
using namespace std;

typedef long long        ll;
typedef vector<ll>       vll;
#define tc ll tt; cin>>tt; while(tt--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

ll findmex(vll v, ll N)
{
	ll min = *min_element(v.begin(), v.end()), max = *max_element(v.begin(), v.end());
    ll h[max] = {0}, mex;
    if(min>0) return 0;
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
int main(){
fastio
    tc{
        ll n, k, i=0, j=0; cin >> n >> k;
        ll a[n]; vll pos;
        for(i=0; i<n; i++){
            cin>>a[i];
            if(a[i]==0) pos.push_back(i);
        }
        vector<vector<ll>> v;
        for (ll i=0; i <n; i++)
        {
            for (ll j=i; j<n; j++)
            {
                vll v1;
                for(ll k=i; k<=j; k++)
                v1.push_back(a[k]);
                v.push_back(v1);
            }
        }
        vll res;
        for(i=0; i<n*(n+1)/2; i++){
            if(pos[j]==i){
                res.push_back(0);
                j++;
                continue;
            }
            else
            res.push_back(findmex(v[i], v[i].size()));
        }
        // sort(res.begin(), res.end());
        for(auto & elm : res)cout<<elm<<" ";
        cout<<endl;
        // cout<<res[k-1]<<"\n";
    }
}