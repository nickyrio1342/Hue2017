#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001
#define pp pair<int, int>

using namespace std;
int m, n, a[N][N];
long long s[N][N];

long long cal(int i, int j, long long k) {
    long long x = a[i][k];
    long long sum = 0;
    if (k) {
        sum += x * k - s[i][k - 1];
    }
    sum += s[i][n - 1] - s[i][k] - (n - k - 1) * x;
    k = n - k;
    if (k) {
        sum += x * k - s[j][k - 1];
    }
    sum += s[j][n - 1] - s[j][k - 1] - (n - k) * x;
    return sum;
}

long long find(int i, int j) {
    if (a[i][0] >= a[j][n - 1]) return cal(i, j, 0);
    if (a[j][0] >= a[i][n - 1]) return cal(j, i, 0);
    int l = 1;
    int r = n - 1;
    int cur = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[i][mid] >= a[j][n - mid - 1]) {
            cur = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    if (cur != -1) {
        if (a[i][cur] <= a[j][n - cur]) return cal(i, j, cur);
    }
    l = 1;
    r = n - 1;
    cur = -1;
     while (l <= r) {
        int mid = (l + r) >> 1;
        if (a[j][mid] >= a[i][n - mid - 1]) {
            cur = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    return cal(j, i, cur);
}
int main() {
    freopen("WMT.inp","r",stdin);
    freopen("WMT.out","w",stdout);
    cin.tie(NULL);cout.tie(NULL);
    scanf("%d%d", &m, &n);
    REP(i, m) REP(j, n) scanf("%d", &a[i][j]);
    REP(i, m) sort(a[i], a[i] + n);
    REP(i, m) {
        s[i][0] = a[i][0];
        FOR(j, 1, n - 1) s[i][j] = s[i][j - 1] + a[i][j];
    }
    long long ans = 0;
    REP(i, m - 1) FOR(j, i + 1, m - 1) {
        ans += find(i, j);
    }
    printf("%lld", ans);
}


