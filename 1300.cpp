#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
long long int N;
long long int k;
int main () {ios_base::sync_with_stdio(0);
    cin.tie(0);
cin >> N;
cin >> k;
long long int low = 1;
long long int high = N*N;
long long int i;
long long int j;
long long int ttmp=1;
long long int mid=1;
    while (low<=high) { 
        long long int tmp=0;
        mid = (low + high) / 2;
        for (i=1;i<N+1;i++)  {
            if (mid >= i && mid < i*N) {
                tmp = tmp + (mid / i);
            }
            else if (mid >= i*N) {
                tmp = tmp + N;
            }
        }
        if (tmp >= k ) {
            ttmp = mid;
            cout << ttmp << "\n";
            high = mid - 1;
        }
        else if (tmp < k) {
            low = mid + 1;
        }
    }
    cout << ttmp << "\n";
}