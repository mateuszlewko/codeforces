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

const int N = 100 * 1000 + 10;
int A[N];
map<int, int> cnts;
int diff = 0;

bool check() {
	if (diff == 1) return true;
	if (cnts.size() > 2) return false;

	int s1 = cnts.begin()->first;
	int s1_cnt = cnts.begin()->second;
	
	if (cnts.size() == 1 && s1 == 1) return true;
	else if (cnts.size() == 1) {
		return false;
	}

	int s2 = (++cnts.begin())->first;
	int s2_cnt = (++cnts.begin())->second;

	if (s1 == 1 && s1_cnt == 1) return true;
	if (s2 == s1 + 1 && s2_cnt == 1) return true;

	return false;
}

int main() {
	_upgrade;

	int n;
	cin >> n;

	int best_x = 0;

	For (i, n) {
		int c;
		cin >> c;
		c--;

		int prev_cnt = A[c];
		A[c]++;
		int next_cnt = A[c];

		if (prev_cnt == 0) {
			diff++;
		} else {
			cnts[prev_cnt]--;
			if (cnts[prev_cnt] == 0) cnts.erase(prev_cnt);
		}
		cnts[next_cnt]++;

		// for (auto it : cnts) {
		// 	cout << "on map: ";
		// 	error(it);
		// }

		// cout << "------" << endl;

		if (check()) {
			best_x = i + 1;
		}
	}

	cout << best_x << "\n";
}

