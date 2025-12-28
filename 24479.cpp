#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int M;
int R;
int k=1;
int main () {ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    int ttmp;
    cin >> N >> M >> R;
    vector <vector<int>> adl (N);
    vector <int> table (N,0);
    vector <int> stack;
    for (int i = 0; i < M; i++ ) {
        cin >> tmp >> ttmp;
        adl[tmp - 1].push_back(ttmp);
        adl[ttmp - 1].push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        sort(adl[i].begin(),adl[i].end());
    }
    stack.push_back(R);
    table [R - 1] = 1;
    while(!stack.empty()) { 
        if (adl[R].empty()) {
            break;
        }
        int pop = 1;
        for(int i = 0; i < N; i++) {
            if (table[adl[stack.back()-1][i]-1] == 0) {
                k++;
                R = adl[R-1][i];
                stack.push_back(R);
                table[R - 1] = k;
                cout << R << "\n";
                pop = 0;
                break;      
            }
        }
        if (pop) {
            stack.pop_back();
        }
    }
    for (int i = 0; i < N; i++) {
        cout << table[i] << "\n";
    }
}
