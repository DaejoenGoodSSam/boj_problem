#include <iostream>
#include <vector>

using namespace std;

vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31};

int main () {
    int t;
    int i;
    int k;
    int j;
    int l=0;
    cin >> t;
    for (i = 0; i < t; i++) {
        cin >> k;

        for (j = 0; j < 11; j++) {
            if (k%prime[j] == 0 && k != prime[j]) {
                l++;
                break;
            }
            else if (k==1) {
                l++;
                break;
            }
        }
    }
    cout << t-l;
}