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

const int N = 5 * 100 * 1000 + 10;

int cnt_pattern[N];
int cnt_curr[N];
int A[N];

void print_ans(int beg, int end, int extra, int k) {
	vector<int> ans;

	for (int i = beg - (beg % k); i < beg; i++) {
		extra--;
		ans.push_back(i);
	}

	for (int i = beg; i <= end; i++) {
		int x = A[i];
		if (cnt_pattern[x] == 0 && extra > 0) {
			extra--;
			ans.push_back(i);
		} else if (cnt_pattern[x] > 0) {
			cnt_pattern[x]--;
		}
	}

	cout << ans.size() << "\n";
	for (int x : ans) {
		cout << x + 1 << " ";
	}
}

int main() {
	_upgrade;

	int m, k, n, s;
	cin >> m >> k >> n >> s;

	int extra = m - k * n;

	For (i, m) cin >> A[i];
	int pat_distinct = 0;

	For (i, s) {
		int x;
		cin >> x;
		cnt_pattern[x]++;
		if (cnt_pattern[x] == 1) pat_distinct++;
	}

	int correct = 0;

	// error(len);
	// error(pat_distinct);

	int end = 0;

	For (i, m) {	

		while (end < m && correct < pat_distinct) {
			int x = A[end];
			cnt_curr[x]++;

			if (cnt_curr[x] == cnt_pattern[x]) correct++;
			end++;
		}

		int curr_len = end - i;
		// error(i, correct, curr_len, end);

		if (correct == pat_distinct && i % k <= extra && curr_len - k <= extra - i % k) {
			print_ans(i, end - 1, extra, k);
			return 0;
		}

		int y = A[i];

		// error(j, y, cnt_curr[y]);

		cnt_curr[y]--;
		if (cnt_curr[y] + 1 == cnt_pattern[y]) correct--;
	}

	cout << "-1\n";
}

