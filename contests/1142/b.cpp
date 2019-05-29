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

vector<int> prefix_function(const vector<int> &s) {
	int n = (int) s.size();
	vector<int> pi(n);

	for (int i=1; i<n; ++i) {
		int j = pi[i-1];
		while (j > 0 && s[i] != s[j])
			j = pi[j-1];
		if (s[i] == s[j])  ++j;
		pi[i] = j;
	}
	return pi;
}

const int N = 2 * 100 * 1000 + 10;
int P[N];
int A[N];

int main() {
    _upgrade;

	int n, m, q;
	cin >> n >> m >> q;

	For (i, n) cin >> P[i];
	For (i, m) cin >> A[i];

	vector<int> norm; 
	For (i, n) norm.push_back(P[i]);
	norm.push_back(-1);
	For (i, m) norm.push_back(A[i]);

	auto p1 = prefix_function(norm);
	cout << "p1: " << p1 << endl;

	vector<int> rev;
	ForD (i, n) rev.push_back(P[i]);
	rev.push_back(-1);
	ForD (i, m) rev.push_back(A[i]);

	auto p2 = prefix_function(rev);
	cout << "p2: " << p2 << endl;

	int offset = n + 1;
	vector<int> correct_pos;

	int k = norm.size();
	For (i, k) {
		int p1_val = p1[i];
		int p2_val = p2[i - p1_val];

		if (p1_val + p2_val == n) {
			correct_pos.push_back(i - offset + 1);
		} 
	}

	cout << "res: " << correct_pos << endl;

	For (i, q) {
		int l, r;
		cin >> l >> r;
		if (correct_pos.empty()) {
			cout << "0";
			continue;
		}

		int pos = upper_bound(correct_pos.begin(), correct_pos.end(), r) - correct_pos.begin();
		if (pos == 0) {
			cout << "0";
			continue;
		}

		pos--;
		if (correct_pos[pos] - n >= l) {
			cout << "1";
		} else cout << "0";
	}
}

