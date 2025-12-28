#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int N;
vector <int> ser;
int backtrank (int k, int sum) {
    if (k == N-1) {
        if (sum == ser[N-1] && sum == 0) {
            return 2;
        }

        else if (sum == 0 || sum == ser[N-1]) {
            return 1;
        } 
        
        return 0;
    }
    
    return backtrank (k+1,sum) + backtrank (k+1,sum-ser[k]);
}

int main () {ios_base ::
    sync_with_stdio(0);
    cin. tie(0);
    int tmp;
    int Sum;
    cin >> N;
    cin >> Sum;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        ser.push_back(tmp);
    }
    int ttmp;
    if (Sum == 0) {
        ttmp = backtrank(0,Sum) - 1;
    }
    else {
        ttmp = backtrank(0,Sum);
    }
    cout << ttmp;
}