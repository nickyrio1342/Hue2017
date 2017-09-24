#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 80
#define pp pair<long long, long long>

using namespace std;

struct data {
    long long h, t, pos;

    operator < (const data &a) {
        return h > a.h;
    }
}s[N];
long long n, current[N], maxt, ss[N];
vector<long long> e[4];

long long ans;

vector<int > dp[N][30 * N], trace[N][30 * N];
//vector<int> vec;

void Trace(int k, int u, long long t1, long long t2) {
    if (k == u) {
        e[2].push_back(s[u].pos);
        REP(i, u) e[1].push_back(s[i].pos);
        Trace(k, u + 1, t1, t2);
        return;
    }
    int idx = trace[u][t1][t2];
    if (idx == 1) {
        if (u != k) e[1].push_back(s[u].pos);
        if (u != n - 1) Trace(k, u + 1, t1 - s[u].t, t2);
        return;
    }
    if (idx == 2) {
        if (u != k) e[2].push_back(s[u].pos);
        if (u != n - 1) Trace(k, u + 1, t1, t2 - s[u].t);
        return;
    }
    if (u != k) e[3].push_back(s[u].pos);
    if (u != n - 1) Trace(k, u + 1, t1, t2);
}

void solve() {
    int sum = 0;
    FORD(i, n - 1, 0) {
        sum += s[i].t;
        FOR(j, 0, sum + 1) FOR(k, 0, sum - j + 1) {
            dp[i][j].push_back(1e9);
            trace[i][j].push_back(0);
        }
    }
    sum = s[n - 1].t;
    dp[n - 1][0][0] = s[n - 1].h;
    trace[n - 1][0][0] = 3;
    dp[n - 1][s[n - 1].t][0] = 1e8;
    trace[n - 1][s[n - 1].t][0] = 1;
    dp[n - 1][0][s[n - 1].t] = 1e8;
    trace[n - 1][0][s[n - 1].t] = 2;
    FORD(i, n - 2, 1) {
        FORD(t1, sum, 0) FORD(t2, sum - t1, 0) if (dp[i + 1][t1][t2] != 1e9) {
            long long t3 = sum - t1 - t2;
            //
            //int t3 = maxt - t1 - t2;
            //
            long long tt1 = t1 + ss[i - 1];
            //
            long long tt = dp[i + 1][t1][t2];
            if (tt != 1e8) {
                long long now = 1ll * (s[0].h + s[i].h + dp[i + 1][t1][t2]) * 1ll * (max(tt1, max(t2 + s[i].t, t3)));
                if (ans > now) {
                    ans = now;
                    FOR(k, 1, 3) e[k].clear();
              //      Trace(i, i, t1, t2);
                }
            }

            //
            if (t1 + s[i].t <= maxt && dp[i][t1 + s[i].t][t2] > dp[i + 1][t1][t2]) {
                dp[i][t1 + s[i].t][t2] = dp[i + 1][t1][t2];
                trace[i][t1 + s[i].t][t2] = 1;
            }

            if (t2 + s[i].t <= maxt && dp[i][t1][t2 + s[i].t] > dp[i + 1][t1][t2]) {
                dp[i][t1][t2 + s[i].t] = dp[i + 1][t1][t2];
                trace[i][t1][t2 + s[i].t] = 2;
            }

            if (dp[i][t1][t2] > s[i].h) {
                dp[i][t1][t2] = s[i].h;
                trace[i][t1][t2] = 3;
            }
        }
        sum += s[i].t;
    }

}
int main() {
    freopen("BOOKCASE.inp","r",stdin);
    freopen("BOOKCASE.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    maxt = 0;
    REP(i, n) {cin>>s[i].h>>s[i].t; s[i].pos = i + 1; maxt += s[i].t;}
    sort(s, s + n);
    ss[0] = s[0].t;
    FOR(i, 1, n - 1) ss[i] = ss[i - 1] + s[i].t;
    //
    ans = 1e18;
    solve();
    //
    cout<<ans;
    return 0;
    FOR(i, 1, 3) {
        cout<<endl<<e[i].size();
        //sort(e[i].begin(), e[i].end())
        for(int x : e[i]) cout<<' '<<x;
    }
}

