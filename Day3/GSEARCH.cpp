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

bool dd[N];
int d[N], n, m, u, v;
vector<int> res, e[N], ee[N];

void dfs(int u) {
    dd[u] = false;
    for (int v : ee[u]) {
        if (dd[v]) {
            dfs(v);
        }
    }
}

void bfs(int s) {
    FOR(i, 1, n) d[i] = 1e9;
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : e[u]) {
            if (d[v] == 1e9) {
                d[v] = d[u] + 1;
                q.push(v);
            }
        }
    }
}

void dfs2(int u, int f) {
    dd[u] = false;
    if (u == f) {
        writeln((int)res.size());
        for (int x : res) {
                write(x);putchar(' ');
        }
        exit(0);
    }
    for (int v: e[u]) {
        if (dd[v]) {
            res.push_back(v);
            dfs2(v, f);
            res.pop_back();
        }

    }
}

int main() {
    read(n);read(m);
    REP(i, m) {
        read(u); read(v);
        e[u].push_back(v);
        ee[u].push_back(v);
        ee[v].push_back(u);
    }
    //1
    int comp = 0;
    memset(dd, true, sizeof dd);
    FOR(i, 1, n) if (dd[i]) {
        comp++;
        dfs(i);
    }
    writeln(comp);
    //2
    read(u);read(v);
    bfs(u);
    if (d[v] == 1e9) {
        writeln(0);writeln(0);
        return 0;
    }
    writeln(d[v]);
    //3
    memset(dd, true, sizeof dd);
    FOR(i, 1, n) sort(e[i].begin(), e[i].end());
    res.push_back(u);
    dfs2(u, v);
}

