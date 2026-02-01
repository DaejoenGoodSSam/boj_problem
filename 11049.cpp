#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
#include<limits.h>
using namespace std;
pair<int,int> arr[501];
int cost[501][501];

int money (int k,int N) {
    if (k == N) {
        cost[k][N] = 0;
        return cost[k][N];
    }
    if (k == N - 1) {
        cost[k][N] = arr[k].first * arr[k].second * arr[N].second;
        return cost[k][N];
    }
    if (cost[k][N] != -1) {
        return cost[k][N];
    }
    int tttmp;
    tttmp = INT_MAX;
    for (int i = k; i < N; i++) {
        tttmp = min(tttmp, money(k,i) + money(i + 1, N) + arr[k].first * arr[i].second * arr[N].second);
    }
    cost[k][N] = tttmp;
    return cost[k][N];
}
 
int main () { ios_base::sync_with_stdio(0); cin.tie(0);
int N;
cin >> N;
    for(int i = 1; i < N + 1; i++) {
        cin >> arr[i].first >> arr[i].second;
    }
    memset(cost, -1 , sizeof(cost));
    cout << money(1,N);
}