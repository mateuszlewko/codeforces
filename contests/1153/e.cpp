#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < int(n); i++)
#define ForD(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

#ifndef JUST_CPP11
template<typename... Args>
void read(Args&... args)
{
    ((cin >> args), ...);
}

template<typename... Args>
void write(Args... args)
{
    ((cout << args << " "), ...);
}

template<typename... Args>
void writeln(Args... args)
{
    ((cout << args << " "), ...);
	cout << "\n";
}
#endif

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

pii swapp(pii p) {
	return {p.second, p.first};
}

int ask(pii top_left, pii bottom_right) {
	cout << "? " << swapp(top_left) << " " << swapp(bottom_right) << endl;
	int x;
	cin >> x;
	return x;
}

void print_ans(pii a, pii b) {
	cout << "! " << swapp(a) << " " << swapp(b) << endl;
	exit(0);
}

const int N = 1010;
int rows_ans[N];
int col_ans[N];

bool check(int kind, int x, int mid) {
	if (mid == 0) return false;

	if (kind == 0) {
		int col = x;
		return ask({col, 1}, {col, mid}) % 2 == 1;
	} else {
		int row = x;
		return ask({1, row}, {mid, row}) % 2 == 1;
	}
}

int find(int x, int n, int kind) {
	int beg = 0;
	int end = n;

	while (beg != end - 1) {
		int mid = (beg + end) / 2;
		if (check(kind, x, mid)) {
			end = mid;
		} else {
			beg = mid; 
		}
	}

	return end;
}

int main() {
	int n;
	cin >> n;

	vector<int> rows_possible;
	vector<int> col_possible;

	for (int i = 1; i <= n; i++) {
		rows_ans[i] = ask({1, i}, {n, i});
		if (rows_ans[i] % 2 != 0) rows_possible.push_back(i);
	}

	for (int i = 1; i <= n; i++) {
		col_ans[i] = ask({i, 1}, {i, n});
		if (col_ans[i] % 2 != 0) col_possible.push_back(i);
	}
	
	if (rows_possible.empty()) {
		int r = find(col_possible[0], n, 0);
		rows_possible.push_back(r);
	} else if (col_possible.empty()) {
		int c = find(rows_possible[0], n, 1);
		col_possible.push_back(c);
	}

	vector<pii> ans;
	for (int r : rows_possible) {
		for (int c : col_possible) {
			if (ask({c, r}, {c, r}) == 1) {
				ans.push_back({c, r});
			}

			if (ans.size() == 2) {
				print_ans(ans[0], ans[1]);
				return 0;
			}
		}
	}
}

