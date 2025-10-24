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
    ll first_min = LLONG_MAX;
    ll second_min = LLONG_MAX;
    ll f_ans = 0;
    while(j<vec.size()){
        if(vec[j] <= first_min){
            second_min = first_min;
            first_min = vec[j];
        }
        else if(vec[j] < second_min){
            second_min = vec[j];
        }
        j++;
        if((j-i)<k){
            continue;
        }
        else if((j-i)==k){
            f_ans^=first_min;
            if(vec[i]==first_min){
                first_min = LLONG_MAX;
                second_min = LLONG_MAX;
                for(ll idx = i+1; idx < j; idx++){
                    if(vec[idx] <= first_min){
                        second_min = first_min;
                        first_min = vec[idx];
                    }
                    else if(vec[idx] < second_min){
                        second_min = vec[idx];
                    }
                }
            }
            i++;
        }
    }
    cout<<f_ans<<"\n";
    return 0;
}