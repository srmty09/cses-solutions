#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, k;
    cin >> n >> k;
    vector<ll> vec(n);
    for (ll i = 0; i < n; i++) {
        cin >> vec[i];
    }

    ll i = 0, j = 0;
    map<ll, ll> mpp; 
    vector<ll> ans;

    while (j < n) {
        mpp[vec[j]]++;
        if (j - i + 1 == k) {
            ans.push_back(mpp.size());
            mpp[vec[i]]--;
            if (mpp[vec[i]] == 0) {
                mpp.erase(vec[i]);
            }
            i++;
        }
        j++;
    }

    for (auto &it : ans) {
        cout << it << endl;
    }

    return 0;
}
