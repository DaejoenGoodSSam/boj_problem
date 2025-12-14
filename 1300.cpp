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
int low = 1;
int high = N*N;
int i;
int j;
    while (low<=high) { 
        int x=0;
        int y=0;
        int mid = (low + high) / 2;
        for (i=1;i<high+1;i++)  {
            for (j=1;j<high+1;i++)
            if (i*j<mid) {
                x++;
                y++;
            }
            else if (i*j == mid) {
                y++;
            }
        }
        if (x <= k-1 && k-1 <= y) {
            cout << mid;
            break;
        }
        else if (y<k-1) {
            int high=mid+1;
        }
        else if (x>k-1){
            int low=mid-1;
        }
    }

}