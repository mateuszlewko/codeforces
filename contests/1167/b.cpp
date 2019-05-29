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

int ask(int i, int j) {
	cout << "? " << i << " " << j << endl;
	int x;
	cin >> x;
	return x;
}

int main() {
	_upgrade;

	int a[] = {4, 8, 15, 16, 23, 42};

	map<int, pii> M;
	set<int> left;
	
	For (i, 6) {
		left.insert(a[i]);

		for (int j = i + 1; j < 6; j++) {
			M[a[i] * a[j]] = {a[i], a[j]};
		}
	} 

	pii ans[] = {M[ask(1, 2)], M[ask(2, 3)], M[ask(4, 5)], M[ask(5, 6)]};

	cout << "! ";

	int dx[] = {0, 2};

	For (i, 2) {
		int x = dx[i];

		if (ans[x].first != ans[x + 1].first && ans[x].first != ans[x + 1].second) {
			cout << ans[x].first << " ";
		} else {
			cout << ans[x].second << " ";
		}

		if (ans[x + 1].first == ans[x].first || ans[x + 1].first == ans[x].second) {
			cout << ans[x + 1].first << " " << ans[x + 1].second << " ";
		} else {
			cout << ans[x + 1].second << " " << ans[x + 1].first << " ";
		}
	}

	// For (i, 4) {
	// 	if ((i != 3 && ans[i].first != ans[i + 1].first && ans[i].first != ans[i + 1].second) ||
	// 	   (i == 3 && (ans[i].first != ans[i - 1].first || ans[i].first != ans[i - 1].second ))) {
	// 		cout << ans[i].first << " ";
	// 		left.erase(ans[i].first);

	// 		if (i == 3) {
	// 			left.erase(ans[i].second);
	// 			cout << ans[i].second << " ";
	// 		}
	// 	} else {
	// 		left.erase(ans[i].second);
	// 		cout << ans[i].second << " ";
	// 		if (i == 3) {
	// 			left.erase(ans[i].first);
	// 			cout << ans[i].first << " ";
	// 		}
	// 	}
	// }

	// cout << (*left.begin());
}

