#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

int n, w;

struct data {
    long long a, b, pos;

    operator < (const data &x) {
        return a * x.b < b * x.a;
    }
}t[N], s[2 * N];
int BIT[2 * N];

void update(int u, int val) {
    for(; u <= 2 * n; u += u&-u) BIT[u] = max(BIT[u], val);
}

int get(int u) {
    int ans = 0;
    for (; u > 0; u -= u&-u) ans = max(ans, BIT[u]);
    return ans;
}

int main() {
    freopen("FRACTION.inp","r",stdin);
    freopen("FRACTION.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>w;
    REP(i, n) {
        cin>>s[i].a>>s[i].b;
        s[i + n].a = s[i].b;
        s[i + n].b = s[i].a;
        s[i].pos = i;
        s[i + n].pos = i + n;
    }
    sort(s, s + 2 * n);
    int k = 1;
    REP(i, 2 * n) {
        if (i && s[i].a * s[i - 1].b != s[i].b * s[i - 1].a) k++;
        if (s[i].pos < n) t[s[i].pos].a = k;
        else t[s[i].pos - n].b = k;
    }
    if (w == 0) {
        int ans = 0;
        REP(i, n) {
            int tt = get(t[i].a - 1) + 1;
            ans = max(ans, tt);
            update(t[i].a, tt);
        }
        cout<<ans;
    }
    else {
        int ans = 0;
        REP(i, n) {
            int t1 = get(t[i].a - 1) + 1;
            int t2 = get(t[i].b - 1) + 1;
            ans = max(ans, max(t1, t2));
            update(t[i].a, t1);
            update(t[i].b, t2);
        }
        cout<<ans;
    }
}
