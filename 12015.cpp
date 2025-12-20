#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector <int> increasing;
int ttmp = 0;
int binary_search(int value) {
    int start = 0;
    int end = increasing.size() - 1;
    while(start <= end) {
        int mid = (start + end) / 2;
        if (value <= increasing[mid]) {
            ttmp = mid;
            end = mid - 1;
        }
        else if (value > increasing[mid]) {
            start = mid + 1;
        }
    } 
    return ttmp;
}
long long int length;
long long int value;
int tmp;
int N;
int i;
int main () {ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    cin >> i;
    increasing.push_back(i);
    for ( i = 1; i < N; i++) {
        cin >> tmp;
        if (tmp > increasing.back()) {
            increasing.push_back(tmp);
        }
        else if (tmp < increasing.back()) {
            increasing[binary_search(i)] = tmp;
        }
            for (int k = 0; k<increasing.size(); k++) {
        cout << increasing[k] << "\n";
        }
    }
    cout << increasing.size() << "\n";
}
    