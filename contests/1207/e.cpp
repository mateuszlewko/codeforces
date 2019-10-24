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

const int m = 1<<14;
vector<int> rand_nums(int n) {
	unordered_set<int> pres;
	while (int(pres.size()) < n) {
		int x = rand() % (1<<12);
		if (pres.count(x) == 0) pres.insert(x);
	}

	vector<int> res;
	for (int x : pres) res.push_back(x);
	return res;
}

vector<int> get_nums() {
	auto ns = rand_nums(100);
	For (i, 100) {
		ns.push_back(ns[i] ^ (1<<13));
	}

	return ns;
}

unordered_map<int, int> get_fst;

bool check(vector<int> &v) {
	get_fst.clear();

	unordered_set<int> all_pairs;
	for (int i = 0; i < 100; i++) {
		for (int j = 100; j < 200; j++) {
			int x = v[i] ^ v[j];
			if (all_pairs.count(x)) {
				// error(v[i], v[j]);
				return false;
			}
			all_pairs.insert(x);
			get_fst[x] = v[i];
		}
	}

	return true;
}

int main() {
	// _upgrade;
	cout << "? ";

	auto nums = get_nums();
	int cc = 0;
	while (cc++ < 100) {
		if (check(nums)) break;
		// error(nums);
		nums = get_nums();
	}

	check(nums);

	For (i, 100) cout << nums[i] << " ";
	cout << endl;

	int x;
	cin >> x;
	
	cout << "? ";
	for (int j = 100; j < 200; j++) {
		cout << (nums[j] ^ x) << " ";
	}
	cout << endl;

	int y;
	cin >> y;
	assert(get_fst.count(y));
	int fs = get_fst[y];

	cout << "! " << (fs ^ x) << endl;
}

