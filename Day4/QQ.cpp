#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

vector<long long> a, b;
int n;

int main() {
    freopen("QQ.inp","r",stdin);
    freopen("QQ.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin>>n;
    long long x, y;
    REP(i, n) {
        cin>>x>>y;
        a.push_back(x);
        b.push_back(y);
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    long long mx = a[n / 2];
    long long my = b[n / 2];
    //Row line
    long long ans = 0;
    for(long long x : a) {
        ans += abs(x - mx);
    }
    int mid = n / 2;
    REP(i, mid) {
        ans += abs(b[mid] - b[i] + i - mid);
        ans += abs(b[i + mid + 1] - (b[mid] + i));
    }
    long long res = ans;
    //Column line
    ans = 0;
    for(long long y : b) {
        ans += abs(y - my);
    }
    mid = n / 2;
    REP(i, n - mid) {
        ans += abs(a[mid] - a[i] + i - mid);
        ans += abs(a[i + mid] - (a[mid] + i));
    }
    res = min(res, ans);
    cout<<res;
}

