#include <iostream>
#include <vector>

using namespace std;
int main () {
    int M;
    int N;
    int min;
    int sum=0;
    int cnt=0;
    cin >> M >> N;
    int weeknumber=0;

    for (int k=M; k<N+1; k++) {
        weeknumber = 0;
        for (int i=1; i<k+1; i++ ) {
            if (k%i == 0) {
                weeknumber++;
            }
            
        }

        if (weeknumber == 2) {
            cnt++;
            if (cnt == 1) {
                min = k;
            }
            sum += k; 
        }
    }
    if (cnt==0) {
        cout << -1 << "\n";
    }
    else {
    cout << sum << "\n";
    cout << min << "\n";
}
}