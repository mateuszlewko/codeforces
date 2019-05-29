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

const int N = 110;
bool con[N][N];
int perm[N];
int pos_of[N];

ll dp[N];

int main() {
	_upgrade;

	int n, m;
	cin >> n >> m;

	For (i, m) {
		int a, b;
		cin >> a >> b;
		con[b][a] = con[a][b] = 1;
	}

	For (i, n) {
		int cnt = 0;
		For (j, n) {
			if (j < i && !con[i][j]) cnt++;
			if (j > i && con[i][j]) cnt++;
		}

		perm[i] = cnt;
		pos_of[cnt] = i;
		// cout << cnt << " ";
	}
	// cout << endl;

	dp[perm[0]] = 1;
	for (int i = 1; i < n; i++) {
		int p = perm[i];

		for (int from = 0; from < p; from++) {
			if (pos_of[from] > i) continue;

			bool any_between = false;
			for (int j = pos_of[from] + 1; j < i; j++) {
				if (perm[j] < p && perm[j] > from) {
					any_between = true;
					break;
				}
			}

			if (any_between) continue;
			dp[p] += dp[from];
		}

		dp[p] = max(1LL, dp[p]);
	}

	ll sum = 0;

	For (i, n) {
		int p = perm[i];
		bool any_larger = false;
		for (int j = i + 1; j < n; j++) {
			if (perm[j] > p) {
				any_larger = true;
				break;
			}
		}

		if (!any_larger) {
			// error(p, dp[p]);
			sum += dp[p];
		}
	}

	cout << sum << "\n";
}

