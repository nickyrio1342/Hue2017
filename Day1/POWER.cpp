#include <bits/stdc++.h>

using namespace std;

int main() {
    int a, b, k;
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>a>>k>>b;
    if (a < 2) {
        if (k == 1) cout<<0;
        else cout<<-1;
        return 0;
    }
    double ans = (k - 1) * (log(b) / log(a));
    cout<<ceil(ans);
}
