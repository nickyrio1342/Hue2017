#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 105
#define pp pair<int, int>

using namespace std;

int k, n, m;
string s[N];

struct data {
    int u, v, k, dir;
};
const int d[4] = {0, 1, 0, -1};
const int c[4] = {1, 0, -1, 0};
bool fr[4][N][N];
bool inside(int u, int v) {
    return u >= 0 && u <= m + 1 && v >= 0 && v <= n + 1;
}
long long bfs(int uu, int vv) {
    deque<data> q;
    memset(fr, true, sizeof fr);
    REP(i, 4) fr[i][uu][vv] = false;
    REP(i, 4) {
        data t;
        t.u = uu + d[i];
        t.v = vv + c[i];
        if (s[t.u][t.v] == s[uu][vv] || s[t.u][t.v] == '.') {
            fr[i][t.u][t.v] = false;
            t.k = 1;
            t.dir = i;
            q.push_back(t);
        }
    }
    while (!q.empty()) {
        data u = q.front();
        q.pop_front();
        fr[u.dir][u.u][u.v] = false;
        if (s[u.u][u.v] != '.') continue;
        REP(i, 4) {
            data v;
            v.u = u.u + d[i];
            v.v = u.v + c[i];
            v.dir = i;
            if (!inside(v.u, v.v) || !fr[i][v.u][v.v]) continue;
            if (s[v.u][v.v] != s[uu][vv] && s[v.u][v.v] != '.') continue;
            if (i != u.dir) v.k = u.k + 1;
            else v.k = u.k;
            if (v.k > k) continue;
            if (i != u.dir) {
                q.push_back(v);
            } else q.push_front(v);
        }
    }
    long long cnt = -1;
    FOR(i, 1, m) FOR(j, 1, n) REP(k, 4){
        if (!fr[k][i][j] && s[i][j] == s[uu][vv]) {cnt++;break;}
    }
    return cnt;
}

int main() {
    freopen("PIKACHU.inp","r",stdin);
    freopen("PIKACHU.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n>>k;
    long long cnt = 0;
    FOR(i, 0, n + 1) s[0].push_back('.');
    s[m + 1] = s[0];
    FOR(i, 1, m) {
        cin>>s[i];
        s[i] = '.' + s[i];
        //cout<<s[i]<<endl;
        while (s[i].size() > n + 1) s[i].pop_back();
        //cout<<s[i]<<endl;
        s[i] = s[i] + '.';
    }
    FOR(i, 1, m) FOR(j, 1, n) if (s[i][j] != '.'){
       cnt += bfs(i, j);
    }
    cout<<cnt / 2;
}

