#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>prime;
int sum;
int h = 0;
int t = 0;
int ttmp = 0;
void two_pointer (int N) {
    sum = 2;
    while (t < N) {
        if (sum < N) {
            t++;
            if (t == prime.size()) {
                return;
            } 
            sum = sum + prime[t];
        }
        else if (sum > N) {
            sum = sum - prime[h];
            h++;
        }
        else {
            ttmp++;
            sum = sum - prime[h];
            h++;
        }
    
    }
}
int main () {ios_base :: sync_with_stdio;
    int N;
    cin >> N;
    prime.push_back(2);
    for (int i = 3; i < N + 1; i+=2) {
        int isPrime = 1;
        for (int j = 0; j < prime.size(); j++) {
            if (i%prime[j] == 0) {
                isPrime = 0;
                break;
            }
        }
        if (isPrime == 1) {
            prime.push_back(i);
        }
    }
    if (N < 2) {
        cout << 0;
    }
    else {
        two_pointer(N);
        cout << ttmp;
    }
}
