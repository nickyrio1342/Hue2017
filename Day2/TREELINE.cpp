#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

const long long MOD = 1e9;

long long pow(int a, int k) {
    if (k == 0) return 1;
    long long t = pow(a, k / 2);
    t = t * t % MOD;
    if (k % 2) t = t * a % MOD;
    return t;
}

int cal(int x, int i) {
    int t = 0;
    while (x % i == 0) {
        t++;
        x /= i;
    }
    return t;
}
vector<bool> NT(2 * N, true);
long long catalan(int n) {
    
    long long ans = 1;
    FOR(i, 2, 2 * n) if (NT[i]) {
        int count = 0;
        for (int j = i; j<= 2 * n; j += i) {
            NT[j] = false;
            if (j >= n + 2) count += cal(j, i);
            if (j <= n) count -= cal(j, i);
        }
        ans = (ans * pow(i, count)) % MOD;
    }
    return ans;
}
int n, b, a[N];

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    scanf("%d%d", &n, &b);//cin>>n>>b;
    REP(i, n) scanf("%d", &a[i]);//cin>>a[i];
    a[n] = 1e9;
    int ans = n + 1;
    FORD(i, n - 1, 0) if (a[i] > a[i + 1]) {
        ans = n - i;break;
    }
    printf("%d\n%lld", ans, catalan(n + 1));
}
