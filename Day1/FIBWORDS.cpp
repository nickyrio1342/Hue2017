#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 700100
#define pp pair<long long, long long>

using namespace std;
const long long MOD = 1e9 + 7;
const long long base1 = 3;
const long long base2 = 101;

int n;
string st;
string f[60];
long long hash1[60][N], hash2[60][N], POW1[N], POW2[N];
unsigned long long g[10001];
void prepareHash(int u, string s) {
    hash1[u][0] = hash2[u][0] = 0;
    FOR(i, 1, s.size()) {
        hash1[u][i] = (hash1[u][i - 1] * base1 + s[i - 1] - '0') % MOD;
        //hash2[u][i] = (hash2[u][i - 1] * base2 + s[i - 1] - '0') % MOD;
    }
}

long long  prepare(string s) {
    long long hash1 = 0, hash2 = 0;
    FOR(i, 1, s.size()) {
        hash1 = (hash1 * base1 + s[i - 1] - '0') % MOD;
        //hash2 = (hash2 * base2 + s[i - 1] - '0') % MOD;
    }
    return hash1;//pp(hash1, hash2);
}


long long getHash(int u, int i, int j) {
    return (hash1[u][j] - hash1[u][i - 1] * POW1[j - i + 1] + MOD * MOD) % MOD;//              (hash2[u][j] - hash2[u][i - 1] * POW2[j - i + 1] + MOD * MOD) % MOD);
}

void init() {
    f[0] = '0';
    f[1] = '1';

    FOR(i, 2, 27) f[i] = f[i - 1] + f[i - 2];
    FOR(i, 0, 25) prepareHash(i, f[i] + f[i + 1]);
    FOR(i, 0, 25) prepareHash(i + 28, f[i + 1] + f[i]);
    POW1[0] = POW2[0] = 1;
    FOR(i, 1, N - 1) {
        POW1[i] = (POW1[i - 1] * base1) % MOD;
        //POW2[i] = (POW2[i - 1] * base2) % MOD;
    }
}

unsigned long long cal(int n, string st) {
    int now = 0;
    while (f[now].size() < st.size()) now++;
    if (now > n) {
        return 0;
    }
    long need = prepare(st);

    int cnt1 = 0, cnt2 = 0;
    //
    string z = f[now];
    int sz = st.size();
    int fsz = f[now].size();
    FOR(i, 1, sz - 1) {
        if (getHash(now + 29, f[now + 1].size() - sz + i + 1, f[now + 1].size() + i) == need) cnt1++;
        if (getHash(now, fsz - sz + i + 1, fsz + i) == need) cnt2++;
    }
    //
    //1011010110110101101011011010110110101101011011010110101
    g[now] = 0;
    FOR(i, 1, fsz - sz + 1) {
        if (getHash(now, i, sz + i - 1) == need) g[now]++;
    }
    g[now + 1] = 0;
    FOR(i, 1, f[now + 1].size() - sz + 1) {
        if (getHash(now + 1, i, sz + i - 1) == need) g[now + 1]++;
    }
    FOR(i, now + 2, n) {
        g[i] = g[i - 1] + g[i - 2];
        if ((i - now) % 2) g[i] += cnt2;
        else g[i] += cnt1;
    }
    return g[n];
}
int main() {
    //freopen("FIBWORDS.inp","r",stdin);
    //freopen("FIBWORDS.out","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    init();
    int test = 0;
    while (cin>>n) {
        test++;
        cin>>st;
        cout<<"Case "<<test<<": "<<cal(n, st)<<endl;
    }

}

