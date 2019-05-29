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

bool check(const string &s, int mx) {
	if (mx == 0) return false;

	int v1 = 0;
	int v2 = 0;

	for (char c : s) {
		if (c == '(') {
			if (v1 == mx) {
				v2++;
				if (v2 > mx) return false;
			}
			else v1++;
		} else {
			if (v1 > v2) v1--;
			else v2--;
		}
	}

	assert(v1 == 0);
	assert(v2 == 0);
	return true;
}

string make_ans(const string &s, int mx) {
	string ans = "";

	int v1 = 0;
	int v2 = 0;

	for (char c : s) {
		if (c == '(') {
			if (v1 == mx) {
				v2++;
				ans.push_back('1');
			}
			else {
				v1++;
				ans.push_back('0');
			}
		} else {
			if (v1 > v2) {
				v1--;
				ans.push_back('0');
			}
			else {
				v2--;
				ans.push_back('1');
			}
		}
	}

	assert(v1 == 0);
	assert(v2 == 0);

	return ans;
}

string solve(const string &s) {
	int beg = 0;
	int end = int(s.size()) + 1;

	while (beg != end - 1) {
		int mid = (beg + end) / 2;
		if (check(s, mid)) {
			end = mid;
		} else beg = mid;
	}

	return make_ans(s, end);
}

int main() {
	_upgrade;

	int n;
	cin >> n;

	string s;
	cin >> s;

	cout << solve(s);
}

