#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) cin >> vec[i];

    unordered_map<ll, ll> freq;
    set<ll> s;
    for (ll i = 0; i <= n; i++) s.insert(i);

    ll i = 0;
    for (ll j = 0; j < n; j++) {
        freq[vec[j]]++;
        if (freq[vec[j]] == 1) {
            s.erase(vec[j]);
        }

        if (j - i + 1 == k) {
            cout << *s.begin() << " "; 

            freq[vec[i]]--;
            if (freq[vec[i]] == 0) {
                s.insert(vec[i]); 
            }
            i++;
        }
    }
    cout<<"\n";
    return 0;
}
