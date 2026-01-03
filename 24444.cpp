#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

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
    queue <int> q;
    for (int i = 0; i < M; i++ ) {
        cin >> tmp >> ttmp;
        adl[tmp - 1].push_back(ttmp);
        adl[ttmp - 1].push_back(tmp);
    }
    for (int i = 0; i < N; i++) {
        sort(adl[i].begin(),adl[i].end());
    }
    q.push(R);
    table [R - 1] = 1;
    while(!q.empty()) { 
        if (adl[R - 1].empty()) {
            break;
        }
        int tttmp = q.front();
        for(int i = 0; i < adl[tttmp-1].size(); i++) {
            if (table[adl[tttmp-1][i]-1] == 0) {
                k++;
                q.push(adl[tttmp-1][i]);
                table[adl[tttmp-1][i]-1] = k;    
            }
        }
        q.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << table[i] << "\n";
    }
}