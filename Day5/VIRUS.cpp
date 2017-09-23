#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 10010
#define pp pair<int, int>

using namespace std;
int n;
int nxt[26][N], f[510][510];
string s, st;
int cal() {
    int ans = 0;
    int m = st.size();
    REP(i, m + 1) REP(k, m + 1) f[i][k] = s.size();
    REP(i, m) f[i][0] = -1;
    REP(i, m) FORD(k, i + 1, 1) {
        if (i) {
            f[i][k] = f[i - 1][k];
            if (f[i - 1][k - 1] == s.size()) continue;
            if (nxt[st[i] - 'A'][f[i - 1][k - 1] + 1] != s.size())
                f[i][k] = min(f[i][k], nxt[st[i] - 'A'][f[i - 1][k - 1] + 1]);
        }
        else {
            if (nxt[st[i] - 'A'][0] != s.size())
                f[i][k] = min(f[i][k], nxt[st[i] - 'A'][0]);
        }
        if (f[i][k] != s.size()) ans = max(ans, k);
    }
    return ans;
}

void prepare() {
    REP(i, s.size() + 1) REP(idx, 26) nxt[idx][i] = s.size();
    FORD(i, s.size() - 1, 0) REP(idx, 26) {
        if (idx != s[i] - 'A') nxt[idx][i] = nxt[idx][i + 1];
        else nxt[idx][i] = i;
    }
}

void solve() {
    cin>>n;
    cin>>s;
    int ans = 0;
    prepare();
    REP(i, n) {
        cin>>st;
        ans = max(ans, cal());
    }
    cout<<ans<<endl;
}
int test;
int main() {
    freopen("VIRUS.inp","r",stdin);
    freopen("VIRUS.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>test;
    while (test--) solve();
}

