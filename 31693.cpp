#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
vector<int>number;
vector<int>llog;

int main() {ios_base::sync_with_stdio(0); cin.tie(0);
    int N;
    cin >> N;
    int tmp;
    int tttmp;
    int ttmp = 0;
    for (int i = 0; i < N; i++) {
        cin >> tmp;
        number.push_back(tmp);
    }
    llog.push_back(0);
    for (int i = 0; i < N - 1; i++) {
        
        if (ceil(log2((double)number[i] / (double)number[i + 1]) + llog[i]) < 0) {
            llog.push_back(0);
        }
        else {
            llog.push_back(ceil(log2((double)number[i] / (double)number[i + 1]) + llog[i]));
        }
        ttmp = ttmp + llog[i + 1];
    }
    
    for (int i = 0; i < N; i++) {
        cout << llog[i] << " ";
    } 
    cout << ttmp;
}