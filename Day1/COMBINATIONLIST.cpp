#include <bits/stdc++.h>

using namespace std;

#define N 10010

int n, m;
long long need;
long long f[N][N];

long long Cal(int n, int k) {
    if (n < k) return 0;
    if (f[n][k] != 0) return f[n][k];
    if (k == 0) {
        f[n][k] = 1;
        return f[n][k];
    }
    f[n][k] = Cal(n - 1, k - 1) + Cal(n - 1, k);
    if (f[n][k] > 2e9) f[n][k] = 2e9 + 5;
    return f[n][k];
}

void Find(int n, int k, int num) {
    if (k == 0) return;
    if (need <= f[n - 1][k - 1]) {
        printf("%d ", num);
        Find(n - 1, k - 1, num + 1);
    }
    else {
        need = need - f[n - 1][k - 1];
        Find(n - 1, k, num + 1);
    }
}

int main() {
    scanf("%d%d%lld",&n, &m, &need);
    long long maxx = Cal(n, m);
    if (maxx < need) {
        printf("-1\n");
        return 0;
    }
    Find(n, m, 1);
}
