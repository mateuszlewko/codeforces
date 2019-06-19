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

const int N = 510;
char A[N][N];
bool mark[N][N];

int n, m;
bool in_range(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}

int main() {
	_upgrade;

	cin >> n >> m;
	For (i, n) {
		For (j, m) cin >> A[i][j];
	}

	pii center_pos = {-1, -1};
	int dx[] = {-1, 1, 0, 0};
	int dy[] = {0, 0, -1, 1};

	For (i, n) {
		For (j, m) {
			if (A[i][j] != '*') continue;

			bool all = true;
			For (k, 4) {
				int nx = dx[k] + i;
				int ny = dy[k] + j;

				if (!in_range(nx, ny) || A[nx][ny] != '*') {
					all = false;
					break;
				}
			}

			if (all && center_pos.first != -1) {
				cout << "NO\n";
				return 0;
			}

			if (all) {
				center_pos = {i, j};
			}
		}
	}

	if (center_pos.first == -1) {
		cout << "NO\n";
		return 0;
	}

	mark[center_pos.first][center_pos.second] = true;
	For (i, 4) {
		for (int k = 1; k <= n; k++) {
			int nx = center_pos.first + dx[i] * k;
			int ny = center_pos.second + dy[i] * k;

			if (!in_range(nx, ny)) break;
			if (A[nx][ny] != '*') break;

			mark[nx][ny] = true;
		}
	} 

	For (i, n) {
		For (j, n) {
			if (!mark[i][j] && A[i][j] == '*') {
				cout << "NO\n";
				return 0;
			}
		}
	}

	cout << "YES\n";
}

