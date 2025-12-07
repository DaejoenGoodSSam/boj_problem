#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<pair<int,int>>ct;
vector<int> n;

int N;
int M;
int search (int a) {
    int mid;
    int start = 0;
    int end = ct.size()-1;
    
    while (start <= end)
    {
        mid = (start + end)/2; 
    
        if (a == ct[mid].first) {
            return ct[mid].second;
        } else if (a > ct[mid].first) {
            start = mid+1;
        } else if (a < ct[mid].first) {
            end = mid-1;
        }
    }
    return 0;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> N ;
    for (int i=0;i<N;i++) {
        int tmp;
        cin >> tmp;
        n.push_back(tmp);
    }
    sort(n.begin(), n.end());
    int k=1;
    for (int i=0;i<N;i++) {
        if (i==N-1) { 
            ct.push_back({n[i],k});
            break;
        } else if (n[i] == n[i+1]) {
            k++;
        } else {
            ct.push_back({n[i],k});
            k=1;
        }
    
    }
    cin >> M;
    for(k=0;k<M;k++) {
        int ttmp;
        cin >> ttmp;
        
        cout << search(ttmp) << " ";
    }
    cout << "\n";
}
