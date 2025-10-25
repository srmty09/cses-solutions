#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> vec;

void generator(ll x, ll a,ll b,ll c,ll n){
    vec.push_back(x);
    for(ll i = 1; i < n; i++){
        vec.push_back(((vec[i-1]*a)+b)%c);
    }
}

int main(){
    ll n, k, a, b, c, x;
    cin >> n >> k;
    cin >> x >> a >> b >> c;

    generator(x, a, b, c, n);

    ll i = 0, j = 0;
    ll ans = 0;
    ll win_xor = 0;

    while(j < n){
        win_xor ^= vec[j];
        j++;

        if((j - i) == k){
            ans ^= win_xor;        
            win_xor ^= vec[i];     
            i++;
        }
    }

    cout << ans << endl;
    return 0;
}
