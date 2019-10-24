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

const int N = 22;
vector<int> pos_of[N];
const ll INF = 1LL << 60;

ll calc_cost(int k) {
	assert(pos_of[k].size());
	int last_pos = 0;
	ll sum = pos_of[k][0];

	for (int i = 1; i < (int)pos_of[k].size(); i++) {
		int curr_pos = pos_of[k][i];
		sum += curr_pos - last_pos - 1;
		last_pos++;
	} 

	return sum;
}

pair<ll, vector<int>> get_cost(vector<int> v) {
	For (i, N) pos_of[i].clear();

	For (i, v.size()) {
		pos_of[v[i]].push_back(i);
	}

	ll best_cost = INF;
	int best_k = -1;

	for (int i = 1; i < N; i++) {
		if (pos_of[i].empty()) continue;
		ll c = calc_cost(i);

		if (c < best_cost) {
			best_cost = c;
			best_k = i;
		}
	}

	assert(best_k != -1);

	vector<int> next_v;
	for (int x : v) {
		if (x == best_k) continue;
		next_v.push_back(x);
	}

	error(best_k);
	return {best_cost, next_v};
}

int main() {
	_upgrade;

	int n;
	cin >> n;

	vector<int> v;
	v.reserve(n);

	For (i, n) {
		int x;
		cin >> x;
		v.push_back(x);
	}

	ll total_cost = 0;
	while (v.size()) {
		auto [c, next_v] = get_cost(v);
		total_cost += c;
		
		error(c, next_v);
		if (c == 0) {
			break;
		}
		v = next_v;
	}

	cout << total_cost << "\n";
}

