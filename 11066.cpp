#include<iostream>
#include<vector>
#include<algorithm>
#include <string.h>
#include<limits.h>

using namespace std;
int arr[501][501];
vector<int>file;
vector<int>result;
vector<int> sssum;



int sum(int a, int b) {
    if (a > 0) {
        return (sssum[b] - sssum[a - 1]);
    }
    else {
        return sssum[b];
    }
}
int money(int a, int b) {
    //cout << "money["<< a << "]["<< b << "]" <<endl;
    int min = INT_MAX;

    if (a == b) {
        arr[a][b] = 0;
        return arr[a][b];
    }
    if (a + 1 == b) {
        arr[a][b] = file[a] + file[b];
        return arr[a][b];
    }


    for (int i = 0; i < b - a; i++) {
        int tttmp = money(a, a + i) + money(a + i + 1, b) + sum(a , b);

        if (tttmp < min) {
            min = tttmp;
        }
    }
    arr[a][b] = min;
    return arr[a][b];
}

int main() {ios_base :: sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    int K;
    int tmp;
    int ttmp;
    for (int i = 0; i < T; i++) {
        cin >> K;
        for(int j = 0; j < K; j++) {
            cin >> tmp;
            file.push_back(tmp);
        }
        int ssum = 0;
        for (int i = 0; i < K; i++) {
            ssum = ssum + file[i];
            sssum.push_back(ssum);
        }
        memset(arr, -1, sizeof(arr));
        result.push_back(money(0 ,K - 1));
        file.clear();
        sssum.clear();
    }
    for (int i = 0; i < T; i++) {
        cout << result[i] << "\n";
    }
}