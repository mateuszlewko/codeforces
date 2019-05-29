#pragma region Template 
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

#pragma endregion 

const int N = 1000010;
int divider[N];
vector<int> divs[N];

void sieve() {
	for (int i = 2; i * i < N; i++) {
		if (divider[i] != 0) continue;

		for (int j = i * i; j < N; j += i) {
			divider[j] = i;
		}
	}
}

void populate_divs(int x) {
	int c = x;
	int prev_div = -1;

	while (true) {
		int d = divider[c];
		if (d != prev_div) {
			divs[d == 0 ? c : d].push_back(x);
		}

		prev_div = d;
		if (d == 0) return;
		c /= d;
	}
}

int ans[N];
bool used[N];

int find_best(int last) {
	int c = last;

	int best = N - 1;

	while (true) {
		int d = divider[c];
		int dd = d == 0 ? c : d;

		while (divs[dd].size() && used[divs[dd].back()]) divs[dd].pop_back();
		if (divs[dd].size()) best = min(best, divs[dd].back());

		if (d == 0) break;
		c /= d;
	}

	return best;
}

void gen_seq() {
	// For (i, 40) cout << divider[i] << " " ;
	// cout << endl;

	for (int i = N - 1; i >= 3; i--) {
		populate_divs(i);
	}

	// cout << "-------" << endl;

	// For (i, 10) {
	// 	For (j, min(10, (int)divs[i].size())) {
	// 		cout << divs[i][(int)divs[i].size() - j - 1] << " ";
	// 	}
	// 	cout << endl;
	// }
	// cout << "-------" << endl;

	vector<int> seq;
	seq.push_back(1);
	seq.push_back(2);

	used[1] = true;
	used[2] = true;

	For (i, N - 5) {
		int b = find_best(seq.back());
		used[b] = true;
		seq.push_back(b);
	}

	For (i, seq.size()) {
		ans[seq[i]] = i + 1;
	}

	// For (i, 50) {
	// 	cout << seq[i] << " ";
	// }
	// cout << endl;
}

int main() {
	_upgrade;

	sieve();
	gen_seq();

	while (true) {
		int n;
		cin >> n;
		if (n == 0) return 0;

		cout << "The number " << n << " appears in location " << ans[n] << ".\n";
	}
}

