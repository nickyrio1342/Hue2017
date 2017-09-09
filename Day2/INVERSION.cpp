#include <bits/stdc++.h>

using namespace std;

#define N 1000010

long long f[N];

void init() {
    f[0] = 0;
    for (int i = 1; i<N; i++) f[i] = f[i - 1] + i;
}

long long n;
const long long MOD = 1e9 + 7;

vector<long long> r[N];


long long k, res[N];

void cal(long long m , long long k) {
    for (; m>0; m--) {
        if (k >= f[m - 2]) {
            long long first = k - f[m - 2] + 1;
            r[first].push_back(n - m + 1);
            long long t = n - m + 1;
            for (int i = m; i>0; i--) {
                if (i == first) continue;
                r[i].push_back(++t);
            }
            return;
        }
        else r[1].push_back(n - m + 1);
    }
}
void solve() {
    //cin>>n>>k;
    scanf("%lld%lld", &n, &k);
    for (int i = 0; i<=n; i++) r[i].clear();
    if (n == 1) {
        if (k == 0) {
            printf("1\n");//cout<<"1\n";
            return;
        }
        printf("-1\n");//cout<<"-1\n";
        return;
    }
    if (k >= f[n - 2]) {
        long long first = k - f[n - 2] + 1;
        if (first > n) {
            printf("-1\n");//cout<<"-1\n";
            return;
        }
        long long POW = 1;
        long long ans = first;
        for (long long i = n ; i> 0; i--) {
            if (i == first) continue;
            POW = (POW * 2ll) % MOD;
            ans = (ans + (i * POW) % MOD) % MOD;
        }
        printf("%lld\n", ans);//cout<<ans<<endl;
        return;
    }
    r[1].push_back(1);
    cal(n - 1, k);
    //sort(p + 1, p + n + 1, cmp);
    int cnt = 1;
    for (int i = 1; i<=n; i++)
        for (int j = 0; j<(int) r[i].size(); j++) res[r[i][j]] = cnt++;
    unsigned long long ans = 0;
    unsigned long long POW = 1;
    for (int i = 1; i<=n; i++) {
        ans = (ans + (res[i] * POW) % MOD) % MOD;
        POW = (POW * 2ll) % MOD;
    }
    printf("%lld\n", ans);//    cout<<ans<<endl;
}
int main() {
    freopen("inversion.inp","r",stdin);
    freopen("inversion.out","w",stdout);
    //ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int test;
    //cin>>test;
    scanf("%d", &test);
    init();
    while (test--) {
        solve();

    }
}
