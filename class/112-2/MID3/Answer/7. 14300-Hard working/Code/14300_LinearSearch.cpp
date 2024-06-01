#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void print(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i] << endl;
    }
}

int Find(vector<int> &v, int target) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == target) return i;
    }
    return -1;
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
    vector<int> job_type(n);// job types for n jobs
    for(int i = 0; i < n; i++) {
        cin >> job_type[i];
    }

    vector<int> ans(n);// job i is taken by ans[i]
    for(int i = 0; i < m; i++) {
        vector<int> job_taken_list;
        for(int j = 0; j < job_set[i].size(); j++) {
            int index = Find(job_type, job_set[i][j]);
            if(index == -1) {//didn't find the job he wants
                print(ans);
                return 0;
            }
            job_taken_list.push_back(index); // which jobs he has taken
            job_type[index] = -1; // this job has been taken
        }

        // update answer
        for(int j = 0; j < job_taken_list.size(); j++) {
            ans[job_taken_list[j]] = i + 1;
        }
    }

    // output answer
    print(ans);
}

