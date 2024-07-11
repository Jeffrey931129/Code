#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

void print(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

int Find(map<int, queue<int>> &mp, int target) {
    if(mp.count(target)) {
        int ret = mp[target].front(); // return the smallest index for type "target"
        mp[target].pop();
        if(mp[target].empty()) mp.erase(target);
        return ret;
    }
    else {
        return -1;
    }
}

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> job_set[m]; // job sets for m little cutes
    for(int i = 0; i < m; i++) {
        int k;
        cin >> k;
        job_set[i].resize(k);
        for(int j = 0; j < k; j++) {
            cin >> job_set[i][j];
        }
    }
    map<int, queue<int>> job_type;// job types for n jobs
    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        job_type[t].push(i);
    }

    vector<int> ans(n);// job i is taken by ans[i]
    for(int i = 0; i < m; i++) {
        vector<int> job_taken_list;
        for(int j = 0; j < job_set[i].size(); j++) {
            int index = Find(job_type, job_set[i][j]);
            if(index == -1) {// cannot find a job he wants
                print(ans);
                return 0;
            }
            job_taken_list.push_back(index); // which jobs he has taken
        }

        // update answer
        for(int j = 0; j < job_taken_list.size(); j++) {
            ans[job_taken_list[j]] = i + 1;
        }
    }

    // output answer
    print(ans);
}

