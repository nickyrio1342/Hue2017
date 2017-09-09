#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 1001000
#define pp pair<int, int>

using namespace std;
const long long MOD = 1e9;
long long f[N];
int n, b, a[N];
long long fib(int n) {
    f[1] = 1;
    f[2] = 1;
    FOR(i, 3, n) f[i] = (f[i - 1] + f[i - 2]) % MOD;
    return f[n];
}
int main() {
    //ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    scanf("%d%d", &n, &b);//cin>>n>>b;
    REP(i, n) scanf("%d", &a[i]);//cin>>a[i];
    int maxx = *max_element(a, a + n);
    if (b <= maxx) {
        printf("0\n0");return 0;
    }
    else {
        if (n == 0) {
            printf("1\n1");return 0;
        }
        if (n == 1) {
            printf("2\n2");return 0;
        }
        if (a[0] < a[1]) printf("1\n%lld", fib(n + 2));
        else printf("2\n%lld", fib(n + 2));
    }
}

