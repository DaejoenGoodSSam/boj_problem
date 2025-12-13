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
    for (int x=(sum/K);x>-1;x--) {
        int ssum=0;
        for (int i=0;i<K;i++) {
            ssum=ssum+(n[i]/x);
        }
        if (x==0) {
            cout << "0" <<"\n";
            return 0;
        }
        else if (ssum==N) {
            cout << x <<"\n";
            return 0;
        }
    }
}