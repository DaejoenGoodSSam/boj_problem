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
    for (int i=0;i<K;i++) {
        int tmp;
        cin >> tmp;
        n.push_back(tmp);
    }
    int sum=0;
    for (int i=0;i<K;i++) {
        sum=sum+n[i];
    }
    for (int x=(sum/K);x>0;x--) {
        int ssum=0;
        for (int i=0;i<K;i++) {
            ssum=ssum+(n[i]/x);
        }
        if (ssum==N) {
            cout << x <<"\n";
            return 0;
        }
    }
}