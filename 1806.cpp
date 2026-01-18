#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int> number;
int h = 0;
int t = 0;
int sum = 0;
int ttmp = 10001;
void two_pointer (int N, int S) {
    sum = number[0];
    while (t < N) {
        if (sum < S) {
            t++;
            if (t == N) {
                return;
            } 
            sum = sum + number[t];
        }
        else if (sum >= S) {
            if (t - h + 1 < ttmp) {
                ttmp = t - h + 1;
            }
            sum = sum - number[h];
            h++;
        }
    
    }
}
int main () {ios_base :: sync_with_stdio(0);
    int N,S;
    cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;
        number.push_back(tmp);
    }
        two_pointer (N,S);
        if (ttmp == 10001) {
            cout << 0;
        }
        else {
            cout << ttmp;
        }

}