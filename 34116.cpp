#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    int a;
    cin >> a;
    int k;
    int m=100000000;
    int M=-100000000;
    int S=-100000000;
    int A=-100000000;
    int fS=100000000;
    int fA=100000000;
    int correct;
    vector<pair<int,int>> points(a); 
    for (k=0;k<a;k++) {
        int x,y;
        cin >> x >> y;
        points[k] = {x,y};
    }
    for (k=0;k<a;k++) {
        m= min (points[k].second,m);
        M= max (points[k].second,M);
        S= max (points[k].second-points[k].first,
            S);
        A= max (points[k].second+points[k].first,
            A);
        fS= min (points[k].second-points[k].first,
            fS);
        fA= min (points[k].second+points[k].first,
            fA);
    }
    correct= min (A+S-2*m,-fS-fA+2*M);
    cout << correct;
}