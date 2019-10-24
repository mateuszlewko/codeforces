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

const int N = 200 * 1000 + 10;
int sub_size[N];
vector<int> G[N];

int go_sub_size(int x, int p) {
	int sum = 1;
	for (int y : G[x]) {
		if (y == p) continue;
		sum += go_sub_size(y, x);
	}

	return sub_size[x] = sum;
}

ll score_down[N];

ll go_score_down(int x, int p) {
	ll sum = sub_size[x];

	for (int y : G[x]) {
		if (y == p) continue;
		sum += go_score_down(y, x);
	}

	return score_down[x] = sum;
}

int n;
ll best = 0;

void go(int x, int p, ll score_from_top) {
	
	// error(x, p, score_from_top);


	ll child_sum = 0;
	for (int y : G[x]) {
		if (y == p) continue;

		child_sum += score_down[y];
	}
	ll my_score = n + child_sum + score_from_top;
	best = max(best, my_score);

	for (int y : G[x]) {
		if (y == p) continue;

		ll next_score_top = (n - sub_size[y]) + score_from_top + child_sum - score_down[y];
		go(y, x, next_score_top);
	}
}

int main() {
	_upgrade;

	cin >> n;

	For (i, n - 1) {
		int x, y;
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	go_sub_size(1, -1);
	go_score_down(1, -1);
	go(1, -1, 0);

	// For (i, n) {
	// 	cout << i + 1 << " -> " << score_down[i + 1] << "\n";
	// }
	cout << best << "\n";
}

