#include <bits/stdc++.h>

using namespace std;
#define N 2000005
long long MOD;
long long n, k;


long long POW(int x, int k) {
    if (k == 0) return 1;
    long long tmp = POW(x, k / 2);
    tmp = (tmp * tmp) % MOD;
    if (k % 2 == 1) tmp =(tmp * x) % MOD;
    return tmp;
}

int cal(int x, int i) {
    int t = 0;
    while (x % i == 0) {
        t++;
        x /= i;
    }
    return t;
}

long long catalan(int n) {
    vector<bool> NT(2 * n + 1, true);

    long long ans = 1;
    for (int i = 2; i<=2 * n; i++) if (NT[i]){
        int count = 0;
        for (int j = i; j<=2 * n; j += i) {
            NT[j] = false;
            if (j >= n + 2) count += cal(j, i);
            if (j <=n) count -= cal(j, i);
        }
        ans = (ans * POW(i, count)) % MOD;
    }
    return ans;
}

int main() {
    //freopen("CCATALAN.inp","r",stdin);
    //freopen("CCATALAN.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>MOD;
    cout<<catalan(n);
}
