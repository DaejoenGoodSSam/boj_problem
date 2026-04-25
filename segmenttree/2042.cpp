#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int N;
ll num[1000001];
ll segtree [4000004];

void print_segtree(int k) {
    int newline = 1;
    cout << "---- print segtree ----\n";
    for (int i = 1; i < k+1; i ++) {
        cout << segtree[i] << " ";
        if (i == newline) {
            cout << "\n";
            newline = 2*newline+1;
        }
    }
    cout << "\n----------------------\n";
}

ll init(int segidx, int start, int end) {

    // leaf 도달하면 기록
    if (start == end) {
        segtree[segidx] = num[start];
        return segtree[segidx];
    }
    
    int mid = (start+ end)/2;
    // leaf가 아니면 left child와 right child 초기화후 합 기록
    return segtree[segidx] = init(segidx*2, start, mid) + init(segidx*2 + 1, mid + 1, end);
}
void update(ll diff, int numidx, int segidx, int start, int end) {
    segtree[segidx] += diff;
    if (start == end) {
        return;
    }

    int mid = (start+ end)/2;
    if (numidx <= mid) {
        update(diff,numidx, 2*segidx, start, mid);
    }
    else {
        update(diff,numidx,2*segidx + 1, mid + 1, end);
    }

}

ll subsum (int segidx, int start, int end, int sum_s, int sum_e) {
    if (start == sum _s && end == sum_e) {
        return segtree[segidx];
    }
    
    int mid = (start+ end)/2;
    if ()
    
    return subsum(segidx*2, start, mid, sum_s, mid) + subsum(segidx*2 + 1, mid + 1, end,);

}


int main() {ios_base :: sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    int M,K;
    cin >> M >> K;
    for (int i = 1; i < N + 1; i++) {
        cin >> num[i];
    }

    init(1,1,N);
    print_segtree(4*N);
    
    for (int i = 0; i < M + K; i++) {
        int tmp;
        cin >> tmp;
        if (tmp == 1) {
            int idx;
            ll NUM;
            cin >> idx >> NUM;
            ll diff = NUM - num[idx];
            num[idx] = NUM;
            update(diff, idx, 1, 1, N);
            print_segtree(4*N);
        }
        else {

        }
    }

}