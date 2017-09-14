#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

int n, h, a[N];
const long long MOD = 1e9;
long long f[N][4];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>h;
    REP(i, n) cin>>a[i];
    if (*max_element(a, a + n) >= h) {
        cout<<"0\n0";return 0;
    }
    switch (n) {
    case 0: {
        cout<<"1\n1";return 0;
    }
    case 1: {
        cout<<"2\n2";return 0;
    }
    case 2: {
        cout<<"2\n4";return 0;
    }
    default: {
        int t = max(a[n - 1], max(a[n - 2], a[n - 3]));
        if (t == a[n - 1] || t == a[n - 2]) {
            cout<<"2\n";
        } else cout<<"1\n";
        f[3][1] = 1;
        f[3][2] = 1;
        f[3][3] = 2;
        FOR(i, 4, n + 2) {
            f[i][1] = f[i - 1][2];
            f[i][2] = f[i - 1][3];
            f[i][3] = (f[i - 1][1] + f[i - 1][2] + f[i - 1][3]) % MOD;
        }
        cout<<f[n + 2][3];
    }
    }
}

