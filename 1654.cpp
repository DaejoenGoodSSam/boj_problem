#include <iostream>
#include <vector>

using namespace std;
vector<int> n;
int K;
int N;
int ssum (int a) {
    int Z=0;
    for (int i = 0; i < K; i++) {
        Z = Z + (n[i]/a);
    }
    return Z;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> K;
    cin >> N;
    long long int sum = 0;
    
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        n.push_back(tmp);
        sum = sum + n[i];
    }
    int start = 0;
    int end = sum/N;
    while (start <= end) {
        int mid = (end + start)/2;
        if (ssum(mid) >= N) {
            if (ssum(mid+1) < N) {
                cout << mid << "\n";
                break;
            }
            else {
                end = mid + 1;
            }
        }
        else if (ssum(mid) < N) {
            start = mid - 1;
        }
    }       
}