#pragma region Template 
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

#pragma endregion 

const int N = 1000 * 1000 + 10;
const int INF = 1<<30;
int max_left[N];

int open[N];
int close[N];
int A[N];

int main() {
	_upgrade;

	int n;
	ll x;
	cin >> n >> x;

	For (i, n) cin >> A[i];

	max_left[0] = A[0];
	for (int i = 1; i < n; i++) max_left[i] = max(max_left[i - 1], A[i]);

	For (i, n) {
		if (A[i] < max_left[i]) {
			open[max_left[i] + 1]++;
			if (A[i] > 1) {
				open[1]++;
				close[A[i] - 1]++;
			}

			if (A[i] + 1 < max_left[i]) { 
				open[A[i] + 1]++;
				close[max_left[i] - 1]++;
			}
		}
	}

	int opened = 0;
	ll len = 0;

	ll res = x * (x + 1) / 2;

	for (int i = 1; i <= x; i++) {
		error(i, open[i], close[i]);

		opened += open[i];
		if (opened > 0) len++;
		
		opened -= close[i];
		if (opened == 0 && len > 0) {
			res -= len * (len + 1) / 2;
			len = 0;
		}
	}
	
	res -= len * (len + 1) / 2;
	cout << res << "\n";
}

