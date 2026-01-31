#include <iostream>
#include <vector>

using namespace std;
vector<int> n;
int K;
int N;
int num_of_line (int length) {
    int ret = 0;
    for (int i = 0; i < K; i++) {
        ret = ret + (n[i]/length);
    }
    return ret;
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

    unsigned int start = 1;
    unsigned int  end = sum/N;
    unsigned int ret = 0;

    while (start <= end) {
        unsigned int mid = (end + start)/2;
        int tmp = num_of_line(mid);
        if (tmp >= N) {
            ret = max(ret, mid);
            start = mid + 1;
        } else if (tmp < N) {
            end = mid - 1;
        }
    }
    
    cout << ret << "\n";
}