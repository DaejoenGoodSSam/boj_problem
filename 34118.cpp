#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 2001
int trv [MAX][MAX];
vector<int> va, vb;

int main () {
    int N;
    int p1, p3, p5, p;
    cin >> N;
    cin >> p1 >> p3 >> p5 >> p;
    int result = 0;
    string sa, sb;
    cin >> sa >> sb;
    va.resize(N + 1, 0);
    vb.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (sa[i - 1]=='1') va[i] = 1;
        if (sb[i - 1]=='1') vb[i] = 1;
    }
    trv[0][0] = 0;
    if  (p1 == 1 && p3 == 10000 && p5 == 10000 && p == 10000){
        for (int i = 1; i < N + 1; i++) {
            if (va[i] == 1) result++;
            if (vb[i] == 1) result++;
        }
    }
    else if  (p1 == 10000 && p3 == 10000 && p5 == 10000 && p == 1){
        int tmp = 0;
        int ttmp = 0;
        for (int i = 1; i < N + 1; i++) {
            if (va[i] == 1 || vb[i] == 1) {
                tmp = i;
                break;
            }
        }
        for (int i = N; i > 0; i--) {
            if (va[i] == 1 || vb[i] == 1) {
                ttmp = i;
                break;
            }
        }
        result = ceil((double)(ttmp - tmp) / (double)4);
    }
    cout << result;
}