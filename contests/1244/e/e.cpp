#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define SZ(x) (int((x).size()))
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

map<int, int> M;

ll move_next(ll k, int x, int cnt, pair<int, int> nx, int dir) {
	ll steps = min(k / cnt, (ll)abs(nx.first - x));
	error(nx, steps);

	k -= cnt * steps;
	M.erase(x);
	M[x + steps * dir] += cnt;

	return k;
}

int main() {
	_upgrade;

	int n;

	ll k;

	cin >> n >> k;

	For (i, n) {
		int x;
		cin >> x;

		M[x]++;
	}

	while (int(M.size()) > 1) {
		auto [p, p_cnt] = *M.begin();
		auto [q, q_cnt] = *M.rbegin();

		if (p_cnt < q_cnt) {
			if (p_cnt > k) break;
			error(k, p, p_cnt);
			k = move_next(k, p, p_cnt, *next(M.begin()), 1);
			error(k);
		} else {
			if (q_cnt > k) break;
			error(k, q, q_cnt);
			k = move_next(k, q, q_cnt, *next(M.rbegin()), -1);
			error(k);
		}
	}

	cout << M.rbegin()->first - M.begin()->first << "\n";
}

