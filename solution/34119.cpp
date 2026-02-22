#include <bits/stdc++.h>
using namespace std;

struct SegTree {
    int n;
    vector<long long> sum;  // 방어력 합
    vector<int> cnt;        // 개수

    SegTree(int n_) : n(n_) {
        sum.assign(4 * n, 0);
        cnt.assign(4 * n, 0);
    }

    void update(int idx, long long val, int node, int l, int r) {
        if (l == r) {
            sum[node] = val;
            cnt[node] = (val > 0 ? 1 : 0);
            return;
        }
        int mid = (l + r) >> 1;
        if (idx <= mid) update(idx, val, node * 2, l, mid);
        else            update(idx, val, node * 2 + 1, mid + 1, r);
        sum[node] = sum[node * 2] + sum[node * 2 + 1];
        cnt[node] = cnt[node * 2] + cnt[node * 2 + 1];
    }

    void update(int idx, long long val) {
        update(idx, val, 1, 0, n - 1);
    }

    // 합이 P 이상이 되도록 하는 최소 개수 반환, 불가능하면 -1
    int minCountFor(long long P) {
        if (sum[1] < P) return -1;  // 전체 합이 부족
        long long remain = P;
        int node = 1, l = 0, r = n - 1;
        int used = 0;

        while (l != r) {
            int left = node * 2;
            int right = node * 2 + 1;
            int mid = (l + r) >> 1;

            if (sum[left] > remain) {
                // 왼쪽 구간 안에서만 P를 채울 수 있음
                node = left;
                r = mid;
            } else {
                // 왼쪽 전부를 사용해도 아직 부족
                remain -= sum[left];
                used += cnt[left];
                node = right;
                l = mid + 1;
            }
        }

        // leaf
        if (remain > 0) {
            // 이 노드 하나로 남은걸 채울 수 있는지 확인
            if (sum[node] >= remain) {
                used += cnt[node];  // leaf면 1
                return used;
            } else {
                return -1;
            }
        } else {
            // 딱 맞게 채운 경우
            return used;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;
    vector<long long> D(N);
    for (int i = 0; i < N; ++i) cin >> D[i];

    // 방어력 내림차순 정렬
    vector<pair<long long,int>> sorted;
    sorted.reserve(N);
    for (int i = 0; i < N; ++i)
        sorted.push_back({D[i], i});
    sort(sorted.begin(), sorted.end(),
         [](auto &a, auto &b){ return a.first > b.first; });

    // 원래 인덱스 -> 정렬 후 인덱스
    vector<int> pos(N);
    for (int i = 0; i < N; ++i) {
        int origIdx = sorted[i].second;
        pos[origIdx] = i;
    }

    // X별로 쿼리 묶기 (0-based X-1)
    vector<vector<pair<long long,int>>> queries(N);
    vector<long long> P(Q);
    vector<int> X(Q);
    for (int j = 0; j < Q; ++j) {
        int x;
        long long p;
        cin >> x >> p;
        --x;          // 0-based
        X[j] = x;
        P[j] = p;
        queries[x].push_back({p, j});
    }

    SegTree st(N);
    vector<int> ans(Q, -1);

    // 왼쪽에서 오른쪽으로 진행하며 prefix 확장
    for (int i = 0; i < N; ++i) {
        // 위치 i의 건초더미 활성화
        st.update(pos[i], D[i]);

        // X = i 인 쿼리 처리
        for (auto &qp : queries[i]) {
            long long p = qp.first;
            int idx = qp.second;
            ans[idx] = st.minCountFor(p);
        }
    }

    for (int j = 0; j < Q; ++j)
        cout << ans[j] << '\n';

    return 0;
}