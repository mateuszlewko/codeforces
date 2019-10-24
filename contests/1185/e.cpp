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

vector<pii> pos_of[30];
const int N = 2010;
char A[N][N];

char res[N][N];

void draw(char c, int x, int y, int dx, int dy, int len) {
	For (i, len) {
		res[x + dx * i][y + dy * i] = c;
	}
}

bool check(int n, int m) {
	For (i, n) {
		For (j, m) {
			if (A[i][j] != res[i][j]) return false;
		}
	}

	return true;
}

void solve() {
	int n, m;
	cin >> n >> m;

	int max_c = -1;

	For (i, n) {
		For (j, m) {
			res[i][j] = '.';
		}
	}

	For (i, 30) pos_of[i].clear();

	For (i, n) {
		For (j, m) {
			cin >> A[i][j];
			if (A[i][j] != '.') {
				int c = int(A[i][j] - 'a');
				max_c = max(max_c, c);
				pos_of[c].push_back({i, j});
			}
		}
	}

	vector<pair<pii, pii>> ans;

	if (max_c == -1) {
		cout << "YES\n0\n";
		return;
	}

	For (i, max_c + 1) {
		if (pos_of[i].empty()) {
			auto p = pos_of[max_c].front();
			draw(char('a' + i), p.first, p.second, 1, 0, 1);
			
			p.first++;
			p.second++;

			ans.push_back({p, p});
			continue;
		}

		SORT(pos_of[i]);

		pii l = pos_of[i].front();
		pii r = pos_of[i].back();

		ans.push_back({{l.first + 1, l.second + 1}, {r.first + 1, r.second + 1}});
		if (l.second == r.second) {
			draw(char('a' + i), l.first, l.second, 1, 0, r.first - l.first + 1);
		} else if (l.first == r.first) {
			draw(char('a' + i), l.first, l.second, 0, 1, r.second - l.second + 1);
		} else {
			cout << "NO\n";
			return;
		}
	}

	if (!check(n, m)) {
		// cout << endl;
		// For (i, n) {
		// 	For (j, m) {
		// 		cout << res[i][j];
		// 	}
		// 	cout << endl;
		// }
		cout << "NO\n";
		return;
	}

	cout << "YES\n" << ans.size() << "\n";
	for (auto aa : ans) cout << aa << "\n";
}

int main() {
	_upgrade;

	int t;
	cin >> t;

	while (t--) solve();
}

