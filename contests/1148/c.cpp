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

const int N = 3 * 100 * 1000 + 10;

int A[N];
int pos_of[N];
vector<pii> ans;

void do_swap(int i, int j) {
	if (i == j) return;

	swap(A[i], A[j]);
	swap(pos_of[A[i]], pos_of[A[j]]);

	ans.push_back({i, j});
}

int main() {
	_upgrade;

	int n;
	cin >> n;

	For (i, n) {
		cin >> A[i + 1];
		pos_of[A[i + 1]] = i + 1;
	}

	for (int i = n / 2 + 1; i < n; i++) {
		if (pos_of[i] == i) continue;

		if (abs(pos_of[i] - i) >= n / 2) {
			do_swap(pos_of[i], i);
		} else if (abs(pos_of[i] - 1) >= n / 2) {
			do_swap(pos_of[i], 1);
			do_swap(1, i);
		} else {
			do_swap(pos_of[i], n);
			do_swap(n, 1);	
			do_swap(1, i);
		}
	}

	for (int i = 2; i <= n / 2; i++) {
		if (pos_of[i] == i) continue;
		
		if (abs(pos_of[i] - i) >= n / 2) {
			do_swap(pos_of[i], i);
		} else if (abs(pos_of[i] - n) >= n / 2) {
			do_swap(pos_of[i], n);
			do_swap(n, i);
		} else {
			do_swap(pos_of[i], 1);
			do_swap(1, n);
			do_swap(n, i);
		}
	}

	// cout << "pos: " << endl;
	// For (i, n) cout << pos_of[i + 1] << " "; 
	// cout << endl;

	if (pos_of[1] != 1) {
		do_swap(pos_of[1], 1);
	}

	for (int i = 2; i <= n; i++) {
		assert(A[i] > A[i - 1]);
	}

	assert(int(ans.size()) <= 5 * n);

	cout << ans.size() << "\n";
	for (auto a : ans) {
		cout << a.first << " " << a.second << "\n";
		// error(a);
		assert(abs(a.first - a.second) >= n / 2);
	}
}

