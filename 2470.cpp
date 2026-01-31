#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

vector<int> acid;
int main() {ios_base :: sync_with_stdio(0);
    int N;
    cin >> N;
    int tmp;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        acid.push_back(tmp);
    }
    sort(acid.begin(), acid.end());
    int l = 0;
    int j = N - 1;
    int ttmp = acid[0] + acid[N - 1];
    int tttmp = acid[0];
    int ttttmp = acid[N - 1];
    while(l < j) {
        if (abs(acid[l] + acid[j]) < abs(ttmp)) {
            ttmp = acid[l] + acid[j];
            tttmp = acid[l];
            ttttmp = acid[j];
            if (ttmp == 0) {
                break;
            }
            else if (ttmp > 0) {
                j--;
            }
            else {
                l++;
            }
        }
        else {
            if (acid[l] + acid[j] > 0) {
                j--;
            }
            else {
                l++;
            }
        }
    }
    cout << tttmp << " " << ttttmp;
}