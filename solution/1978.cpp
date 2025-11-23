#include <iostream>
#include <vector>
using namespace std;

vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};

int main() {
	int N, result = 0;
	int temp = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int isPrime = 1;
        cin >> temp;

		for (int div = 0; div < 11 && prime[div] < temp ; div++) {
			if (temp % prime[div] == 0) {
				isPrime = 0;
                break;
            }
		}
        if (isPrime) {
            result ++;
        }
        
        if (temp == 1) {
            result --;
        }

	}
	cout << result << '\n';
}

