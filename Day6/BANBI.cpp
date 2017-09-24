#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1010
#define pp pair<int, int>

using namespace std;

int used[N][N][5], dp[N][N][5];
int m, n;
int ans, a[N][N];

int go(int k, int x, int y) {
    if (x == 0 || x > m || y == 0 || y > n) return 0;
    if (used[x][y][k]) return dp[x][k][y];
    if (k == 1) {
        if (a[x][y] == 0) {
            dp[x][y][k] += go(k, x, y + 1);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 1) {
            dp[x][y][k] += go(3, x + 1, y);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 2) {
            dp[x][y][k] += go(4, x - 1, y);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
    }
    if (k == 2) {
        if (a[x][y] == 0) {
            dp[x][y][k] += go(k, x, y - 1);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 1) {
            dp[x][y][k] += go(4, x - 1, y);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 2) {
            dp[x][y][k] += go(3, x + 1, y);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
    }
    if (k == 3) {
        if (a[x][y] == 0) {
            dp[x][y][k] += go(k, x + 1, y);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 1) {
            dp[x][y][k] += go(2, x, y - 1);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 2) {
            dp[x][y][k] += go(1, x, y + 1);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
    }
    if (k == 4) {
        if (a[x][y] == 0) {
            dp[x][y][k] += go(k, x - 1, y);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 1) {
            dp[x][y][k] += go(1, x, y + 1);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
        if (a[x][y] == 2) {
            dp[x][y][k] += go(2, x, y - 1);
            used[x][y][k] = 1;
            return dp[x][y][k];
        }
    }
    return 0;
}
string s[N];

int main() {
    freopen("BANBI.inp","r",stdin);
    freopen("BANBI.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n;
    FOR(i, 1, m) cin>>s[i];
    FOR(i, 1, m) FOR(j, 1, n) a[i][j] = s[i][j - 1] - '0';
    ans = -1;
    int p, k;
    FOR(i, 1, m) FOR(j, 1, n) FOR(k, 1, 4) dp[i][j][k] = 1;
    memset(used, 0, sizeof used);
    FOR(i, 1, m) {
        int t = go(1, i, 1);
        if (t > ans) {
            p = 1;
            k = i;
            ans = t;
        }
    }
    FOR(i, 1, m) {
        int t = go(2, i, n);
        if (t > ans) {
            p = 2;
            k = i;
            ans = t;
        }
    }
    FOR(i, 1, n) {
        int t = go(3, 1, i);
        if (t > ans) {
            p = 3;
            k = i;
            ans = t;
        }
    }
    FOR(i, 1, n) {
        int t = go(4, m, i);
        if (t > ans) {
            p = 4;
            k = i;
            ans = t;
        }
    }
    cout<<p<<' '<<k;
}

