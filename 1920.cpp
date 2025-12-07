#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;
vector<int> n;
int N;
int M;
int size (int a) {
    int mid;
    int start = 0;
    int end = N-1;
    while (start <= end)
    {
        mid = (start + end)/2; 
    
        if (a == n[mid]) {
            return 1;
        } else if (a > n[mid]) {
            start = mid+1;
        } else if (a < n[mid]) {
            end = mid-1;
        }
    }
    return 0;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int k;

    cin >> N;
    for(k=0;k<N;k++) {
        int tmp;
        cin >> tmp;
        n.push_back(tmp);
    }
    sort(n.begin(), n.end());
/*
    for (int i = 0; i < N; i++ ) {
        cout << n[i] <<" ";
    }
    cout << "\n";
*/
    cin >> M;
    for(k=0;k<M;k++) {
        int ttmp;
        cin >> ttmp;
        
        cout << size(ttmp) << "\n";
    }
}