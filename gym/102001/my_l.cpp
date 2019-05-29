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

const int N = 110;

int A[N];
int n, c, p;
ll t;

int B[N];

int sum_all = 0;

bool check(int k) {
	if (k > sum_all) return false;
	
	int left = k;
	ll total_t = 0;

	int todo = 0;

	For (i, n) {
		B[i] = min(left, A[i]);
		left -= B[i];
		
		int w = B[i] / c;
		total_t += w * 2LL * (i + 1) * p;
		
		B[i] -= c * w;
		todo += B[i];
	}

	int ind = n - 1;

	while (todo > 0) {
		int curr = 0;
		int mx_lvl = 0;

		while (ind >= 0 && curr < c) {
			int take = min(B[ind], c - curr);
			if (take > 0) mx_lvl = max(ind, mx_lvl);

			curr += take;
			B[ind] -= take;

			if (B[ind] == 0) {
				if (ind == 0) break;
				else ind--;
			}
		}

		todo -= curr;
		if (curr > 0) total_t += 2LL * (mx_lvl + 1) * p;
	}

	return total_t <= t;
}

int main() {
	_upgrade;

	#ifndef DEBUG
  freopen("elevator.in", "r", stdin);
  freopen("elevator.out", "w", stdout);
  #endif
	
	cin >> n >> c >> p >> t;

	int end = 1;
	For (i, n) {
		cin >> A[i];
		sum_all += A[i];
		end += A[i];
	}

	int beg = 0;

	while (beg != end - 1) {
		int mid = (beg + end) / 2;
		
		if (check(mid)) beg = mid;
		else end = mid;
	}

	cout << beg << "\n";
}

