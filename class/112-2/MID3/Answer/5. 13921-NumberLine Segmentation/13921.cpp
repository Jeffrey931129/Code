#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
set<ll> s;

void solve() {
    cin >> n;
    for (ll i = 0, ty, x; i < n; ++i) {
        cin >> ty >> x;
        if (ty == 1) {
            if (s.find(x) == s.end())
                s.insert(x);
            else
                s.erase(x);
        } else {
            auto r = s.lower_bound(x+1);
            auto l = prev(r); //returns an iterator pointing to the previous element
            cout << (r == s.end() || r == s.begin() ? -1 : *r - *l) << "\n";
        }
    }
}

int main(void) {
    ios_base::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}


