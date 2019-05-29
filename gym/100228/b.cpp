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

const int N = 610;
int dp[2][N];
string A[N];

int main() {
	_upgrade;

	while (true) {
		int n, l, m;
		cin >> n >> l >> m;

		if (n == 0 && l == 0 && m == 0) return 0;
		
		map<string, int> M;
		int len = 0;

		For (i, m) {
			string s;
			cin >> s;

			len = s.size();

			if (M.count(s) == 0) {
				int ix = M.size();
				M[s] = ix;
			}
		}

		m = M.size();

		if (l < len) {
			cout << "0\n";
			continue;
		}

		For (i, m) {
			dp[len % 2][i] = 1;
		}

		for (int i = len + 1; i <= l; i++) {
			For (j, m) dp[i % 2][j] = 0;
			
			for (auto s_id : M) {
				int id = s_id.second;
				string pref = s_id.first;
				int got = dp[(i + 1) % 2][id]; 

				// error(got, s_id);
				
				For (j, n) {
					string s = pref.substr(1, int(pref.size()) - 1);
					s.push_back('A' + j);

					// error(s);

					auto it = M.find(s);
					if (it == M.end()) continue;

					int to = it->second;
					dp[i % 2][to] += got;
				}
			} 
		}

		int res = 0;
		For (i, m) {
			res += dp[l % 2][i];
		}

		cout << res << "\n";
	}
	
}

