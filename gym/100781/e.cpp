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

unordered_map<int, int> large2small;
const int N = 100 * 1000 + 10;
pii A[N];

const int TREE_N = 1<<19; 
int max_from_bottom[TREE_N * 4];
int add_on_me[TREE_N * 4];

void update(int x) {
	int children_max = 0;
	if (x < TREE_N) {
		children_max = max(max_from_bottom[x * 2], max_from_bottom[x * 2 + 1]);
	}

	max_from_bottom[x] = children_max + add_on_me[x];
}

void push_go(int l, int r, int x, int p, int q) {
	if (p >= l && r >= q) {
		// cout << "added on --> ";
		// error(l, r, p, q, x);
		// cout << endl;
		add_on_me[x]++;
		update(x);

		return;
	}

	int mid = (p + q) / 2;
	if (l <= mid) {
		push_go(l, min(r, mid), x * 2, p, mid);
	}

	if (r > mid) {
		push_go(max(l, mid + 1), r, x * 2 + 1, mid + 1, q);
	}

	update(x);
}

void push(int l, int r) {
	push_go(l, r, 1, 0, TREE_N - 1);
}

int query_res;

void query_go(int l, int r, int x, int p, int q, int from_top) {
	if (p >= l && r >= q) {
		// error(x, p, q, max_from_bottom[x], from_top);
		query_res = max(query_res, max_from_bottom[x] + from_top);
		return;
	}

	// error(l, r);

	int mid = (p + q) / 2;
	int from_me = from_top + add_on_me[x];

	if (l <= mid) {
		query_go(l, min(r, mid), x * 2, p, mid, from_me);
	}

	if (r > mid) {
		query_go(max(mid + 1, l), r, x * 2 + 1, mid + 1, q, from_me);
	}
}

int query(int l, int r) {
	query_res = 0;
	query_go(l, r, 1, 0, TREE_N - 1, 0);
	return query_res;
} 

int main() {
	_upgrade;

	int n, k;

	vector<int> ps;

	cin >> n >> k;

	For (i, n) {
		int x, y;
		cin >> x >> y;

		x++;
		A[i] = {x, y};
		ps.push_back(x);
		ps.push_back(y);
	}

	SORT(ps);

	for (int p : ps) {
		if (large2small.count(p) == 0) {
			int x = large2small.size() + 1;
			large2small[p] = x;
		}
	}

	auto cmp = [](pii lhs, pii rhs) {
		if (lhs.second != rhs.second) {
			return lhs.second < rhs.second;
		}

		return lhs.first >= rhs.first;
	};

	sort(A, A + n, cmp);

	int res = 0;
	For (i, n) {
		int l = large2small[A[i].first];
		int r = large2small[A[i].second];
		// error(A[i].first, A[i].second, l, r);
		// int q = query(l, r);
		// error(q);

		if (query(l, r) < k) {
			// cout << "pushing\n";
			// error(l, r);
			// cout << endl;

			push(l, r);
			res++;
		}
	}

	cout << res << "\n";
}
