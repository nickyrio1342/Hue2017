#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

int n;
long long a[N];
int main() {
    freopen("HP.inp","r",stdin);
    freopen("HP.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    FOR(i, 1, n) {
        cin>>a[i];
        a[i] += a[i - 1];
    }
    long long ans = 0;
    FOR(i, 2, n) ans += (a[i] - a[i - 1]) * a[i - 1];
    cout<<ans;
}

