#include <bits/stdc++.h>

using namespace std;
#define N 10010

int n, k;
int POW[N], res[N];
vector<int> s;
#define pp pair<int, int>

pp a[N];

bool cmp(const pp &a, const pp &b) {
    return (a.first < b.first) ||((a.first == b.first && a.second < b.second));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    for (int i = 0; i<n; i++) s.push_back(i + 1);
    POW[1] = 1;
    for (int i = 2; i<=n; i++) {
        POW[i] = (POW[i - 1] * i);
        if (POW[i] > k) {
            POW[i] = k + 10;
        }
    }
    if (k > POW[n]) {
        cout<<-1;
        return 0;
    }
    for (int i = n - 1; i>0; i--) {
        a[i].first = (k - 1) / POW[i];
        a[i].second = n - i;
        //cout<<t<<' ';
      //  s.erase(s.begin() + t);
        k = k - a[i].first * POW[i];
    }
    a[0].first = 0;
    a[0].second = n;
    sort(a, a + n, cmp);
    for (int i = 0; i<n; i++) {
        res[a[i].second] = i + 1;
    }
    for (int i = 1; i<=n; i++) cout<<res[i]<<' ';
}
