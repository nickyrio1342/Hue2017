
#include <bits/stdc++.h>

using namespace std;
#define N 1000001
int n;
long long ii,MOD;
long long  aa[N],fr[N];
typedef long long ll;
#define matrix  vector<vector<ll> >

matrix a;// = { {0,1},{1,1} };
matrix r;// = { {0,0};{0,0} };
matrix rr;// = { {0,0};{0,0} };

matrix operator* (const matrix &aa, const matrix &bb ) {
    matrix c = rr;
    for (int i = 0; i<2; i++) {
        for (int j = 0; j<2; j++) {
            for (int k = 0; k<2; k++) {
                c[i][j] = (c[i][j] + (aa[i][k] * bb[k][j]) % MOD) %MOD;
            }
        }
    }
    return c;
}
matrix power(long long n) {
    if (n == 1) return a;
    matrix tmp = power(n / 2);
    tmp = tmp * tmp;
    if (n % 2 == 1) tmp = tmp * a;
    return tmp;
}
vector<ll> cc;
void solve() {

    for (int i = 0; i<2; i++) {
        a.push_back(cc);
        r.push_back(cc);
        rr.push_back(cc);
        for(int j = 0; j<2; j++) {
            a[i].push_back(1);
            r[i].push_back(0);
            rr[i].push_back(0);
        }
    }
    a[0][0] = 0;
    cin>>n>>ii>>MOD;
    r = power(ii);
    aa[0] = r[1][0];
    aa[1] = r[1][1];
    for (int i = 2; i<n; i++) aa[i] = (aa[i-2] + aa[i-1]) % MOD;
    memset(fr, -1, sizeof fr);
    long long sum = 0;
    fr[0] = 0;
    for (int i = 0; i<n; i++) {
        sum = (sum + aa[i])%MOD;
        if (fr[sum] > -1) {
            cout<<i - fr[sum] + 1<<' ';
            for(int j = fr[sum]; j<=i; j++) cout<<j + ii<<' ';
            cout<<endl;
            return;
        }
        fr[sum] = i + 1;
    }

}
int main() {
    //freopen("FIBSEQ.inp","r",stdin);
    //freopen("FIBSEQ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int test;
    cin>>test;
    while (test--) {
        solve();
    }
}
