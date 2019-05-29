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

const int W = 24;
bool board[W][W];
int h, w;

int tc = 1;

void print_ans() {
	cout << "Data set " << tc << " ends with boxes at locations ";
	vector<pii> ps;

	For (i, h) {
		For (j, w) {
			if (board[i][j]) {
				ps.push_back({i, j});
			}
		}
	}

	SORT(ps);

	int n = ps.size();
	For (i, n) {
		cout << "(" << ps[i].first << "," << ps[i].second << ")";
		if (i < n - 1) cout << " ";
		else cout << ".";
	}

	cout << "\n";
	tc++;
}

bool in_range(int x, int y) {
	return x >= 0 && y >= 0 && x < h && y < w;
}

void go(int x, int y, int dx, int dy, int line, int boxes) {
	if (!in_range(x, y) && (boxes > 0 || line > 0)) {
		assert(false);
		error(x, y, dx, dy, line, boxes);
	}

	if (!in_range(x, y) || (boxes == 0 && line == 0)) return;
	
	if (board[x][y] && line > 0) {
		board[x][y] = 0;
		boxes++;
	} else if (!board[x][y] && line == 0 && boxes > 0) {
		board[x][y] = 1;
		boxes--;
	}

	line = max(0, line - 1);
	go(x + dx, y + dy, dx, dy, line, boxes);
}

pii calc_mx() {
	int mx_h = 0;
	int mx_w = 0;

	For (i, h) {
		int cnt_w = 0;
		For (j, w) if (board[i][j]) cnt_w++;

		mx_w = max(mx_w, cnt_w);
	}

	For (i, w) {
		int cnt_h = 0;
		For (j, h) if (board[j][i]) cnt_h++;

		mx_h = max(mx_h, cnt_h);
	}

	return {mx_h, mx_w};
}

void solve(int n, int m) {
	int k;
	cin >> k;

	h = n;
	w = m;

	For (i, h + 1) For (j, w + 1) board[i][j] = 0;

	For (i, k) {
		int x, y;

		cin >> x >> y;
		board[x][y] = 1;
	}

	while (true) {
		string cmd;
		cin >> cmd;
		if (cmd == "done") break;

		int d;
		cin >> d;

		auto mx = calc_mx();
		int mx_h = mx.first;
		int mx_w = mx.second;

		if (cmd == "down" || cmd == "up") d = min(d, h - mx_h);
		else d = min(d, w - mx_w);

		if (cmd == "down")  For (i, w) go(0    , i    ,  1,  0, d, 0);
		if (cmd == "up")    For (i, w) go(h - 1, i    , -1,  0, d, 0);
		if (cmd == "left")  For (i, h) go(i    , w - 1,  0, -1, d, 0);
		if (cmd == "right") For (i, h) go(i    , 0    ,  0,  1, d, 0);
	}

	print_ans();
}

int main() {
	_upgrade;

	while (true) {
		int n, m; 
		cin >> n >> m;
		if (n == 0 && m == 0) break;

		solve(n, m);
	}
}

