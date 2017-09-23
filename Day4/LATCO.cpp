#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define bit(S, i) (S >> i) & 1

using namespace std;
string a, b;
int m, n;

void flip(string &t, int m, int pos) {
    pos = pos % n;
    if (pos < 0) pos += n;
    REP(i, m) {
        t[(pos + i) % n] = char(48 + '1' - t[(pos + i) % n]);
    }
}

int main() {
    freopen("LATCO.inp","r",stdin);
    freopen("LATCO.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    string b, a;
    cin>>n>>m>>a>>b;
    int ans = 1e9;
    REP(p, n) {
        REP(S, 1 << m) {
            string t = a.substr(p, n - p);
            t = t + a.substr(0, p);
            int cnt = __builtin_popcount(S);
            REP(i, m) if (bit(S, i)) flip(t, m, n - i);
            REP(i, n - m + 1) {
                if (t[i] != b[i]) {
                    flip(t, m, i);
                    cnt++;
                }
            }
            bool ok = true;
            FOR(i, n - m + 1, n - 1) {
                if (t[i] != b[i]) {
                    ok = false;
                    break;
                }
            }
            if (ok) ans = min(ans, cnt);
        }
    }
    if (ans == 1e9) cout<<-1;
    else cout<<ans;
}

