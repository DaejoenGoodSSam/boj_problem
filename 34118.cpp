#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;
#define MAX 2006
int trv [MAX][MAX];
vector<int> va, vb;
int N;
int p1, p3, p5, p;


void print_trv() {
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            cout << trv[i][j] << " ";
        }
        cout << endl;
    }
}

void update_a (int i, int j) {
    int prev = 0;
    if (i != 0) {
        prev = trv[i - 1][j];
    }
    trv[i][j] = min(prev + p1, trv[i][j]);
    for (int x = 0; x < 3; x++) {
        trv[i + x][j] = min(prev + p3, trv[i + x][j]);
    }
    for (int y = 0; y < 5; y++) {
        trv[i + y][j] = min(prev + p5, trv[i + y][j]);
    }
}
void update_b (int i, int j) {
    int prev = 0;
    if (j != 0) {
        prev = trv[i][j - 1];
    }
    trv[i][j] = min(prev + p1, trv[i][j]);
    for (int x = 0; x < 3; x++) {
        trv[i][j + x] = min(prev + p3, trv[i][j + x]);
    }
    for (int y = 0; y < 5; y++) {
        trv[i][j + y] = min(prev + p5, trv[i][j + y]);
    }
}
void update_p (int i, int j) {
    for (int x = 0; x < 4; x++) {
        for (int y = 0; y < 4; y++) {
            trv[i + x][i + y] = min(trv[i - 1][j - 1] + p, trv[i + x][i + y]);
        }
    }
}
int main () {
    cin >> N;
    string sa, sb;
    cin >> sa >> sb;
    cin >> p1 >> p3 >> p5 >> p;
    int result = 0;


    va.resize(N + 1, 0);
    vb.resize(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        if (sa[i - 1]=='1') va[i] = 1;
        if (sb[i - 1]=='1') vb[i] = 1;
    }

    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            trv[i][j] = INT_MAX;
        }
    }
   
    trv[0][0] = 0;
    //print_trv();
    for (int i = 0; i < N + 1; i++) {
        for (int j = 0; j < N + 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            if (i == j) {
                update_p(i , j);
            }

            if (va[i] == 1) {
                update_a(i , j);
            }
            else if (va[i] == 0) {
                if (i > 0) {
                    trv[i][j] = trv[i - 1][j];
                } else {
                    trv[i][j] = 0;
                }
            }

            if (vb[j] == 1) {
                update_b(i , j);
            }
            else if (vb[j] == 0) {
                if (j > 0) {
                    trv[i][j] = trv[i][j - 1];
                } else {
                    trv[i][j] = 0;
                }
            }
        }
    }
    print_trv();

}