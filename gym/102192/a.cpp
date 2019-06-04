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

const int N = 2 * 100 * 1000 + 10;
ll factor[N];
ll inv_factor[N];

ll fast_pow(ll x, ll n) {
	if (n == 0) return 1LL;
	ll r = fast_pow(x, n / 2LL);
	r = (r * r) % MOD;
	
	if (n % 2 == 1) r = (r * x) % MOD;
	return r;
}

void init_factors() {
	ll f = 1;

	factor[0] = 1;
	inv_factor[0] = 1;

	for (ll i = 1; i < N; i++) {
		f = (f * (ll)i) % MOD;
		factor[i] = f;
		inv_factor[i] = fast_pow(f, MOD - 2);
	}
}

ll binomial(ll n, ll k) {
	if (n < 0) return 0LL;
	if (k > n) return 0LL;
	if (n >= N || k >= N) return 0LL;

	ll r = (factor[n] * inv_factor[k]) % MOD;
	return (r * inv_factor[n - k]) % MOD;
}

void solve() {
	ll n, m, k;
	cin >> n >> m >> k;

	ll sum = 0;
	for (ll i = 0; i <= m; i++) {
		ll r = binomial(k + m - 1 - i * n, m - 1) * binomial(m, i);
		r %= MOD;
		
		if (i % 2 == 0) sum = (sum + r) % MOD;
		else sum = (sum - r + MOD) % MOD;
	}

	cout << sum << "\n";
}

int main() {
	_upgrade;

	init_factors();

	int t;
	cin >> t;

	while (t--) solve();
}

