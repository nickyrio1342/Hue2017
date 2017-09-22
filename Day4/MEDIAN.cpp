#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1011
#define pp pair<int, int>

using namespace std;

int n, m, r, c, a[N][N], b[N][N];

bool check(int mid) {
    FOR(i, 1, m) FOR(j, 1, n)
        if (a[i][j] <= mid) b[i][j] = 1;
        else b[i][j] = 0;
    FOR(i, 1, m) FOR(j, 1, n) {
        b[i][j] += b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1];
    }
    //
    FOR(i, 1, m - r + 1) FOR(j, 1, n - c + 1) {
        int sum = b[i + r - 1][j + c - 1] - b[i + r - 1][j - 1] - b[i - 1][j + c - 1] + b[i - 1][j - 1];
        if (sum * 2 >= r * c) return true;
    }
    return false;
}

int main() {
    freopen("MEDIAN.inp","r",stdin);
    freopen("MEDIAN.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>m>>n>>r>>c;
    FOR(i, 1, m) FOR(j, 1, n) cin>>a[i][j];
    int l = 0;
    int r = 1e9;
    int cur = -1;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (check(mid)) {
            cur = mid;
            r = mid - 1;
        } else l = mid + 1;
    }
    cout<<cur;
}

