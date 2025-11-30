#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int a;
    int k;
    int m;
    int M;
    int S;
    int A;
    int fS;
    int fA;
    int correct;
    cin >> a;
    vector<pair<int,int>> points(a); 
    for (k=0;k<a;k++) {
        int x,y;
        cin >> x >> y;
        points[k] = {x,y};
    }
    for (k=0;k<a-1;k++) {
        m= min (points[k].second,points[k+1].second);
        M= max (points[k].second,points[k+1].second);
        S= max (points[k].second-points[k].first,
            points[k+1].second-points[k+1].first);
        A= max (points[k].second+points[k].first,
            points[k+1].second+points[k+1].first);
        fS= min (points[k].second-points[k].first,
            points[k+1].second-points[k+1].first);
        fA= min (points[k].second+points[k].first,
            points[k+1].second+points[k+1].first);
    }
    correct= min (A+S-2*m,-fS-fA+2*M);
    cout << correct;
}