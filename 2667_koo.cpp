#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
#define MAX 26
void print_vector (vector<int> ret) {
    for (auto elem : ret) {
        cout << elem << " " ;
    }
    cout << endl;
}

void init_matrix (int matrix[MAX][MAX], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j]  = 0;
        }
    }
}

void print_matrix (int matrix[MAX][MAX], int size) {
    cout << "=== print_matrix ===" << endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}



int main() {ios_base::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    string arr[MAX];
    int owned[MAX][MAX];
    vector<int> result(N*N,0);
    vector<int> last;
    
    init_matrix(owned,N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }


    int group = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int prop_left = 0;
            int prop_up = 0;
            if (arr[i][j] != '1') {
                continue;
            }
            // if up exist, and they already participate in group
            // then propagate
            if (i > 0 && owned[i-1][j] != 0) {
                prop_up = owned[i-1][j]; // propagate from up
            } 
             // if left exist, and they already participate in group
            // then propagate
            if (j > 0 && owned[i][j-1] != 0) {
                prop_left = owned[i][j-1]; // propagate from left
            }

            if (prop_left != 0 && prop_up !=0) {
                // merge from left and up
                cout << "merge with " <<prop_up <<" "<< prop_left << endl;
                result[prop_up] = result[prop_up] + result[prop_left] + 1;
                owned[i][j] = prop_up;
                result[prop_left] = 0;
            } else if (prop_left != 0) {
                cout << "ddddd2" << endl;
                result[prop_left] ++;
                owned[i][j] = prop_left;
            } else if (prop_up != 0) {
                cout << "ddddd3" << endl;
                result[prop_up] ++;
                owned[i][j] = prop_up;
            } else {
                // new group
                cout << "ddddd4" << endl;
                group = i*N + j;
                result[group] = 1;
                owned[i][j] = group;
            }
            print_vector(result);
        }
    }

    print_matrix(owned, N);

    int ttmp = 0;
    for (int i = 0; i < N*N; i++) {
        if (result[i] > 0) {
            ttmp++;
            last.push_back(result[i]);
        }
    }

    sort(last.begin(),last.end());

    cout << ttmp << "\n";
    for (int i = last.size() - 1; i > -1; i--) {
        cout << last[i] << endl;
    }
}