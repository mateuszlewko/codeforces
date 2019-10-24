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
int mx_to[4][N][N];
int n, m;

void calc_mx(int ix, int x, int y, int dx, int dy) {
	for (int i = x; i > 0 && i <= n; i += dx) {
		for (int j = y; j > 0 && j <= m; j += dy) {
			mx_to[ix][i][j] = max(mx_to[ix][i - dx][j], mx_to[ix][i][j - dy]);
			mx_to[ix][i][j] = max(mx_to[ix][i][j], A[i][j]);
		}
	}
}

int main() {
	_upgrade;

	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;

		For (i, n + 5) For (j, m + 5) A[i][j] = 0;
		For (k, 4) For (i, n + 5) For (j, m + 5) mx_to[k][i][j] = 0;

		For (i, n) {
			For (j, m) {
				int v;
				cin >> v;
				A[i + 1][j + 1] = v;
			}
		}


		int sx[] = {1, 1, n, n};
		int sy[] = {1, m, 1, m};

		int dx[] = {1, 1, -1, -1};
		int dy[] = {1, -1, 1, -1};

		For (i, 4) {
			calc_mx(i, sx[i], sy[i], dx[i], dy[i]);
		}

		int best = 1<<30;
		for (int i = 2; i < n; i++) {
			for (int j = 2; j < m; j++) {
				vector<int> vs;
				For (k, 4) {
					vs.push_back(mx_to[k][i - dx[k]][j - dy[k]]);
				}

				SORT(vs);
				best = min(best, vs.back() - vs.front());
			}
		}

		cout << best << "\n";
	}
}

