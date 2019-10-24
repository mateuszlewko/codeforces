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

pii cheapest_pizza[4000];
int how_many_like[4000];

const int INF = 1<<30;

int main() {
	_upgrade;

	int n, m;
	cin >> n >> m;

	For (i, 2000) cheapest_pizza[i] = {INF, -1};

	For (i, n) {
		int f;
		cin >> f;

		int all_mask = 0;
		For (j, f) {
			int x;
			cin >> x;
			x--;
			
			all_mask |= (1 << x);
		}

		For (j, (1<<9)) {
			if ((j & all_mask) == all_mask) how_many_like[j]++;
		}
	}

	For (i, m) {
		int c;
		int r;
		cin >> c >> r;

		int all_mask = 0;
		For (j, r) {
			int x;
			cin >> x;

			x--;
			all_mask |= (1 << x);
		}

		if (cheapest_pizza[all_mask].first > c) {
			cheapest_pizza[all_mask] = {c, i + 1};
		}
	}

	pii best_ix = {1, 2};
	int best_cost = 1<<30;
	int num_of_p = 0;

	For (i, (1 << 9)) {
		if (cheapest_pizza[i].first >= INF) continue;

		for (int j = i + 1; j < (1<<9); j++) {
			if (cheapest_pizza[j].first >= INF) continue;

			int all_mask = (i | j);
			int p = how_many_like[all_mask];
			int c = cheapest_pizza[i].first + cheapest_pizza[j].first;

			if (p > num_of_p || (p == num_of_p && best_cost > c)) {
				num_of_p = p;
				best_cost = c;
				best_ix = {cheapest_pizza[i].second, cheapest_pizza[j].second};
			}
		}
	}

	cout << best_ix << "\n";
}

