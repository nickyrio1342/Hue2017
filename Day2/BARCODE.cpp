#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;
int a[N], b[N], c[N];
long long POW[N];
int n, m;
const long long MOD = 1e9 + 7;

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    REP(i, n) scanf("%d", &a[i]);//cin>>a[i];
    REP(i, n) b[i] = a[i];
    sort(b, b + n);
    REP(i, n) {
        a[i] = lower_bound(b, b + n, a[i]) - b + 1;
    }
    POW[0] = 1;
    FOR(i, 1, n) POW[i] = (POW[i - 1] * 2) % MOD;
    scanf("%d", &m);//cin>>m;
    while (m--) {
        REP(i, n) {
            scanf("%d", &c[i]);//cin>>c[i];
            c[i] = lower_bound(b, b + n, c[i]) - b + 1;
        }
        long long ans = 0;
        REP(i, n - 3) {
            int tmp = 0;
            REP(j, i + 1) if (c[j] <= c[i]) tmp++;
            if (tmp == c[i]) {
                continue;
            }
            else {
                ans = (ans + POW[n - i - 2]) % MOD;
            }
        }
        if (n == 1) {printf("1\n"); continue;}
        if (n == 2) {
            if (c[0] > c[1]) ans = 2;
            else ans = 1;
            printf("%lld\n", ans);continue;
        }
        else {
            if (c[n - 3] < c[n - 2] && c[n - 2] < c[n - 1]) ans = (ans + 1) % MOD;
            else {
                if (c[n - 3] < c[n - 1] && c[n - 1] < c[n - 2]) ans = (ans + 2) % MOD;
                else {
                    if (c[n - 2] < c[n - 3] && c[n - 3] < c[n - 1]) ans = (ans + 3) % MOD;
                    else {
                        ans = (ans + 4) % MOD;
                    }
                }
            }
        }
        printf("%lld\n", ans);//cout<<ans<<endl;
    }
}
