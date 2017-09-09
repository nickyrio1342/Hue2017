#include <bits/stdc++.h>

using namespace std;
#define N 1000005
long long MOD;
int n, k;

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

void sangnt(int n, int k) {
    vector<bool> NT(n + 1, true);

    long long ans = 1;
    for (int i = 2; i<=n; i++) if (NT[i]){
        int count = 0;
        for (int j = i; j<=n; j += i) {
            NT[j] = false;
            count += cal(j, i);
            if (j <= k) count -= cal(j, i);
            if (j <= n - k) count -= cal(j, i);
        }
        ans = (ans * POW(i, count)) % MOD;
    }
    cout<<ans;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n>>k>>MOD;
    sangnt(n, k);
}
