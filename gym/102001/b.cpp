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

const int N = 2 * 100 * 1000 + 10;
unordered_map<int, vector<int>> X, Y;

int px[N];
int py[N];

int pos_on_x[N];
int pos_on_y[N];

unordered_set<int> vis_x;
unordered_set<int> vis_y;

bool vis[N];

void go(int p) {
	if (vis[p]) return;

	vis[p] = true;

	int x = px[p];
	int y = py[p];

	vis_x.insert(x);
	vis_y.insert(y);

	int my_pos_on_x = pos_on_x[p];
	if (my_pos_on_x > 0) go(X[x][my_pos_on_x - 1]);
	if (my_pos_on_x + 1 < int(X[x].size())) go(X[x][my_pos_on_x + 1]);

	int my_pos_on_y = pos_on_y[p];
	if (my_pos_on_y > 0) go(Y[y][my_pos_on_y - 1]);
	if (my_pos_on_y + 1 < int(Y[y].size())) go(Y[y][my_pos_on_y + 1]);

}

int main() {
	_upgrade;

	#ifndef DEBUG
  freopen("game.in", "r", stdin);
  freopen("game.out", "w", stdout);
  #endif

	int n;
	cin >> n;

	For (i, n) {
		int x, y;
		cin >> x >> y;

		X[x].push_back(i);
		pos_on_x[i] = int(X[x].size()) - 1;
		Y[y].push_back(i);
		pos_on_y[i] = int(Y[y].size()) - 1;

		px[i] = x;
		py[i] = y;
	}

	ll total = 0;

	For (i, n) {
		if (vis[i]) continue;
		
		int x = px[i];
		int y = py[i];

		if (int(X[x].size()) < 2 || int(Y[y].size()) < 2) continue;

		vis_x.clear();		
		vis_y.clear();		

		go(i);
		total += ll(vis_x.size()) * ll(vis_y.size());
	}

	For (i, n) if (!vis[i]) total++;

	cout << total << "\n";
}