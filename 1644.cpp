#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

vector<int>prime;
int sum;
int h = 0;
int t = 0;
int ttmp = 0;
void two_pointer (int N) {
    sum = 2;
    while (t < prime.size()) {
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
int main () {ios_base :: sync_with_stdio;cin.tie(0);
    int N;
    cin >> N;
    int arr[N + 1];
    fill(arr, arr + N + 1, true);
    arr[1] = false;
    for (int i = 2; i < sqrt(N); i++) {
        if (arr[i] == false) {
            continue;
        }
        for (int j = i*i; j < N + 1; j+=i) {
            arr[j] = false;
        }
    }
    for (int i = 2; i < N + 1; i++) {
        if (arr[i] == true) {
            prime.push_back(i);
            cout << i << " ";
        }
    } 
    
    if (N == 1) {
        cout << 0;
    }
    else {
        two_pointer(N);
        cout << ttmp;
    }
}
