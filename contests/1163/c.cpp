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

map<pll, ll> cnt;

ll sign(ll x) {
	if (x < 0) return -1;
	if (x == 0) return 0;
	return 1;
}

const ll INF = (1LL<<61) + 31739LL;

pll get(ll top, ll bot) {
	if (bot == 0) return {INF, INF};
	ll s = sign(bot);
	ll d = __gcd(abs(top), abs(bot));

	return {(s * top) / d, (s * bot) / d};
}

const int N = 1010;
pll A[N];

int main() {
	_upgrade;

	int n;
	cin >> n;

	For (i, n) cin >> A[i].first >> A[i].second;

	set<pair<pll, pll>> ls;

	For (i, n) {
		for (int j = i + 1; j < n; j++) {
			ll a = A[i].second - A[j].second;
			ll b = A[j].first - A[i].first;
			ll c = A[i].first * A[j].second - A[j].first * A[i].second;

			pll p1 = get(a, b);
			pll p2 = b != 0 ? get(c, b) : get(c, a);
			
			ls.insert({p1, p2});

			// cnt[{p1, p2}]++;
		}
	}

	ll total = 0;

	for (auto l : ls) {
		pll p1 = l.first;
		// pll p2 = l.second;

		// error(l);
		cnt[p1]++;
	}

	// error(ls.size());

	for (auto l : ls) {
		pll p1 = l.first;
		// pll p2 = l.second;

		ll common = cnt[p1];
		total += ll(ls.size()) - common;
	}

	// ll lines = (ll)n * (n - 1) / 2LL;
	// ll total = lines * (lines - 1) / 2;

	// for (auto it : cnt) {
	// 	error(it);

	// 	ll c = it.second;
	// 	total -= c * (c - 1) / 2;
	// }

	assert(total >= 0);
	cout << total / 2LL << "\n";
}

