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
const ll INF = 1LL<<62;

ll C[4][N];
vector<int> G[N];

/*
ll dp[3][4][N];

bool wrong = false;

void go(int x, int p) {
	if (wrong) return;

	if (G[x].empty()) {
		For (i, 3) {
			dp[i][0][x] = C[i][x];
		}
	}

	vector<int> children;
	for (int y : G[x]) {
		if (y == x) continue;

		go(y, x);
		children.push_back(y);
	}

	int sz = int(children.size());

	if ((x != 1 && sz > 1) || sz > 2) {
		wrong = true;
		return;
	}

	if (sz == 1) {
		For (i, 3) {
			For (j, 3) {
				For (k, 4) dp[x][i][j] = min()
			}
		}
	}
}
*/

int col[N];

void go(int x, int p, int a, int b) {
	if (col[x] == 0) {
		for (int i = 1; i <= 3; i++) {
			if (i != a && i != b) {
				col[x] = i;
				break;
			}
		}
	}

	// error(x, col[x], p, a, b);

	for (int y : G[x]) {
		if (y == p) continue;

		go(y, x, col[x], a);
	}
}

ll cost(int n) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) sum += C[col[i]][i];
	return sum;
}

void clear(int n) {
	for (int i = 1; i <= n; i++) col[i] = 0; 
}

int main() {
	_upgrade;

	int n;
	cin >> n;

	For (i, 3) {
		For (j, n) cin >> C[i + 1][j + 1];
	}

	For (i, n - 1) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	for (int i = 1; i <= n; i++) {
		if (int(G[i].size()) >= 3) {
			cout << "-1\n";
			return 0;
		}
	}

	int x = 1;
	int y = G[x][0];

	ll res = INF;
	ll x_col = -1, y_col = -1;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			if (i == j) continue;

			clear(n);
			
			col[x] = i;
			col[y] = j;

			go(x, y, col[y], col[x]);
			go(y, x, col[x], col[y]);

			ll r = cost(n);
			// error(i, j, r);

			if (r < res) {
				res = r;
				x_col = i;
				y_col = j;
			}
		}
	}

	clear(n);

	col[x] = x_col;
	col[y] = y_col;
	go(x, y, y_col, x_col);
	go(y, x, x_col, y_col);

	cout << res << "\n";

	For (i, n) cout << col[i + 1] << " ";
}

