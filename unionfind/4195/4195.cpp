#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include <unordered_map>
using namespace std;


unordered_map <string, string> um;
unordered_map <string, int> nums;

int N  = 0;
int K;

string find (string a) {
    if (a == um[a]) {
        return a;
    }
    return um[a] = find (um[a]);
}
void Union (string a, string b) {
    string pa = find(a);
    string pb = find(b);

    if (pa == pb) {
        return;
    }

    nums[pa] = nums[pb] + nums[pa];
    um[pb] = pa;
}


int main () {
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> K;
        string tmp, ttmp;
        um.clear();
        nums.clear();
        for (int i = 0; i < K; i++) {
            cin >> tmp >> ttmp;
            if (um.find(tmp) == um.end()) {
                um[tmp] = tmp;
                nums[tmp] = 1;
            }
            if (um.find(ttmp) == um.end()) {
                um[ttmp] = ttmp;
                nums[ttmp] = 1;
            }
            Union(tmp, ttmp);
            cout << nums[find(tmp)] << "\n";
        }

    }
}