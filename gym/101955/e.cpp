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

const ll INF = 1LL<<60;

struct Tree {
	typedef pair<pll, pll> T;
	T unit;

	bool is_max;

	static T F(bool is_max, const T &a, const T &b) { 
		T res = a;
		res.first = is_max ? max(max(a.first, a.second), max(b.second, b.first)) : min(min(a.first, a.second), min(b.first, b.second));

		if (a.first.second != res.first.second) 
			res.second = is_max ? max(res.second, a.first) : min(res.second, a.first);
		if (a.second.second != res.first.second) 
			res.second = is_max ? max(res.second, a.second) : min(res.second, a.second);

		if (b.first.second != res.first.second) 
			res.second = is_max ? max(res.second, b.first) : min(res.second, b.first);
		if (b.second.second != res.first.second) 
			res.second = is_max ? max(res.second, b.second) : min(res.second, b.second);

		return res;

		// if (a.empty()) return b;
		// if (b.empty()) return a;

		// T both(a3.begin(), a.end());
		// for (auto x : b) both.push_back(x);

		// if (is_max) sort(both.begin(), both.end(), less<pii>());
		// else sort(both.begin(), both.end(), greater<pii>());

		// T res = { both.back() };
		// for (int i = int(both.size()) - 2; i >= 0; i--) {
		// 	if (both[i + 1].second != both[i].second) {
		// 		res.push_back(both[i]);
		// 		break;
		// 	}
		// }

		// assert(int(res.size()) <= 2);

		// return res; 
	} 

	T f(const T &a, const T &b) {
		return F(is_max, a, b);
	}

	vector<T> s; int n;
	
	Tree(int n, bool is_max) : n(n), is_max(is_max) {
		if (is_max) unit = {{-INF, -1}, {-INF, -2}};
		else unit = {{INF, -1}, {INF, -2}};

		s = vector<T>(2*n, unit);
	}

	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}

	void build() {
		ForD (pos, n) s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}

	T query(int b, int e) { // query [b, e)
		T ra = unit, rb = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

const int N = 100 * 1000 + 10;
ll pos_x[N];
ll pos_y[N];
int cls[N];

void set_elem(Tree max_t[4], Tree min_t[4], int i, int c, ll x, ll y, bool fast = false) {
	For (j, 4) {
		ll nx = j % 2 ? x : -x;
		ll ny = (j>>1) % 2 ? y : -y;

		pll p = {nx + ny, c};
		if (fast) {
			max_t[j].s[i + max_t[j].n] = {p, p};
			min_t[j].s[i + min_t[j].n] = {p, p};

		} else {
			max_t[j].update(i, {p, p});
			min_t[j].update(i, {p, p});
		}
	}
}

void solve() {
	int n, m;
	cin >> n >> m;

	Tree max_t[4] = {Tree(n + 10, true), Tree(n + 10, true)
	                ,Tree(n + 10, true), Tree(n + 10, true)};
	Tree min_t[4] = {Tree(n + 10, false), Tree(n + 10, false)
	                ,Tree(n + 10, false), Tree(n + 10, false)};

	For (i, n) {
		ll x, y;
		int c;
		cin >> x >> y >> c;
		pos_x[i] = x;
		pos_y[i] = y;
		cls[i] = c;

		set_elem(max_t, min_t, i, c, x, y, true);
	}

	For (i, 4) {
		max_t[i].build();
		min_t[i].build();
	}

	For (i, m) {
		int t;
		cin >> t;

		if (t == 1) {
			int k;
			ll dx, dy;
			cin >> k >> dx >> dy;
			k--;

			pos_x[k] += dx;
			pos_y[k] += dy;

			set_elem(max_t, min_t, k, cls[k], pos_x[k], pos_y[k]);
		} else if (t == 2) {
			int k, c;
			cin >> k >> c;
			k--;

			cls[k] = c;
			set_elem(max_t, min_t, k, c, pos_x[k], pos_y[k]);
		} else {
			int l, r;
			cin >> l >> r;
			l--;

			// Tree::T min_res;
			// Tree::T max_res;

			// error(l, r);

			// For (j, 4) {
			// 	min_res = Tree::F(false, min_res, min_t[j].query(l, r));
			// 	cout << "min[" << j << "] = " << min_t[j].query(l, r) << endl;
			// }

			// For (j, 4) {
			// 	max_res = Tree::F(true, max_res, max_t[j].query(l, r));
			// 	cout << "max[" << j << "] = " << max_t[j].query(l, r) << endl;
			// }
			
			ll best = 0;
			For (j, 4) {
				auto min_res = min_t[j].query(l, r);
				auto max_res = max_t[j].query(l, r);

				// error(min_res, max_res);

				if (max_res.first.second != min_res.first.second)
					best = max(best, max_res.first.first - min_res.first.first);
				if (max_res.first.second != min_res.second.second)
					best = max(best, max_res.first.first - min_res.second.first);

				if (max_res.second.second != min_res.first.second)
					best = max(best, max_res.second.first - min_res.first.first);
				if (max_res.second.second != min_res.second.second)
					best = max(best, max_res.second.first - min_res.second.first);
			}

			cout << best << "\n";
		}
	}
}

int main() {
	_upgrade;

	int t;
	cin >> t;

	For (i, t) {
		cout << "Case #" << i + 1 << ":\n";
		solve();
	}
}
