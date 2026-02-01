#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;
vector<int>weight;
vector<int>possible(40001,-1);
int dp_matrix[15001][31];
int tttmp;
int N;
void money(int a, int b) {
    if (b > N - 1) {
        return;
    }
    if (dp_matrix[abs(a)][b] == 1) {
        return;
    }
    tttmp = weight[b];
    money(a - tttmp, b + 1);
    money(a, b + 1);
    money(a + tttmp, b + 1);
    possible[abs(a)] = 1;
    dp_matrix[abs(a)][b] = 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int tmp;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        weight.push_back(tmp);
    }
    memset(dp_matrix, -1 , sizeof(dp_matrix));
    money(0, 0);
    int T;
    cin >> T;
    int ttmp;
    for (int i = 0; i < T; i++) {
        cin >> ttmp;
        if (possible[ttmp] == 1) {
            cout << "Y "; 
        }
        else {
            cout << "N ";
        }
    }
}