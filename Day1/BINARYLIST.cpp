#include <bits/stdc++.h>

using namespace std;
#define N 10010

int n, kmax, need;
int f[N][N];


int TRY(int i, int k) {
    if (f[i][k] != 0) return f[i][k];
    if (i == n + 1) {
        f[i][k] = 1;
        return 1;
    }
    int ans = 0;
    if (k != kmax) ans = TRY(i + 1, k + 1);
    if (ans < need) ans += TRY(i + 1, 0);
    if (ans > 1e9) ans = 1e9 + 5;
    f[i][k] = ans;
    return ans;
}

void FIND(int i, int k) {
    if (i == n + 1) return;
    if (k == kmax) {
        cout<<"1 ";
        FIND(i + 1, 0);
    }
    else {
        if (need <= f[i + 1][k + 1]) {
            cout<<"0 ";
            FIND(i + 1, k + 1);
        } else {
            cout<<"1 ";
            need -= f[i + 1][k + 1];
            FIND(i + 1, 0);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>need>>kmax;
    kmax--;
    long long maxx = TRY(1, 0);
    if (maxx < need) {
        cout<<-1;
        return 0;
    }
    FIND(1, 0);
}
