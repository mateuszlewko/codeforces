#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef JUST_CPP11
template<typename... Args>
void read(Args&... args)
{
    ((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
    ((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
	cout << "\n";
}
#endif

template<typename T, typename U>
pair<T, U>& operator+=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first += rhs.first;
	lhs.second += rhs.second;
	return lhs;
}

template<typename T, typename U>
pair<T, U>& operator-=(pair<T, U> &lhs, const pair<T, U> &rhs){
	lhs.first -= rhs.first;
	lhs.second -= rhs.second;
	return lhs;
}

template <class T> ostream &operator<<(ostream &os, const vector<T> &container) {
	for (auto &u : container) os << u << " ";
	return os;
}

template <class T, class U> ostream &operator<<(ostream &os, const pair<T, U> &p) {
	os << p.first << " " << p.second;
	return os;
}

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
// #include <ext/pb_ds/detail/standard_policies.hpp>

using namespace __gnu_pbds; 
using namespace std; 

template<typename T>
using pb_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#if DEBUG
#define error(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string>) {}
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << endl;
	err(++it, args...);
}
#else
#define error(...) do {} while (0)
#endif

template<typename T, typename U>
pair<T, U> operator-(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first - r.first, l.second - r.second};
}
template<typename T, typename U>
pair<T, U> operator+(const pair<T, U> &l, const pair<T, U> &r) {
	return {l.first + r.first, l.second + r.second};
}

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion


namespace dinic {
    // the maximum number of vertices
    const int N = 520;

    // adjacency matrix (fill this up)
    // If you fill adj[][] yourself, make sure to include both u->v and v->u.
    int cap[N][N], deg[N], adj[N][N];

    // BFS stuff
    int q[N], pre[N];

    int dinic(int n, int s, int t)
    {
        int flow = 0;

        while (true)
        {
            // find an augmenting path
            memset(pre, -1, sizeof(pre));
            int qf = 0, qb = 0;
            pre[q[qb++] = s] = -2;
            while (qb > qf && pre[t] == -1)
                for (int u = q[qf++], i = 0, v; i < deg[u]; i++)
                    if (pre[v = adj[u][i]] == -1 && cap[u][v])
                        pre[q[qb++] = v] = u;

            // see if we're done
            if (pre[t] == -1) break;

            // try finding more paths
            for (int z = 0; z < n; z++)
                if (cap[z][t] && pre[z] != -1)
                {
                    int bot = cap[z][t];
                    for (int v = z, u = pre[v]; u >= 0; v = u, u = pre[v])
                        bot = min(bot, cap[u][v]);
                    if (!bot)
                        continue;

                    cap[z][t] -= bot;
                    cap[t][z] += bot;
                    for (int v = z, u = pre[v]; u >= 0; v = u, u = pre[v])
                    {
                        cap[u][v] -= bot;
                        cap[v][u] += bot;
                    }
                    flow += bot;
                }
        }

        return flow;
    }

    //----------------- EXAMPLE USAGE -----------------
    void initAdj(int n)
    {
        for (int u = 0; u < n; u++)
            for (int v = 0; v < n; v++)
                if (cap[u][v] || cap[v][u])
                    adj[u][deg[u]++] = v;
    }
}

ld get_dist(pii x, pii y) {
	ll fst = x.first - y.first;
	ll snd = x.second - y.second;

	return sqrt(ld(fst * fst + snd * snd));
}

vector<pair<pii, int>> ps;
vector<int> S, T;
int n;
	int s, t, q;
int source;
int sink;

bool check(ld x) {
	memset(dinic::deg, 0, sizeof(dinic::deg));
    memset(dinic::adj, 0, sizeof(dinic::adj)); 
    memset(dinic::cap, 0, sizeof(dinic::cap)); 

	for(auto i : S) dinic::cap[source][i] = 1;
	for(auto i : T) dinic::cap[i][sink] = 1;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			auto u = ps[i];
			auto v = ps[j];

			ld d = get_dist(u.first, v.first);
			if (d > x) continue;

			if (u.second < v.second) {
				dinic::cap[j][i] = 1;
				// cout << j << " -> " << i << endl;
			}
			else if (v.second < u.second) {
				dinic::cap[i][j] = 1;
				// cout << i << " -> " << j << endl;
			}
		}
	}

	dinic::initAdj(sink + 1);
	int f = dinic::dinic(sink + 1, source, sink);
	return f == t;
}

const ld eps = 0.0000000000001;

int main() {
    // _upgrade;

	scanf("%d %d %d %d", &n, &s, &t, &q);

	ps.push_back({{0, 0}, 0});

	For (i, n) {
		int x, y, h;
		scanf("%d %d %d", &x, &y, &h);
		ps.push_back({{x, y}, h});
	}

	source = n + 1;
	sink = n + 2;

	For (i, s) {
		int x;
		scanf("%d", &x);
		S.push_back(x);
		// cout << source << " -> " << x << endl;
		dinic::cap[source][x] = 1;
	}

	For (i, t) {
		int x;
		scanf("%d", &x);
		T.push_back(x);
		// cout << x << " -> " << sink << endl;
		dinic::cap[x][sink] = 1;
	}

	// cout << "f: " << f << endl;

	if (!check(ld(q) + eps)) {
		puts("IMPOSSIBLE");
		return 0;
	}

	ld beg = 0;
	ld end = q;

	while (abs(beg - end) > 0.00000001) {
		ld mid = (beg + end) * 0.5;

		if (check(mid)) {
			end = mid;
		} else beg = mid;
	}

	ld ans = 0.0;
	

	printf("%.6Lf\n", ans);
}

