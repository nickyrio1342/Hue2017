#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T> void read(T &x){
    bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		x = -result;
	else
		x = result;
}
template <typename T> void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> void writeln(T x){
    write(x);
    putchar('\n');
}


struct data {
    int u, v, c;
};

bool cmp (const data &a, const data &b) {
    return (a.c < b.c) || (a.c == b.c && a.u < b.u) || (a.c == b.c && a.u == b.u && a.v < b.v);
}
int n, m;
vector<data> e;
int f[N];
int u, v, c;

void Union(int a, int b) {
    int t = f[a] + f[b];
    if (f[a] <= f[b]) {
        f[a] = t;
        f[b] = a;
        return;
    }
    f[a] = b;
    f[b] = t;
}

int root(int u) {
    if (f[u] < 0) return u;
    f[u] = root(f[u]);
    return f[u];
}
vector<pp> res;
int main() {
    //ios::sync_with_stdio(false);
    //cin.tie(NULL);cout.tie(NULL);
    read(n);read(m);//cin>>n>>m;
    REP(i, m) {
        read(u), read(v), read(c);//cin>>u>>v>>c;
        if (u > v) swap(u, v);
        e.push_back(data({u, v, c}));
    }
    long long ans = 0;
    sort(e.begin(), e.end(), cmp);
    memset(f, -1, sizeof f);
    for (data t: e) {
        int a = root(t.u);
        int b = root(t.v);
        if (a != b) {
            res.push_back(pp(t.u, t.v));
            ans += t.c;
            Union(a, b);
        }
    }
    sort(res.begin(), res.end());
    writeln(ans);
    for (pp x : res) {
        write(x.first); putchar(' ');write(x.second);putchar(' ');
    }
}

