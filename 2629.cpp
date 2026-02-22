#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstring>

using namespace std;
int weight[31];
vector<int>possible(40001,-1);
int dp_matrix[15001][31];
int N;
void money(int a, int b) {
<<<<<<< Updated upstream
    int tttmp;
    if (b > N) {
=======
    cout << "[money] a " << a << " " << " b " << b  << endl;
    if (b == N) {
        possible[a] = 1;
>>>>>>> Stashed changes
        return;
    }
    if (dp_matrix[a][b] == 1) {
        return;
    }
    tttmp = weight[b];
    cout << "[log] a " << a << " " << " b " << b << " tttmp " << tttmp << endl;
    cout << " ----> abs(a-tttmp) : " << abs(a-tttmp)  << " a :" << a << " a+tttmp : "<< a+tttmp << endl;
    money(abs(a - tttmp), b + 1);
    money(a + tttmp, b + 1);
    money(a, b + 1);
    possible[a] = 1;
    dp_matrix[a][b] = 1;
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> N;
    int tmp;
<<<<<<< Updated upstream
    for (int i = 0; i < N + 1; i++) {
        if (i >= N) {
            weight.push_back(0);
        }
        else {
        cin >> tmp;
        weight.push_back(tmp);
        }
=======
    memset(weight, 0, sizeof(weight));
    for (int i = 0; i < N; i++) {
        cin >> weight[i];
>>>>>>> Stashed changes
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