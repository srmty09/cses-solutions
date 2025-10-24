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
    ll i = 0;
    ll j = 0;
    ll sum = 0;
    ll f_ans = 0;
    while(j<vec.size()){
        sum+=vec[j];
        j++;
        if((j-i)<k){
            continue;
        }
        else if((j-i)==k){
            f_ans^=sum;
            sum-=vec[i];
            i++;
        }        
    }
    cout<<f_ans<<"\n";
    return 0;
}