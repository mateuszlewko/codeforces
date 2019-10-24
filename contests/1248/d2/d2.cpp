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

const int N = 300 * 1000 + 10;
int lvl[N];
string s;

int get_mn_pos(int n) {
	int mn = 0;
	int mn_pos = 0;
	
	for (int i = 1; i <= n; i++) {
		char c = s[i - 1];
		if (c == '(') lvl[i] = lvl[i - 1] + 1;
		else lvl[i] = lvl[i - 1] - 1;

		mn = min(mn, lvl[i]);
		if (lvl[i] == mn) mn_pos = i;
	}

	return mn_pos;
}

int num_of(int n, int x) {
	int cnt = 0;
	For (i, n) if (lvl[i] == x) cnt++;

	return cnt;
}

pair<int, pii> calc_dp(int mn_val, int n) {
	int best = 0;
	pii best_p = {1, 1};

	int beg = 1;
	int cnt = 0;

	for (int i = 2; i <= n; i++) {
		if (lvl[i] < mn_val) {
			if (cnt > best) {
				best = cnt;
				best_p = {beg, i - 1};
			}

			beg = i;
			cnt = 0;
		} else if (lvl[i] == mn_val) cnt++;
	}

	return {best, best_p};	
}

int trans(int x, int n, int rot) {
	if (x <= n - rot + 1) return rot + x - 1;
	else return x - rot + 1;
}

int main() {
	_upgrade;

	int n;
	cin >> n >> s;

	int pos = get_mn_pos(n);

	if (lvl[n] != 0) {
		cout << "0\n1 1\n";
		return 0;
	}

	rotate(s.begin(), s.begin() + pos, s.end());
	error(s);

	get_mn_pos(n);

	int zero_cnt = num_of(n, 0);
	int best = zero_cnt;
	pii best_p = {1, 1};
	
	For (i, 2) {
		auto [r, p] = calc_dp(i + 1, n);

		// r += zero_cnt - 1;
		if (i == 1) r += zero_cnt;

		error(i, r, p);

		if (r > best) {
			best = r;
			best_p = p;
		}
	}

	error(best_p);
	cout << best << "\n" << trans(best_p.first, n, pos) << " " << trans(best_p.second, n, pos) << endl;
}

