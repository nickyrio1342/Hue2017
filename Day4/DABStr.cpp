#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>
#define bit(S, i) (S >> i) & 1
using namespace std;

int n;
string s[20];
int cnt[10];
long long su[10], f[1 << 20];

int main() {
    freopen("DABStr.inp","r",stdin);
    freopen("DABStr.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin>>n;
    string t;
    REP(i, n)
        cin>>s[i];
    int sum = s[0].size();

    REP(S, 1 << n) {
        f[S] = 0;
        int num = 0;
        REP(k, sum) {
            REP(i, 10) { cnt[i] = 0; su[i] = 0; }
            REP(i, n) if (bit(S, i)) cnt[s[i][k] - '0']++;
            su[0] = 0;
            FOR(i, 1, 9) {
                su[i] = cnt[i] * i + su[i - 1];
                cnt[i] += cnt[i - 1];
            }
            if (cnt[0] * 2 >= cnt[9]) {
                f[S] += su[9];
                continue;
            }
            FOR(i, 1, 9) {
                if (cnt[i] * 2 >= cnt[9]) {
                    f[S] += cnt[i] * i - su[i];
                    f[S] += (su[9] - su[i]) - (cnt[9] - cnt[i]) * i;
                    break;
                }
            }
        }

    }
    int maxx = (1 << n) - 1;
    long long ans = f[0] + f[(1 << n) - 1];
    REP(i, 1 << n) {
        ans = min(ans, f[i] + f[maxx ^ i]);
    }
    cout<<ans;
}

