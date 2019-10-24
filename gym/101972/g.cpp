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

const int N = 505;
int A[N][N];
bool vis[N][N];

int n, m;
int max_go(int x, int y, int fx, int fy) {
	if (x == fx || y == fy) return 0;
	if (x < 1 || x > n || y < 1 || y > m) return 0;
	if (vis[x][y]) return 0;

	int res = A[x][y];
	int dx[] = {-1, 0, 0, 1};
	int dy[] = {0, 1, -1, 0};
	vis[x][y] = true;

	For (i, 4) res = max(res, max_go(x + dx[i], y + dy[i], fx, fy));
	
	return res;
}

int diff_for_cut(int x, int y) {
	vector<int> v;
	assert(x != 1);
	assert(y != 1);
	assert(x != n);
	assert(y != m);

	For (i, n + 2) For (j, m + 2) vis[i][j] = 0; 

	v.push_back(max_go(1, 1, x, y));
	v.push_back(max_go(n, 1, x, y));
	v.push_back(max_go(1, m, x, y));
	v.push_back(max_go(n, m, x, y));
	SORT(v);

	assert(v.front() != 0);
	return v.back() - v.front();
}

int main() {
	_upgrade;

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		vector<pair<int, pii>> fields;
		For (i, n) {
			For (j, m) {
				int v;
				cin >> v;
				A[i + 1][j + 1] = v;
				fields.push_back({v, {i + 1, j + 1}});
			}
		}

		SORT(fields);
		set<int> xs, ys; 
		ForD (i, fields.size()) {
			auto [x, y] = fields[i].second;
			if (x == 1 || x == n || y == 1 || y == m) continue;

			if (int(xs.size()) < 6) xs.insert(x);
			if (int(ys.size()) < 4) ys.insert(y);

			if (int(xs.size()) >= 4 && int(ys.size()) >= 4) break;
		}

		int best = 1<<30;
		for (auto x : xs) {
			for (auto y : ys) {
				best = min(best, diff_for_cut(x, y));
			}
		}

		assert(best < (1<<30));
		cout << best << "\n";
	}
}

