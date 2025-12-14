#include <iostream>
#include <vector>

using namespace std;
vector<int> n;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int K;
    int N;
    cin >> K;
    cin >> N;
    long long int sum = 0;
    for (int i = 0; i < K; i++) {
        int tmp;
        cin >> tmp;
        n.push_back(tmp);
        sum = sum + n[i];
    }
    for (int x = (sum/N); x > -1; x--) {
        long long int ssum = 0;
        if (x==0) {
            cout << "0" <<"\n";
            return 0;
        }
        for (int i = 0; i < K; i++) {
            ssum=ssum+(n[i]/x);
            if (ssum >= N) {
            cout << x <<"\n";
            return 0;
        }
        }
         
    
}
}