#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001

#define pp pair<int, int>

using namespace std;
int n, k, a[100010], f[N][N];

void solve1() {
    memset(f, 0, sizeof f);
    FOR(i, 1, n) FOR(j, 1, n) {
        if (abs(a[i] - j) <= k) f[i][j] = f[i - 1][j - 1] + 1;
        else f[i][j] = max(f[i - 1][j], f[i][j - 1]);
    }
    cout<<f[n][n];
}
int BIT[100010];
vector<int> e;

void update(int u, int val) {
    for(; u<= n; u += u &-u) BIT[u] = max(BIT[u], val);
}


int get(int u) {
    int ans = 0;
    for(; u> 0; u -= u &-u) ans = max(ans, BIT[u]);
    return ans;
}
void solve2() {
    int ans = 0;
    FOR(i, 1, n) FORD(j, k, -k)
        if (a[i] + j > 0 && a[i] + j <= n)
            e.push_back(a[i] + j);
    for (int x : e) {
        int t = get(x - 1) + 1;
        ans = max(ans, t);
        update(x, t);
    }
    cout<<ans;
}
int main() {
    freopen("L1L2K.inp","r",stdin);
    freopen("L1L2K.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    FOR(i, 1, n) cin>>a[i];
    if (n <= 1e3) {
        solve1();
    } else solve2();
}

