//80%
#include <bits/stdc++.h>
#define FOR(i, a, b) for (int i = a; i<=b; i++)
#define FORD(i, a, b) for (int i = a; i>=b; i--)
#define REP(i, a) for (int i = 0; i<a; i++)
#define N 100100
#define pp pair<int, int>

using namespace std;


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
int d[N];
int dist[N], c[N], n, m;
vector<int> ee[N];
vector<pp> e[N];
void bfs(int s) {
    queue<int> q;
    FOR(i, 1, n) d[i] = -1;
    d[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : ee[u]) {
            if (d[v] == -1) {
                d[v] = d[u] + 1;
                if (d[v] != dist[s]) q.push(v);
            }
        }
    }
    FOR(i, 1, n) if (d[i] != -1 && i != s) e[s].push_back(pp(i, c[s]));
}

bool dd[N];
priority_queue<pp> h;
void dijkstra(int s, int t) {
    while (!h.empty()) h.pop();
    h.push(pp(0, s));
    FOR(i, 1, n) d[i] = 1e18;
    d[s] = 0;
    memset(dd, true, sizeof dd);
    while (!h.empty()) {
        int u = h.top().second;
        h.pop();
        if (u == t) break;;
        if (!dd[u]) continue;
        dd[u] = false;
        for (pp t : e[u]) {
            int v = t.first;
            int w = t.second;
            if (d[v] > d[u] + w) {
                d[v] = d[u] + w;
                h.push(pp(-d[v], v));
            }
        }
    }
    write(d[t]);
}
int u, v;
int main() {
    read(n); read(m);
    FOR(i, 1, n) {read(c[i]); read(dist[i]);}
    REP(i, m) {
        read(u); read(v);//cin>>u>>v;
        ee[u].push_back(v);
        ee[v].push_back(u);
    }
    FOR(i, 1, n) bfs(i);
    dijkstra(1, n);
}

