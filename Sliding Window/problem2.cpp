#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<int> vec;
void generator(ll x, ll a,ll b,ll c,ll n){
    vec.push_back(x);
    for(ll i = 1; i<n;i++){
        vec.push_back(((vec[i-1]*a)+b)%c);
    }
}
int main(){
    ll n,k,a,b,c,x;
    cin>>n>>k;
    cin>>x>>a>>b>>c;
    generator(x,a,b,c,n);
    deque<int> dq;
    // ll i = 0;
    // ll j = 0;
    // set<ll> st;
    ll ans = 0;
    // while(j < static_cast<ll>(vec.size())){
    //     st.insert(vec[j]);
    //     j++;
    //     if((j-i)==k){
    //         ans^=*st.begin();
    //         st.erase(vec[i]);
    //         i++;
    //     }
    // }
    // cout<<ans<<endl;
    for(ll i = 0;i<n;i++){
        while(!dq.empty() and dq.front()<=(i-k)){
            dq.pop_front();
        }
        while(!dq.empty() and vec[dq.back()]>vec[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>=k-1){
            ans^=vec[dq.front()];
        }
    }
    cout<<ans<<endl;
    return 0;
}