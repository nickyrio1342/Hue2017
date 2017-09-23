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
        if (g[i][k] < g[j][k]) return false;
    }
    return true;
}

bool cmp(const vector<int> &a, const vector<int> &b) {
    REP(i, m) {
        if (a[i] < b[i]) return true;
        if (a[i] > b[i]) return false;
    }
    return true;
}

int main() {
    freopen("VECTOR2.inp","r",stdin);
    freopen("VECTOR2.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>m;
    int x;
    REP(i, n) {
        REP(j, m) {
            cin>>x;
            g[i].push_back(x);
        }
        sort(g[i].begin(), g[i].end());
        g[i].push_back(i);
    }
    sort(g, g + n, cmp);

    int ans = 0;
    REP(i, n) f[i] = 1;
    FOR(i, 1, n - 1) FOR(j, 0, i - 1) {
        if (great(i, j)) {
            f[i] = max(f[i], f[j] + 1);
        }
        ans = max(ans, f[i]);
    }
    cout<<ans<<endl;
    REP(i, n) {
        e[f[i]].push_back(g[i][m]);
    }
    FOR(i, 1, ans) {
        for(int x : e[i]) cout<<x + 1<<' ';
        cout<<endl;
    }
}

