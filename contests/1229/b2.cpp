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
ll A[N];
ll res = 0;
const ll MOD = 1000 * 1000 * 1000 + 7;
vector<int> G[N];

vector<pair<ll, int>> my_divs[N];
 
void go(int x, int p) {
	if (p != -1) {
		for (auto [d, cnt] : my_divs[p]) {
			ll num = __gcd(d, A[x]);

			if (my_divs[x].size() && my_divs[x].back().first == num) {
				my_divs[x].back().second += cnt;
			} else my_divs[x].emplace_back(num, cnt);
		}
	}
	
	if (my_divs[x].size() && my_divs[x].back().first == A[x]) {
		my_divs[x].back().second++;
	} else my_divs[x].emplace_back(A[x], 1);

	for (auto [d, cnt] : my_divs[x]) res = (res + d * cnt) % MOD;

	for (auto y : G[x]) {
		if (y == p) continue;
		go(y, x);
	}
}
 
int main() {
	_upgrade;
 
	int n;
	cin >> n;
 
	For (i, n) cin >> A[i + 1];
	For (i, n - 1) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
 
	go(1, -1);
	cout << (res % MOD) << "\n";
}