#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int N;
int M;
int R;
int k=1;
int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int tmp;
    int ttmp;
    cin >> N >> M >> R;
    vector <vector<int>> adl (N);
    vector <int> table (N,0);
    vector <int> stack;
    vector <int> skip (N,0);

    for (int i = 0; i < M; i++ ) {
        cin >> tmp >> ttmp;
        adl[tmp - 1].push_back(ttmp);
        adl[ttmp - 1].push_back(tmp);
    }

    for (int i = 0; i < N; i++) {
        sort(adl[i].begin(), adl[i].end());
    }
    stack.push_back(R);

    table [R - 1] = k++;
    if (adl[R - 1].empty()) {
        stack.pop_back();
        goto result;
    }


    while(!stack.empty()) { 
        int pop = 1;
        int node = stack.back();
        for(int i = skip[node-1]; i < adl[node - 1].size(); i++) {
            int adj_node = adl[node - 1][i];
            if (table[adj_node - 1] == 0) {
                table[adj_node - 1] = k++;
                stack.push_back(adj_node);
                skip[node - 1] = i;
                pop = 0;
                break;      
            }
        }
        if (pop) {
            stack.pop_back();
        }
    }

result:
    for (int i = 0; i < N; i++) {
        cout << table[i] << "\n";
    }
}
