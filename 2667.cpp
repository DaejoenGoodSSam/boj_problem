#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 26


int main() {ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string arr[MAX];
    int owned[MAX][MAX];
    vector<int> result(N*N,0);
    vector<int> last;

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    if (arr[0][0] == '1') {
        owned[0][0] = 0;
        result[0]++;
    }

    for (int i = 1; i < N; i++) {
        char tmp = arr[0][i];
        if (tmp == '1') {
            if (arr[0][i - 1] == '1') {
                owned[0][i] = owned[0][i-1];
                result[owned[0][i - 1]]++;
            }
            else if (arr[0][i - 1] == '0') {
                owned[0][i] = i;
                result[owned[0][i]]++;
            }
        }
    }

    for (int j = 1; j < N; j++) {
        char tmp = arr[j][0];
        if (tmp == '1') {
            if (arr[j - 1][0] == '1') {
                owned[j][0] = owned[j-1][0];
                result[owned[j - 1][0]]++;
            }
            else if (arr[j - 1][0] == '0') {
                owned[j][0] = j;
                result[owned[j][0]]++;
            }
        }
    }

    for (int i = 1; i < N; i++) {
        for (int j = 1; j < N; j++) {
            if (arr[i][j] == '1') {
                if (arr[i - 1][j] == '1' && arr[i][j - 1] == '0') {
                    owned[i][j] = owned[i - 1][j];
                    result[owned[i - 1][j]]++;
                }
                else if (arr[i][j - 1] == '1' && arr[i - 1][j] == '0') {
                    owned[i][j] = owned[i][j - 1];
                    result[owned[i][j - 1]]++;
                }
                else if (arr[i][j - 1] == '0' && arr[i - 1][j] == '0') {
                    owned[i][j] = j + i*N;
                    result[owned[i][j]]++;
                }
                else {

                    if (owned[i-1][j] == owned[i][j-1]) {
                        owned[i][j] = owned[i-1][j];
                        result[owned[i][j]] ++;
                    } else {
                        owned[i][j] = owned[i][j - 1];

                        for (int k = j + 1; k < N; k++) {
                            if (owned[i - 1][k] == owned[i - 1][j]) {
                                owned[i - 1][k] = owned[i][j-1];
                            }
                        }
                        result[owned[i][j - 1]] = result[owned[i][j - 1]] + result[owned[i - 1][j]];
                        result[owned[i - 1][j]] = 0;
                        result[owned[i][j - 1]]++;
                    }
                }

            }        
        }
    }
    int ttmp = 0;
    for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
            if (result[owned[i][j]] > 0) {
                ttmp++;
                last.push_back(result[owned[i][j]]);
                result[owned[i][j]] = 0;
            }
        }
    }

    sort(last.begin(),last.end());

    cout << ttmp << "\n";
    for (int i = 0; i < last.size(); i++) {
        cout << last[i] << endl;
    }
}