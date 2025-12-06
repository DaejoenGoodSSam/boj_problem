#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
vector<int> n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;
    int N;
    int M;
    cin >> N;
    for(k=0;k<N;k++) {
        int tmp;
        cin >> tmp;
        n.push_back(tmp);
    }
    cin >> M;
    for(k=0;k<M;k++) {
        int ttmp;
        cin >> ttmp;
        for(int i=0;i<N;i++) {
            if (n[i]==ttmp) {
                cout << "1" << "\n";
                break;
            }
            else if (i == N-1 && n[i]!= ttmp) {
                cout << "0" << "\n";
                break;
            }

        }

    }
}