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

const int M = 10;
ll steps[M][M][M][M];
const ll INF = 1LL<<50;

void init_steps() {
	For (i, M) For (j, M) For (k, M) For (l, M) steps[i][j][k][l] = INF;

	For (x, 10) {
		For (y, 10) {
			For (from, 10) {
				for (int kx = 0; kx <= 11; kx++) {
					for (int ky = 0; ky <= 11; ky++) {
						if (kx + ky == 0) continue;
						
						int to = ((kx * x) + (ky * y) + from) % 10;
						ll cc = kx + ky;
						steps[x][y][from][to] = min(steps[x][y][from][to], cc);
					}
				}
			}
		}
	}
}

ll ans_map[M][M];
bool wrong[M][M];

int main() {
	_upgrade;
	init_steps();

	string s;
	cin >> s;
	
	ll n = s.size();
	int prev = 0;

	for (int ii = 1; ii < n; ii++) {
		int cc = s[ii] - '0';
		For (i, M) {
			for (int j = i; j < M; j++) {
				ll add = steps[i][j][prev][cc];
				ans_map[i][j] += add > 0 ? add - 1 : 0;
				if (add >= INF) wrong[j][i] = wrong[i][j] = true;
			}
		}

		prev = cc;
	}

	For (i, M) {
		For (j, M) {
			ll ans = j >= i ? ans_map[i][j] : ans_map[j][i];
			if (ans >= INF || wrong[i][j]) {
				cout << "-1 ";
			} else {
				cout << ans << " ";
			}
		}
		
		cout << "\n";
	}
}

