#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef JUST_CPP11
template<typename... Args>
void read(Args&... args)
{
    ((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
    ((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
	cout << "\n";
}
#endif

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

const int N = 100 * 1000 + 10;
bool vis[N];

vector<int> G[N];

pair<int, int> go(int x, int parent, bool set_vis = false) {
	if (set_vis) vis[x] = true;

	int best_d = 0;
	int best = x;

	for (int y : G[x]) {
		if (vis[y] || y == parent) continue;

		auto p = go(y, x, set_vis);
		int child_d = p.first + 1;
		int child = p.second;

		if (child_d> best_d) {
			best_d = child_d;
			best = child;
		}
	}

	return {best_d, best};
}

int diam(int x) {
	auto p = go(x, -1);
	// error(x, p);
	return go(p.second, -1, true).first;
}

int main() {
    _upgrade;

		int n, m;
		cin >> n >> m;

		For (i, m) {
			int x, y;
			cin >> x >> y;

			G[x].push_back(y);
			G[y].push_back(x);
		}

		vector<int> ds;
		For (i, n) {
			if (vis[i]) continue;
			ds.push_back(diam(i));
		}

		SORT(ds);

		// error(ds);

		assert(ds.size() > 0);

		if (ds.size() == 1) {
			cout << ds[0] << "\n";
			return 0;
		} 
		
		int dn = ds[ds.size() - 1];

		if (ds.size() == 2) {
			cout << max(dn, ((ds[0] + 1) / 2) + 1 + ((ds[1] + 1) / 2)) << "\n";
			return 0;
		}

		int dn1 = ds[ds.size() - 2];
		int dn2 = ds[ds.size() - 3];

		int res1 = (dn2 + 1) / 2 + 2 + (dn1 + 1) / 2;
		int res2 = (dn1 + 1) / 2 + 1 + (dn + 1) / 2;
		
		cout << max(res1, max(res2, dn)) << "\n";
}


