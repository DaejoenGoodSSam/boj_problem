#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

#define BG ios::sync_with_stdio(false); cin.tie(0);
using namespace std;
using ll = long long;

int main(void) {
    BG
    
    int n;
    cin >> n;
    
    // 각 y별 um[y] pair 로 x의 최소 최대를 pair 로 저장
    unordered_map<int, pair<int, int>> um;

    for(int i=0; i<n; i++) {
        int x, y;
        cin >> x >> y;

        if(um.find(y) == um.end()) {
            um[y] = {x,x};
        } else {
            um[y].first = min(um[y].first, x);
            um[y].second = max(um[y].second, x);
        }
    }

    vector<int> vy;
    for(auto e : um) {
        vy.push_back(e.first);
    }
    sort(vy.begin(), vy.end());

    // simul 1 위 직각 
    int by = vy[0];
    int l = um[by].first;
    int r = um[by].second;
    
    for(int i=1; i<vy.size(); i++) {
        int y = vy[i];
        int h = y - by;        
        
        int lx = um[y].first;
        int rx = um[y].second;

        if(lx<l+h) l=lx-h;
        if(rx>r-h) r=rx+h;
    }
    int res1 = r-l;
    

    // simul 2 아래 직각
    int ty = vy[vy.size()-1];
    l = um[ty].first;
    r = um[ty].second;
    
    for(int i=vy.size()-2; i>=0; i--) {
        int y = vy[i];
        int h = ty-y;        
        
        int lx = um[y].first;
        int rx = um[y].second;

        if(lx<l+h) l=lx-h;
        if(rx>r-h) r=rx+h;
    }
    int res2 = r-l;

    cout << min(res1, res2);
    return 0;
}