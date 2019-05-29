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
typedef long double ld;

#pragma endregion 

const int N = 20;
pair<ld, ld> A[N];
vector<int> G[N];

ld dist2(int i, int j) {
	ld x = (A[i].first - A[j].first);
	ld y = (A[i].second - A[j].second);
	return x * x + y * y;
}

int best;
int col[N];
int n;

inline int get_free_col(int x) {
	bitset<6> avail = 0xFFFF;
	for (int y : G[x]) avail[col[y]] = 0;
	for (int i = 1; i <= 4; i++) if (avail[i] == 1) return i;
	return 5;
}

void go(int ix, int curr_used) {
	// error(ix, curr_used);
	// For (i, n) cout << col[i + 1] << " ";
	// cout << endl << "-----" << endl;

	if (ix == n) {
		int fc = get_free_col(n);
		int res = max(fc, curr_used);
		best = min(best, res);
		// error(best, fc, res);
		return;
	}

	bitset<6> avail = 0xFFFF;
	for (int y : G[ix]) avail[col[y]] = 0;

	for (int i = 1; i <= 5; i++) {
		if (avail[i] == 1) {
			int curr_used_next = max(curr_used, i);
			col[ix] = i;
			go(ix + 1, curr_used_next);
			// col[ix] = 0;
		}
	}
}

int cs = 1;
void print_ans(int x) {
	cout << "The towers in case " << cs << " can be covered in " << x << " frequencies." << "\n";
	cs++;
}

int main() {
	_upgrade;

	int cs = 1;
	while (true) {
		cin >> n;

		if (n == 0) return 0;

		For (i, n) {
			cin >> A[i].first >> A[i].second;
		}		

		For (i, n + 1) G[i].clear();

		For (i, n) {
			for (int j = i + 1; j < n; j++) {
				if (dist2(i, j) <= (ld)400.0) {
					G[i + 1].push_back(j + 1);
					G[j + 1].push_back(i + 1);
				}
			}
		}

		if (n == 1) {
			print_ans(1);
			continue;
		}

		best = 5;
		col[1] = 1;
		go(2, 1);

		print_ans(best);
	}
}

