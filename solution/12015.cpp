#include <iostream>
#include <vector>
using namespace std;


vector<int> num;
int N;

int binary_search(int value) {
    int start = 0;
    int end = num.size() - 1;
    while(start <= end) {
        int mid = (start + end)/2;

        if (num[mid] < value) {
            start = mid + 1;
        } else if (num[mid])
    }
}

int main () {
    cin >> N;
    num.push_back(INT_MIN);
    
    for (int i = 0; i < N; i++) {
        int tmp;
        cin >> tmp;

    }

}