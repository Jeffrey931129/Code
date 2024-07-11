#include <climits>
#include <iostream>
#include <set>

using namespace std;

int main() {
    int N, M;

    cin >> N >> M;

    set<int, less<int>> ascend_arr;
    set<int, greater<int>> descend_arr;

    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        ascend_arr.insert(tmp);
        descend_arr.insert(tmp);
    }

    for (int i = 0; i < M; i++) {
        int query;
        cin >> query;

        int ans1 = ascend_arr.lower_bound(query) == ascend_arr.end() ? *ascend_arr.rbegin() : *ascend_arr.lower_bound(query);
        int ans2 = descend_arr.lower_bound(query) == descend_arr.end() ? *descend_arr.rbegin() : *descend_arr.lower_bound(query);
        int ans = ans1 - query < query - ans2 ? ans1 : ans2;
        cout << ans << endl;
    }

    return 0;
}

