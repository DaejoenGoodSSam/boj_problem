#include <iostream>
#include <algorithm>
#include <climits>

using namespace std;

int t, k;
int pref[501];
long long memo[501][501];

int rangeSum(int l, int r) {
    return pref[r] - pref[l - 1];
}

long long solve(int x, int y) {
    if (x == y) return 0;

    long long &ret = memo[x][y];
    if (ret != -1) return ret;

    ret = LLONG_MAX;
    long long cost = rangeSum(x, y);

    for (int mid = x; mid < y; mid++) {
        ret = min(ret, solve(x, mid) + solve(mid + 1, y) + cost);
    }
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t;
    while (t--) {
        cin >> k;

        pref[0] = 0;
        for (int i = 1; i <= k; i++) {
            int a;
            cin >> a;
            pref[i] = pref[i - 1] + a;
        }

        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                memo[i][j] = -1;
            }
        }

        cout << solve(1, k) << "\n";
    }
    return 0;
}