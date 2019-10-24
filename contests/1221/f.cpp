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

const int N = 5 * 100 * 1000 + 10;
int C[N];

map<int, vector<int>> beg_ixs;
map<int, vector<int>> end_ixs;

int main() {
	_upgrade;

	int n;
	cin >> n;

	set<int> ps_set;

	For (i, n) {
		int x, y, c;
		cin >> x >> y >> c;

		int p = min(x, y);
		int q = max(x, y);

		beg_ixs[p].push_back(i);
		end_ixs[q].push_back(i);
		ps_set.insert(p);
		ps_set.insert(q);
		C[i] = c;
	}

	vector<pair<int, vector<int>>> beg_v, end_v;
	// for (auto [p, ixs] : beg_ixs) beg_v.push_back({p, ixs});
	// for (auto [p, ixs] : end_ixs) end_v.push_back({p, ixs});

	// int bn = beg_v.size();
	// int en = end_v.size();

	ll curr = 0;
	ll best = 0;

	unordered_set<int> begs_present;
	unordered_set<int> ends_present;

	// int beg_ix = 0;
	// int end_ix = 0;

	vector<int> ps;
	for (int x : ps_set) ps.push_back(x);

	int b_ix = 0;
	int e_ix = 0;
	int psn = ps_set.size();

	while (b_ix < psn) {
		best = max(curr - (ps[e_ix] - ps[b_ix]), best);

		for (auto x : beg_ixs[ps[b_ix]]) {
			begs_present.insert(x);
		}

		while (e_ix < psn && e_ix < b_ix) {
			e_ix++;
			for (auto x : beg_ixs[ps[e_ix]]) {
				begs_present.insert(x);
			}
			for (auto x : end_ixs[ps[e_ix]]) {
				if (begs_present.count(x) == 1 && ends_present.count(x) == 0) {
					curr += C[x];
				}

				ends_present.insert(x);
			}
		}

		error("end-eq", curr, ps[e_ix], ps[b_ix]);
		best = max(curr - (ps[e_ix] - ps[b_ix]), best);
		
		while (e_ix < psn && curr - (ps[e_ix] - ps[b_ix]) > 0) {
			e_ix++;
			for (auto x : beg_ixs[ps[e_ix]]) {
				begs_present.insert(x);
			}
			for (auto x : end_ixs[ps[e_ix]]) {
				if (begs_present.count(x) == 1 && ends_present.count(x) == 0) {
					curr += C[x];
				}

				ends_present.insert(x);
			}

			error("end+1", curr, ps[e_ix], ps[b_ix]);
			best = max(curr - (ps[e_ix] - ps[b_ix]), best);
		}

		for (auto x : beg_ixs[ps[b_ix]]) {
			if (begs_present.count(x) == 1 && ends_present.count(x) == 1) {
				curr -= C[x];
			}

			begs_present.erase(x);
		} 

		b_ix++;
		// best = max(curr - (ps[e_ix] - ps[b_ix]), best);
		// error("beg+1", curr, ps[e_ix], ps[b_ix]);
	}
	
	cout << best << "\n";
}

