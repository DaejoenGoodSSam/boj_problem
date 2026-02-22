#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;


int weight [31];
int bead [7];
int dp[40001];
int dp_matrix[15001][30];
int N;
int K;


void solve (int w, int i) {
    if ( N < i) {
        return;
    }

    if (dp_matrix[w][i]) {
         return;
    }

    cout << "weight " << w << " " << " i " << i << endl;
    solve (w + weight[i], i+1);
    solve (abs(w - weight[i]), i+1);
    solve (w, i+1);
    dp[w] = 1;
    dp_matrix[w][i] = 1;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    memset(dp, 0, sizeof(dp));
    memset(dp_matrix, 0, sizeof(dp_matrix));
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
    }
    cin >> K;
    for (int i = 0; i < K; i++) {
        cin >> bead[i];
    }

    solve (0, 0);
    
    for (int i = 0; i < K; i++) {
        if (dp[bead[i]]) {
            cout << "Y ";
        } else {
            cout << "N ";
        }
    }
}