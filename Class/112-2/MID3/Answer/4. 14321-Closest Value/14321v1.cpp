#include <bits/stdc++.h>
using namespace std;

int n, m, k;

void solve(){
    cin >> n >> m;
    set<int> s;
    for(int i = 0; i < n; i++){
        cin >> k;
        s.insert(k);
    }
    while(m--){
        cin >> k;
        auto it = s.upper_bound(k);
        if(it == s.begin()) //all greater than k
            cout << *it << endl;
        else if(it == s.end()) //not found; all less than or equal to k
            cout << *(--it) << endl;
        else{
            int a = *it;
            it--;
            int b = *it;
            cout << (a - k < k - b ? a : b) << endl;
        }
    }
}

int main(void){
    ios_base::sync_with_stdio(false); cin.tie(0);
    int t = 1;
    while(t--)
        solve();
    return 0;
}

