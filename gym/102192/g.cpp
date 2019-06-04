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

const ll MOD = 998244353LL;
ll ways;
int cost;

const int N = 2 * 100 * 1000 + 10;

int taken[N];
bitset<N> present;

bool vis[N];

vector<pii> G[N];

vector<int> curr_vis;
int total_edges = 0;
map<pii, int> E;

void dfs(int x) {
	if (vis[x]) return;
	
	vis[x] = true;
	total_edges += int(G[x].size());
	curr_vis.push_back(x);

	for (auto e : G[x]) dfs(e.first);
}

int down_cost[N];

int tree_root_cost(int x, int p) {
	int sum = 0;

	for (auto yc : G[x]) {
		int y = yc.first;
		int c = yc.second;

		if (y == p) continue;
		sum += tree_root_cost(y, x) + c;
	}

	return down_cost[x] = sum;
}

void go_dp(int x, int p, int from_top, map<int, int> &cost_ways) {
	int curr_c = from_top + down_cost[x];
	cost_ways[curr_c]++;

	for (auto yc : G[x]) {
		int y = yc.first;
		int c = yc.second;

		if (y == p) continue;

		int n_from_top = down_cost[x] - down_cost[y] + from_top;
		if (c == 0) n_from_top++;
		else n_from_top--;

		go_dp(y, x, n_from_top, cost_ways);
	}
}

void tree_dp() {
	int r = curr_vis[0];
	tree_root_cost(r, -1);
	// for (int x : curr_vis) {
	// 	error(x, down_cost[x]);
	// }

	map<int, int> cost_ways;
	go_dp(r, -1, 0, cost_ways);

	// for (auto cw : cost_ways) {
	// 	error(cw);
	// }

	auto cw = *cost_ways.begin();
	
	cost += cw.first;
	ways = (ways * cw.second) % MOD;
}

bitset<N> vis_cycle;
vector<int> cycle_stack;
vector<int> found_cycle;

void dfs_cycle(int x, int p) {
	if (vis_cycle[x] || found_cycle.size()) return;
	vis_cycle[x] = true;

	cycle_stack.push_back(x);

	for (auto yc : G[x]) {
		if (found_cycle.size()) return; 
		if (yc.first == p) continue;
		if (vis_cycle[yc.first]) {
			error(cycle_stack, yc.first);

			while (cycle_stack.back() != yc.first) {
				found_cycle.push_back(cycle_stack.back());
				cycle_stack.pop_back();
				assert(cycle_stack.size());
			}

			found_cycle.push_back(cycle_stack.back());
			return;
		}

		dfs_cycle(yc.first, x);
	}

	// assert(cycle_stack.size());
	if (cycle_stack.size()) cycle_stack.pop_back();
}

void calc_cycle() {
	found_cycle.clear();
	cycle_stack.clear();

	for (int x : curr_vis) {
		vis_cycle[x] = false;
		down_cost[x] = 0;
	}

	assert(curr_vis.size());
	dfs_cycle(curr_vis[0], -1);

	int nc = found_cycle.size();
	int c1 = 0, c2 = 0;

	For (i, nc) {
		int x = found_cycle[i];
		int pe = found_cycle[(i - 1 + nc) % nc];
		int ne = found_cycle[(i + 1) % nc];

		c1 += E[{x, ne}];
		c2 += E[{ne, x}];

		for (auto yc : G[x]) {
			if (yc.first == pe || yc.first == ne) continue;

			int c = yc.second + tree_root_cost(yc.first, x);
			cost += c;
		}
	}

	if (c2 == c1) {
		ways = (ways * 2LL) % MOD;
	} 
	cost += min(c1, c2);
}

bool solve_vis(bool is_cycle) {
	vector<int> curr_taken;

	for (int x : curr_vis) {
		down_cost[x] = 0;
		if (taken[x]) curr_taken.push_back(x);
	}

	int taken_cnt = curr_taken.size();
	if (taken_cnt >= 2 || (is_cycle && taken_cnt >= 1)) return false;

	if (taken_cnt == 1) cost += tree_root_cost(curr_taken[0], -1);
	else if (!is_cycle) tree_dp();
 	else calc_cycle();

	return true;
}

void solve() {
	ways = 1;
	cost = 0;
	total_edges = 0;
	E.clear();

	int n;
	cin >> n;

	For (i, 2 * n + 5) {
		taken[i] = 0;
		present[i] = 0;
		G[i].clear();
		vis[i] = 0;
	}

	map<pii, vector<pii>> M;

	For (i, n) {
		int x, y;
		cin >> x >> y;

		pii v = {x, y};
		if (x > y) swap(x, y);
		pii k = {x, y};

		M[k].push_back(v);
	}

	for (auto it : M) {
		int x = it.second[0].first;
		int y = it.second[0].second;

		if (it.second.size() > 2) {
			cout << "-1 -1\n";
			return;
		}

		if (it.second.size() >= 2 && x == y) {
			cout << "-1 -1\n";
			return;
		} 

		if (x == y) {
			taken[x]++;
			continue;
		}
		
		if (it.second.size() == 1) {
			present[x] = present[y] = true;

			G[x].push_back({y, 1});
			G[y].push_back({x, 0});
			E[{x, y}] = 1;
			E[{y, x}] = 0;
		}
		else {
			taken[x]++;
			taken[y]++;

			if (it.second[0] == it.second[1]) {
				ways *= 2LL;
				ways %= MOD;
				cost++;
			}
		}
	}

	For (i, 2 * n + 2) { 
		if (taken[i] >= 2) {
			cout << "-1 -1\n";
			return;
		}
	}

	For (i, 2 * n + 2) {
		if (!present[i] || vis[i]) continue;

		total_edges = 0;
		curr_vis.clear();
		
		dfs(i);
		error(i, curr_vis);

		total_edges /= 2;
		int total_nodes = int(curr_vis.size());
		if (total_edges > total_nodes) {
			cout << "-1 -1\n";
			return;
		}
		
		if (!solve_vis(total_edges == total_nodes)) {
			cout << "-1 -1\n";
			return;
		}
	}

	cout << cost << " " << ways << "\n";
}

int main() {
	_upgrade;

	int t;
	cin >> t;

	while (t--) solve();
}

