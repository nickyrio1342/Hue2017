#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 210

#define pp pair<int, int>

using namespace std;
int n;
vector<long long> a, b;
long long f[N][N][N];
int main() {
    freopen("GAME.in","r",stdin);
    freopen("GAME.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    int x;
    REP(i, n) {
        cin>>x;
        if (x) a.push_back(x);
    }
    REP(i, n) {
        cin>>x;
        if (x) b.push_back(x);
    }
    int na = a.size();
    int nb = b.size();
    REP(i, N) REP(j, N) REP(k, N) f[i][j][k] = -1e18;
    REP(i, n - na + 1) REP(j, n - nb + 1) REP(k, na) {
        int l = i + k - j;
        if (l < 0 || l >= nb) { // Can't put b[l] at pos i + k => must put 0
            f[i][j][k] = 0;
            continue;
        }
        //Pos i + k : (0, 0)
        if (i && j) f[i][j][k] = max(f[i][j][k], f[i - 1][j - 1][k]);
        //Pos i + k : (0, b[l])
        if (i) f[i][j][k] = max(f[i][j][k], f[i - 1][j][k]);
        //Pos i + k : (a[k], 0)
        if (j && k) f[i][j][k] = max(f[i][j][k], f[i][j - 1][k - 1]);
        //Pos i + k : (a[k], b[l])
        if (k) f[i][j][k] = max(f[i][j][k], f[i][j][k - 1] + a[k] * b[l]);
        else f[i][j][k] = max(f[i][j][k], a[k] * b[l]);
    }
    cout<<f[n - na][n - nb][na - 1];
}

