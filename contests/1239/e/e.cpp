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

const int N = 26;
const int M = 50 * 1000;
const int INF = 1<<30;

typedef bitset<62> mask;

int A[2 * N];
mask dp[2][N + 2][N * M + 10];

int main() {
	_upgrade;

	int n;
	cin >> n;
	
	n *= 2;
	For (i, n) cin >> A[i];
	sort(A, A + n);

	vector<int> res[2];
	For (i, 2) res[i].push_back(A[i]);

	int sum = 0;
	For (i, n - 2) {
		A[i] = A[i + 2];
		sum += A[i];
	}

	int m = n - 2;

	// For (i, 2) For (j, N) For (k, M + 1) dp[i][j][k] = -1;
	dp[0][0][0][60] = 1;

	For (i, m) {
		For (j, min(i, m / 2) + 1) {
			For (k, N * M + 1) {
				auto prev_m = dp[i % 2][j][k];
				if (!prev_m[60]) continue;
				int v = A[i];
				if (k + v > N * M) continue;

				int x = (i + 1) % 2;
				dp[x][j][k] = prev_m;
				prev_m[i] = 1;
				dp[x][j + 1][k + v] = prev_m;
				error(x, j+1, k+v, prev_m);
			} 
		} 
	}

	int best = INF;
	mask best_m = 0;

	For (i, N * M + 1) {
		auto msk = dp[m % 2][m / 2][i];
		if (!msk[60]) continue;

		int a = sum - i;
		int r = max(a, i);

		if (r < best) {
			best = r;
			best_m = msk;
		}
	}

	error(best_m);

	For (i, m) {
		res[best_m[i]].push_back(A[i]);
	}

	sort(res[0].begin(), res[0].end());
	sort(res[1].begin(), res[1].end(), greater<>());

	For (i, 2) cout << res[i] << "\n";
}

