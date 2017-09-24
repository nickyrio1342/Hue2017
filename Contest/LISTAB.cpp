#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001000
#define pp pair<int, int>

using namespace std;

struct data {
    long long x, y, val;

    operator < (const data &a) {
        return (val < a.val) || (val == a.val && (pp(x, y) < pp(a.x, a.y)));
    }
};

vector<data> e;
int m, n;
vector<int> vec;
vector< vector<int> > dp, a;
const int d[4] = {1, 0, -1, 0};
const int c[4] = {0, -1, 0, 1};

bool inside(int u, int v) {
    return u >= 0 && u < m && v >= 0 && v < n;
}

int main() {

    freopen("LISTAB.inp","r",stdin);
    freopen("LISTAB.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n;
    //CreateTable
    REP(i, m) {
        dp.push_back(vec);
        REP(j, n) dp[i].push_back(1);
    }
    a = dp;
    //
    int x;
    REP(i, m) REP(j, n) {
        cin>>a[i][j];
        e.push_back(data({i, j, a[i][j]}));
    }
    sort(e.begin(), e.end());

    int ans = 0;
    REP(i, e.size()) {
        data x = e[i];
        REP(j, 4) {
            int u = x.x + d[j];
            int v = x.y + c[j];
            if (inside(u, v) && a[u][v] < a[x.x][x.y]) {
                dp[x.x][x.y] = max(dp[x.x][x.y], dp[u][v] + 1);
            }
        }
        ans = max(ans, dp[x.x][x.y]);
    }
    cout<<ans;
}

