//Tương tự (có thể nói là giống hệt) VOITSORT(2015)
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b ; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define IO cin.tie(NULL);cout.tie(NULL);

using namespace std;
vector<int> p;
int n, k, appear[N], cnt, xx;
bool OK[N];

int permute() {
    FORD(l, n - 2, 0) if (p[l] < p[l + 1]) {
        FORD(r, n - 1, l + 1) if (p[l] < p[r]) {
            swap(p[l], p[r]);
            for (int i = l + 1, j = n - 1; i < j; ++i, --j) swap(p[i], p[j]);
            return l;
        }
    }
    return -1;
}

bool check(int u, int cnt) {
    int l = -1, r = n + 1;
    FORD(i, n - 1, u + 1) {
        appear[p[i]] = cnt;
        r = min(r, p[i]);
    }
    FORD(i, p[u] - 1, 1) if (appear[i] != cnt) {
        l = i;
        break;
    }
    return l < r;
}

bool SSort() {
    FOR(i, xx, n - 1) {
        OK[i] = check(i, ++cnt);
        if (i) OK[i] &= OK[i - 1];
    }
    return OK[n - 1];
}
int main() {
    IO;
    scanf("%d %d", &n, &k);
    p.resize(n);
    REP(i, n) scanf("%d", &p[i]);
    int ans = 0;
    xx = 0;
    cnt = 0;
    while (k--) {
        if (SSort()) ans++;
        xx = permute();
        if (xx == -1) break;
    }
    cout<<ans;
}
