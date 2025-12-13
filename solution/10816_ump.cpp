#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int n,m;
vector<int> arr;

map<int,int> mm;

int main() {
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);

    cin >> n;

    for(int i = 0; i<n ;i++) {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    sort(arr.begin(),arr.end());
    
    for(int i = 0; i < n; i++) {
        auto iter = mm.find(arr[i]);
        if (iter != mm.end()) {
            mm[arr[i]] ++;
        } else {
            mm.insert(make_pair(arr[i],1));
        }
    }

    /*
    for (auto iter = mm.begin(); iter != mm.end(); iter++) {
        cout << iter -> first << " " << iter->second << "\n";
    }
    */

    cin >> m;
    for(int i = 0; i < m; i++) {
        int x;
        cin >> x;

        auto iter = mm.find(x);
        if (iter != mm.end()) {
            cout << iter->second << " ";
        } else {
            cout << "0 ";
        }

    }
    cout << "\n";

}