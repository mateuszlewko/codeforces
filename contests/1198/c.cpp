#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

const int N = 300 * 1000 + 10;
vector<int> g_node[N];
vector<int> g_edge[N];
vector<int> incident_edges[N];

vector<int> indep_set(vector<int> G[], int n, int target) {
	vector<pii> v_by_deg;

	for (int i = 1; i <= n; i++) {
		v_by_deg.push_back({int(G[i].size()), i});
	}

	SORT(v_by_deg);
	vector<bool> taken;
	taken.resize(n + 10, false);

	vector<int> res; 

	for (auto [_, v] : v_by_deg) {
		if (taken[v]) continue;
		res.push_back(v);
		if (int(res.size()) == target) return res;

		for (int y : G[v]) taken[y] = true;
	}

	if (int(res.size()) == target) return res;
	return {};
}

void solve() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n * 3; i++) {
		g_node[i].clear();
		incident_edges[i].clear();
	}

	for (int i = 1; i <= m; i++) {
		g_edge[i].clear();
	}

	for (int i = 1; i <= m; i++) {
		int x, y;
		cin >> x >> y;


		g_node[x].push_back(y);
		g_node[y].push_back(x);
		if (m <= 4000) {
			for (int ex : incident_edges[x]) {
				for (int ey : incident_edges[y]) {
					if (ex == ey) continue;

					g_edge[ex].push_back(ey);
					g_edge[ey].push_back(ex);
				}
			}

			incident_edges[x].push_back(i);
			incident_edges[y].push_back(i);
		}
	}

	auto node_indep = indep_set(g_node, 3 * n, n);
	if (int(node_indep.size()) == n) {
		cout << "IndSet\n" << node_indep << "\n";
		return;
	} 

	if (m <= 4000) {
		auto edge_indep = indep_set(g_edge, m, n);
		if (int(edge_indep.size()) == n) {
			cout << "Matching\n" << edge_indep << "\n";
			return;
		}
	}

	cout << "Impossible\n";
}

int main() {
	_upgrade;

	set<int> s;
	auto it = s.find(4);
	cout << "eq: " << int(it == s.begin()) << endl;

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}

