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

const int N = 150;
bitset<N> A[N];
map<pair<pii, pii>, int>  M;

int get_col(int x, int y, int len) {
	int col = 2;
	for (int i = x; i < x + len; i++) {
		for (int j = y; j < y + len; j++) {
			if (col == 2) col = A[i][j];
			else if (col != A[i][j]) return 2;
		}
	}

	return col;
}

int leaf_cnt = 0;
int vertex_cnt = 0;

int get_num(int x, int y, int len) {
	int col = get_col(x, y, len);
	vertex_cnt++;
	if (col != 2) {
		leaf_cnt++;
		return col;
	}

	error(x, y, len, col);
	len /= 2;

	int a = get_num(x, y, len);
	int b = get_num(x, y + len, len);
	int c = get_num(x + len, y, len);
	int d = get_num(x + len, y + len, len);

	pair<pii, pii> hs = {{a, b}, {c, d}};

	if (M.count(hs) == 0) {
		int id = int(M.size());
		return M[hs] = id;
	} else return M[hs];
}

void solve(int n, int m) {
	M.clear();
	leaf_cnt = 0;
	vertex_cnt = 0;

	int k = max(n, m);
	while (__builtin_popcount(k) != 1) k++;
	
	For (i, k + 2) A[i].reset();

	For (i, n) {
		For (j, m) {
			char c;
			cin >> c;
			A[i][j] = c == '1';
		}
	}

	int num = get_num(0, 0, k);
	error(num, leaf_cnt);
	cout << vertex_cnt << " " <<  num + leaf_cnt << "\n";
}

int main() {
	_upgrade;

	while (true) {
		int n, m;
		cin >> n >> m;

		if (n == 0 && m == 0) return 0;
		solve(n, m);
	}
}

