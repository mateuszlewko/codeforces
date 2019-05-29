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

const int N = 100 * 1000 + 50;

vector<int> circles[N];
vector<pii> radial;

bool taken[N];
bool vert[N];

int main() {
	_upgrade;

	#ifndef DEBUG
  freopen("subway.in", "r", stdin);
  freopen("subway.out", "w", stdout);
  #endif

	int n, m;
	cin >> n >> m;

	int k = m - n + 1;

	if (k < 1) {
		error("1");
		cout << "No solution\n";
		return 0;
	}

	int v_cnt = 0;
	int max_v = 0;
	int e_cnt = 3 * k;

	For (i, k) {
		For (j, 3) {
			int v = i * 2 + j + 1;
			max_v = max(max_v, v);
			
			if (!vert[v]) {
				vert[v] = true;
				v_cnt++;
			}

			if (j == 2 && i != k - 1) taken[v] = true;
			circles[i].push_back(v);
		}
	}

	error(v_cnt, e_cnt);

	if (v_cnt > n || e_cnt > m) {
		error("2");
		cout << "No solution\n";
		return 0;
	}

	For (j, k) {
		if (v_cnt == n) break;

		For (i, 7) {
			if (v_cnt == n) break;
			circles[j].push_back(++max_v);
			v_cnt++;
			e_cnt++;
		}
	}
	
	error(v_cnt, e_cnt);
	
	if (v_cnt > n || e_cnt > m) {
		error("3");
		cout << "No solution\n";
		return 0;
	}

	For (i, k) {
		if (v_cnt == n) break;

		for (int v : circles[i]) {
			if (v_cnt == n) break;
			if (taken[v]) continue;

			radial.push_back({v, ++max_v});
			v_cnt++;
			e_cnt++;
		}
	}

	error(v_cnt, e_cnt, max_v);

	if (v_cnt != n || e_cnt != m) {
		error("4");
		cout << "No solution\n";
		return 0;
	}

	cout << k << "\n";
	For (i, k) {
		cout << circles[i].size() << " ";
		for (int x : circles[i]) cout << x << " ";
		cout << "\n";
	}

	// error(radial, radial.size());
	cout << radial.size() << "\n";
	for (auto e : radial) {
		cout << e << "\n";
	}
}
