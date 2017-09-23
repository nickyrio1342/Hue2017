#include <bits/stdc++.h>

#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 200100
#define pp pair<int, int>
#define bit(S, i) (S >> i) & 1

using namespace std;
int m, n, k, c, g;
vector<long long> e[21];
long long cal[21][N], f[1 << 20], h[21];
priority_queue<int, vector<int>, greater<int> > heap;

void create(int k) {
    while (!heap.empty()) heap.pop();
    memset(cal[k], 0, sizeof cal[k]);
    long long cnt = e[k].size();
    long long now = 0;
    for (long long i = 0; i < cnt; i++) {
        cal[k][1] += abs(e[k][i] - i - 1) * h[k];
        if (e[k][i] > i + 1) heap.push(e[k][i] - i);
        else now++;
    }
    for (int S = 2; S<= n; S++) {
        cal[k][S] = cal[k][S - 1] + (now * 2 - cnt) * h[k];
        while (!heap.empty() && heap.top() == S) {
            heap.pop();
            now++;
        }
    }
    //cout<<1;
}

vector<int> now;
int main() {
    freopen("COW.inp","r",stdin);
    freopen("COW.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n>>k;
    FOR(i, 1, k) cin>>h[i];
    REP(i, n) {
        cin>>c>>g;
        e[g].push_back(c);
    }
    FOR(i, 1, k) {
        sort(e[i].begin(), e[i].end());
        create(i);
    }
    REP(S, 1 << k) f[S] = 1e18;
    f[0] = 0;
    REP(S, 1 << k) {
        if (!S) continue;
        now.clear();
        int sum = 0;
        FOR(i, 1, k) if (bit(S, i - 1)) {
            now.push_back(i); sum += e[i].size();
        }
        REP(i, now.size()) {
            int u = now[i];
            int tmp = e[u].size();
            long long t2 = cal[u][sum - tmp + 1];
            f[S] = min(f[S], f[S ^ (1 << (u - 1))] + cal[u][sum - e[u].size() + 1]);
        }
    }
    cout<<f[(1 << k) - 1];
}

