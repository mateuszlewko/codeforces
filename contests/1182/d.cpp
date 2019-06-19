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

const int N = 100 * 1000 + 10;
const ll B = 1000033;
const ll MOD = 1000000007;

vector<int> G[N];

ll hash_vec(const vector<ll> &v) {
	ll res = 1;
	ll mult = 1;

	for (ll x : v) {
		res = (res + (x * mult) % MOD) % MOD;
		mult = (mult * B) % MOD;
	}

	return res;
}

pair<bool, ll> check_tree(int x, int p) {
	vector<ll> hs;

	for (int y : G[x]) {
		if (y == p) continue;
		auto r = check_tree(y, x);

		if (!r.first) return {false, -1};
		if (hs.size() && hs.back() != r.second) return {false, -1};

		hs.push_back(r.second);
	}

	return {true, hash_vec(hs)};
}

int max_dist_v;
int max_dist;
void dfs(int x, int p, int d) {
	if (d > max_dist) {
		max_dist = d;
		max_dist_v = x;
	}

	for (int y : G[x]) {
		if (y == p) continue;

		dfs(y, x, d + 1);
	}
}

int last_remove_dist[N];
int dist[N];
int came_from[N];
const int INF = 1 << 30;

pii removal(int n) {
	queue<int> Q;
	vector<int> leafs;

	for (int i = 1; i <= n; i++) {
		last_remove_dist[i] = -1;

		if (int(G[i].size()) == 1) {
			Q.push(i);
			dist[i] = 0;
			came_from[i] = i;
			leafs.push_back(i);
			last_remove_dist[i] = 0;
		} else dist[i] = INF;
	}

	while (Q.size()) {
		int x = Q.front();
		Q.pop();

		for (int y : G[x]) {
			if (int(G[y].size()) > 2) continue;

			if (dist[y] > dist[x] + 1) {
				dist[y] = dist[x] + 1;
				came_from[y] = came_from[x];

				last_remove_dist[came_from[y]] = max(last_remove_dist[came_from[y]], dist[y]);
			}
		}
	}

	vector<pii> dists;
	for (int i = 1; i <= n; i++) {
		if (int(G[i].size()) == 1 && last_remove_dist[i] != -1) {
			dists.push_back({last_remove_dist[i], i});
		}
	}

	SORT(dists);
	if (dists.empty()) {
		return {leafs.front(), leafs.back()};
	} else {
		return {dists.front().second, dists.back().second};
	}
} 

pair<pii, int> longest_path() {
	max_dist_v = -1;
	max_dist = -1;

	dfs(1, -1, 0);
	assert(max_dist_v != -1);

	pii res;
	res.first = max_dist_v;

	max_dist_v = -1;
	max_dist = -1;

	dfs(res.first, -1, 0);
	assert(max_dist_v != -1);
	res.second = max_dist_v;

	return {res, max_dist};
}

int found_middle = -1;

void dfs2(int x, int p, int target_d, int d) {
	if (found_middle != -1) return;

	if (d == target_d) {
		found_middle = x;
		return;
	}

	for (int y : G[x]) {
		if (y == p) continue;
		dfs2(y, x, target_d, d + 1);
	}
}

int middle(int d, int n) {
	for (int i = 1; i <= n; i++) {
		if (int(G[i].size()) == 1) {
			dfs2(i, -1, d / 2, 0);

			return found_middle;
		}
	}

	return 1;
}

int main() {
	_upgrade;

	int n;
	cin >> n;

	For (i, n - 1) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	auto rr = longest_path();
	auto c1 = rr.first;
	int d = rr.second;

	if (check_tree(c1.first, -1).first) {
		cout << c1.first << "\n";
	} else if (check_tree(c1.second, -1).first) {
		cout << c1.second << "\n";
	} else {
		int c2 = middle(d, n);
		if (check_tree(c2, -1).first) {
			cout << c2 << "\n";
		} else {
			auto c3 = removal(n);
			// error(c3);

			if (check_tree(c3.first, -1).first) {
				cout << c3.first << "\n";
			} else if (check_tree(c3.second, -1).first) {
				cout << c3.second << "\n";
			}
			else cout << "-1\n";
		}
	}
}

