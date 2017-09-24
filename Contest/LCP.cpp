#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001
#define M 100
#define pp pair<int, int>

using namespace std;

int n, m;
int a[M][N], pos[N][M], f[N];

bool check(int u, int v) {
    FOR(i, 1, m) {
        if (pos[u][i] > pos[v][i]) return false;
    }
    return true;
}

int main() {
    freopen("LCP.inp","r",stdin);
    freopen("LCP.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    FOR(i, 1, m) FOR(j, 1, n) cin>>a[i][j];
    FOR(i, 1, m) FOR(j, 1, n) pos[a[i][j]][i] = j;
    int ans = 0;
    FOR(i, 1, n) {
        f[i] = 1;
        FOR(j, 1, i - 1) {
            if (check(a[1][j], a[1][i])) f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout<<ans;
}

