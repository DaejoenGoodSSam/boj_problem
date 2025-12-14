#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int gcd(int a, int b) {
    if (b==0) {
        return a;
    }
    return gcd(b,a%b);

}


int main () {
    int i;
    int t;
    int a;
    int b;
    int c;
    int j;
    int f;
    cin >> i;
    if (i==2) {
        cin >> a >> b;
        j=gcd(a,b);
    }
    else {
        cin >> a >> b >> c;
        j=gcd(gcd(a,b),c);

    }
   for (f=1; f<j+1; f++) {
    if (j%f == 0) {
        cout << f << "\n";
    }
   } 
    

}
