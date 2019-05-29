#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
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

const int N = 100 * 1000 + 10;  // limit for array size

int n;  // array size
ll t[2 * N];


class SegmentTree {
	int sz;
	vector<ll> tree;
	vector<pll> lazy;

	void split(int node, int x, int y) {
		if (lazy[node].second) {
			int z = (x + y) / 2;
			tree[2 * node] = (z - x) * lazy[node].first;
			tree[2 * node + 1] = (y - z) * lazy[node].first;
			lazy[2 * node] = lazy[node];
			lazy[2 * node + 1] = lazy[node];
			lazy[node].second = false;
		}
	}
	void merge(int node, int x, int y) {
		tree[node] = tree[2 * node] + tree[2 * node + 1];
	}

public:
	SegmentTree(int n) {
		for (sz = 1; sz < n; sz <<= 1);
		tree.resize(2 * sz/*, 0*/);
		lazy.resize(2 * sz/*, {0, false}*/);
	}

	void update(int l, int r, ll v, int node = 1, int x = 0, int y = -1) {
		if (y == -1) y = sz;
		if (r <= x || l >= y) return;
		if (l <= x && y <= r) {
			tree[node] = (y - x) * v;
			lazy[node] = {v, true};
			return;
		}
		split(node, x, y);
		update(l, r, v, 2 * node, x, (x + y) / 2);
		update(l, r, v, 2 * node + 1, (x + y) / 2, y);
		merge(node, x, y);
	}

	ll query(int l, int r, int node = 1, int x = 0, int y = -1) {
		if (y == -1) y = sz;
		if (r <= x || l >= y) return 0;
		if (l <= x && y <= r) return tree[node];
		split(node, x, y);
		ll res = query(l, r, 2 * node, x, (x + y) / 2)
			   + query(l, r, 2 * node + 1, (x + y) / 2, y);
		merge(node, x, y);
		return res;
	}	
};


int A[N];
int K[N];

int main() {
    _upgrade;

	int n;
	read(n);

	For (i, n) {
		read(t[i + n]);
		A[i] = t[i + 1];
	}
	For (i, n - 1) read(K[i]);

	build();

	set<pii> segs; // (end, begin)
	For (i, n) segs.insert({i, i});

	int q;
	read(q);

	For (i, q) {
		char c;
		read(c);

		if (c == 's') {
			int l, r;

			read(l, r);
			writeln(query(l - 1, r));
		} else {
			int pos;
			ll val;
			read(pos, val);

			auto it = segs.lower_bound({pos, 0});

		}
	}
}

