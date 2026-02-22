#include <iostream>
#include <vector>
#include <algorithm>

#define BG ios::sync_with_stdio(false); cin.tie(0);
using namespace std;

const int INF = 1e9; 
// dp[a][b] a의 일자 b의 일자에서의 최소비용
// dp[n][n] 을 출력
vector<vector<int>> dp;
vector<bool> va, vb;

int n;
int p1,p3,p5,pp;

void update_a(int i, int j) {
    dp[i+1][j] = min(dp[i+1][j], dp[i][j]+p1);
    for(int k=1; k<=3; k++) {
        dp[i+k][j] = min(dp[i+k][j], dp[i][j]+p3);
    }
    for(int k=1; k<=5; k++) {
        dp[i+k][j] = min(dp[i+k][j], dp[i][j]+p5);
    }       
}

void update_b(int i, int j) {
    dp[i][j+1] = min(dp[i][j+1], dp[i][j]+p1);
    for(int k=1; k<=3; k++) {
        dp[i][j+k] = min(dp[i][j+k], dp[i][j]+p3);
    }
    for(int k=1; k<=5; k++) {
        dp[i][j+k] = min(dp[i][j+k], dp[i][j]+p5);
    }              
}

void update_pp(int i, int j) {
    for(int a=0; a<=4; a++) {
        for(int b=0; b<=4; b++) {
            dp[i+a][j+b] = min(dp[i+a][j+b], dp[i][j]+pp);
        }
    }
}

int main(void) {
    BG
    
    cin >> n;

    string sa, sb;
    cin >> sa >> sb;

    cin >> p1 >> p3 >> p5 >> pp;

    va.resize(n+2, false);
    vb.resize(n+2, false);
    dp.resize(n+6, vector<int>(n+6, INF));

    for(int i=1; i<=n; i++){
        if(sa[i-1]=='1') va[i]=true;
        if(sb[i-1]=='1') vb[i]=true;
    }    

    dp[0][0] = 0;

    // i : a, j : b
    for(int i=1; i<=n+1; i++) {
        bool aa=va[i];
        for(int j=1; j<=n+1; j++) {
            bool bb=vb[j];

            // 관광 없는날 
            if(!aa) dp[i][j-1] = min(dp[i][j-1], dp[i-1][j-1]);
            if(!bb) dp[i-1][j] = min(dp[i-1][j], dp[i-1][j-1]);

            // 개별티켓 업데이트
            if(aa) update_a(i-1, j-1);              
            if(bb) update_b(i-1, j-1);            

            // pp는 같은 날 사용해야함.
            if(i==j) update_pp(i-1,j-1);

        }      
    }

    cout << dp[n][n] << endl;


    for (int i = 0; i < n+1; i++) {
        for (int j = 0; j < n+1; j++) {
            cout << dp[j][i] <<" ";
        }
        cout << endl;
    }

    return 0;
}