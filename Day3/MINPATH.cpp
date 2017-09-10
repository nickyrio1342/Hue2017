//Full
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;

typedef long long ll;
typedef long double ld;

template <typename T> inline void read(T &x){
    /*bool minus = false;
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
		x = result; */
	x = 0;
	char c;
	while (!isdigit(c = getchar()));
	do {
	    x = x * 10 + c - '0';
	} while (isdigit(c = getchar()));
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}


int n, m, u, v, w, s, t;
vector<pp> e[N], ee[N];
long long ds[N], dt[N];
bool dd[N];
priority_queue<pp> h;

void dijkstra2(int s, int t) {
    while (!h.empty()) h.pop();
    h.push(pp(0, s));
    FOR(i, 1, n) dt[i] = 1e18;
    dt[s] = 0;
    memset(dd, true, sizeof dd);
    while (!h.empty()) {
        int u = h.top().second;
        h.pop();
        if (u == t) return;
        if (!dd[u]) continue;
        dd[u] = false;
        for (pp t : ee[u]) {
            int v = t.first;
            int w = t.second;
            if (dt[v] > dt[u] + w) {
                dt[v] = dt[u] + w;
                h.push(pp(-dt[v], v));
            }
        }
    }
}

void trace(int s, int t) {
    int ver = -1;
    write(s);putchar(' ');
    if (s == t) return;
    for (pp tt : e[s]) {
        int v = tt.first;
        int w = tt.second;
        if (dt[s] == dt[v] + w && (ver == -1 || ver > v)) ver = v;
    }
    trace(ver, t);
}

int main() {
    read(n);read(m);
    REP(i, m) {
        read(u);read(v);read(w);
        e[u].push_back(pp(v, w));
        ee[v].push_back(pp(u, w));
    }
    read(s); read(t);
    dijkstra2(t, s);
    if (ds[t] == 1e18) {
        writeln(-1);
        return 0;
    }
    writeln(dt[s]);
    trace(s, t);
}

