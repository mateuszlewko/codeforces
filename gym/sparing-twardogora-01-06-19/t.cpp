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

// "a", "e", "i", "o", "u" and "y".

bool is_vowel(char c) {
	if (c == 'a' || c == 'i' || c == 'u' || c == 'y') return true;
	return false;
}

bool is_vowel_eo(char c) {
	if (c == 'e' || c == 'o') return true;
	return false;
}

int main() {
	_upgrade;

	int n;
	string s;
	cin >> n >> s;

	string res = "";
	int eo_cnt = 0;

	for (char c : s) {
		if (!is_vowel(c) && !is_vowel_eo(c)) {
			if (eo_cnt == 2) {
				res.push_back(res.back());
			}

			res.push_back(c);
			eo_cnt = 0;
		} else if (is_vowel(c)) {
			if (eo_cnt == 2) {
				res.push_back(res.back());
			}

			if (res.empty() || res.back() != c) 
				res.push_back(c);

			eo_cnt = 0;
		} else {
			if (res.empty() || res.back() == c || !is_vowel_eo(res.back())) {
				eo_cnt++;
				if (eo_cnt == 1) res.push_back(c);
			} else {
				if (eo_cnt == 2) res.push_back(res.back());
				eo_cnt = 1;
				res.push_back(c);
			}
		}
	}

	if (eo_cnt == 2) {
		res.push_back(res.back());
	}

	cout << res << "\n";
}

