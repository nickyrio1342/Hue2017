#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001
#define pp pair<int, int>

using namespace std;

int n, m, f[N];
vector<int> g[N], e[N];

bool great(int i, int j) {
    REP(k, m) {
        if (g[i][k] <= g[j][k]) return false;
    }
    return true;
}

int BIT[100010];

void update(int u, int val) {
    for(; u <=n; u += u &-u) BIT[u] = max(BIT[u], val);
}

int get(int u) {
    int ans = 0;
    for(; u>0; u -= u&-u) ans = max(ans, BIT[u]);
    return ans;
}
int a[100010], b[100010];

void solve2() {
    REP(i, n) { cin>>a[i]; b[i] = a[i];}
    sort(b, b + n);
    int ans = 0;
    REP(i, n) a[i] = lower_bound(b, b + n, a[i]) - b + 1;
    REP(i, n) {
        int t = get(a[i] - 1) + 1;
        ans = max(ans, t);
        update(a[i], t);
    }
    cout<<ans;
}
int main() {
    freopen("VECTOR.inp","r",stdin);
    freopen("VECTOR.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    int x;
    if (m == 1) {
        solve2();
        return 0;
    }
    REP(i, n) {
        REP(j, m) {
            cin>>x;
            g[i].push_back(x);
        }
        sort(g[i].begin(), g[i].end());
    }
    int ans = 0;
    REP(i, n) f[i] = 1;
    FOR(i, 1, n - 1) REP(j, i) {
        if (great(i, j)) {
            f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout<<ans;
}

