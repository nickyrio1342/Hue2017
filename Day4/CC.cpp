#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;
unsigned long long a[N], n, k;

void solve1() {
    long long ans = 1e18;
    FOR(i, 1, n) {
        long long sum = a[n] - 2ll * a[i] + (2ll * i - n) * (a[i] - a[i - 1]);
        ans = min(ans, sum);
    }
    cout<<ans<<".00";
}

void solve2() {
    unsigned long long sumsqr = 0;
    FOR(i, 1, n) sumsqr += (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
    double ans = (sumsqr * n - (1.0 * a[n] * a[n])) / n;
    cout<<fixed<<setprecision(2)<<ans;
}

int main() {
    freopen("CC.inp","r",stdin);
    freopen("CC.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k;
    FOR(i, 1, n) cin>>a[i];
    sort(a + 1, a + n + 1);
    a[0] = 0;
    FOR(i, 1, n) a[i] += a[i - 1];
    if (k == 1) {
        solve1();
    } else solve2();
}

