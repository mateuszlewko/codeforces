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

int let_cnt[30];

int main() {
	_upgrade;

	int n;
	cin >> n;

	string s1, s2;
	cin >> s1 >> s2;

	map<pair<char, char>, vector<int>> M;

	For (i, n) {
		char a = s1[i];
		char b = s2[i];

		let_cnt[a - 'a']++;
		let_cnt[b - 'a']++;

		if (a == b) continue;

		M[{a, b}].push_back(i);
 	}

	For (i, 30) {
		if (let_cnt[i] % 2 != 0) {
			cout << "-1\n";
			return 0;
		}
	}

	vector<pii> ans;
	map<pair<char, char>, vector<int>> left;

	for (auto [p, vs] : M) {
		if (vs.size() % 2 != 0) {
			auto [a, b] = p;

			left[{min(a, b), max(a, b)}].push_back(vs.back());
			vs.pop_back();
		}

		assert(vs.size() % 2 == 0);
		for (int i = 0; i < int(vs.size()); i += 2) {
			ans.push_back({vs[i], vs[i + 1]});
		}
	}

	for (auto [_, vs] : left) {

		assert(int(vs.size()) == 2);
		ans.push_back({vs[0], vs[0]});
		ans.push_back({vs[0], vs[1]});
	}

	cout << ans.size() << "\n";

	for (auto [l, p] : ans) {
		cout << l + 1 << " " << p + 1 << "\n";
	}
}

