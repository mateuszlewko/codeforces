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
typedef unsigned int uint;

const ll INF = 1LL<<60;
vector<pii> teas[2];

const int N = 1010;

uint pre[N][N][2][2];
// dp[i][j][0/1][1/2];
ll dp[N][N][2][2];

pair<int, pair<pii, pii>> get_state(uint s) {
	int t = (s & (1u<<31)) >> 31;
	int used = (s & (1u<<30)) >> 30;

	uint first10 = 0x000003ffu;

	int num = (s & first10);
	s >>= 10;
	int j = (s & first10);
	s >>= 10;
	int i = (s & first10);

	return {num, {{i, j}, {t, used}}};
}

uint set_state(pair<int, pair<pii, pii>> s) {
	uint res = 0;
	res |= (uint(s.second.second.first << 31));
	res |= (uint(s.second.second.second << 30));

	res |= (uint(s.second.first.first << 20));
	res |= (uint(s.second.first.second << 10));
	res |= uint(s.first);

	return res;
}

inline auto get_pre_state(const pair<pii, pii> &best_state) {
	return get_state(pre[best_state.first.first][best_state.first.second][best_state.second.first][best_state.second.second]);
}

int tea_type[N];

int main() {

	// uint s = set_state({65, {{6, 2}, {1, 2}}});
	// cout << (get_state(s)) << endl;
	// _upgrade;

	#ifndef DEBUG
  freopen("tea.in", "r", stdin);
  freopen("tea.out", "w", stdout);
  #endif

	int k, n;
	cin >> k >> n;

	// if (k == 44 && n == 70) {
	// 	For (i, n) {
	// 		int c, t;
	// 		cin >> c >> t;
	// 		cout << c << "," << t << ";"; 

	// 		if (i % 10 == 0) cout << "\n";
	// 	}

	// 	return 0;
	// }

	For (i, n) {
		int c, t;
		cin >> c >> t;
		teas[t].push_back({c, i + 1});
		tea_type[i + 1] = t;
	}

	int third = k / 3;

	if (n < k || (int)min(teas[0].size(), teas[1].size()) < third) {
		cout << "Impossible";
		return 0;
	}

	For (i, 2) {
		teas[i].push_back({1LL<<30, n + 2 + i});
		SORT(teas[i]);
	}
	
	For (i, N) For (j, N) For (kk, 2) For (l, 2) {
		dp[i][j][kk][l] = INF;
		// pre[i][j][kk][l] = set_state({0, {{0, 0}, {0, 0}}});
	}

	if (teas[0].empty()) {
		For (i, k) cout << teas[1][i].second << " ";
		return 0;
	}

	if (teas[1].empty()) {
		For (i, k) cout << teas[0][i].second << " ";
		return 0;
	}

	// For (i, 2) {
	// 	dp[0][0][i][0] = 0;
	// 	pre[0][0][i][0] = {-1, {{-1, -1}, {-1, -1}}};
	// }

	dp[1][0][0][0] = teas[0][0].first * k;
	dp[0][1][1][0] = teas[1][0].first * k;

	pre[1][0][0][0] = set_state({teas[0][0].second, {{0, 0}, {0, 0}}});
	pre[0][1][1][0] = set_state({teas[1][0].second, {{0, 0}, {0, 0}}});

	For (i, teas[0].size()) {
		For (j, teas[1].size()) {
			if (i + j + 1 > k) break;

			For (t, 2) {
				For (used, 2) {
					ll curr_val = dp[i][j][t][used];
					if (curr_val >= INF) continue;

					For (next, 2) {
						if (used == 1 && next == t) continue;

						int used_num = teas[next][next == 0 ? i : j].second;

						int ni = next == 0 ? i + 1 : i;
						int nj = next == 1 ? j + 1 : j;

						int n_used = next == t ? 1 : 0;
						
						ll p_val = dp[ni][nj][next][n_used];
						ll next_val = curr_val;
						next_val += teas[next][next == 0 ? i : j].first * (k - (i + j));

						if (p_val > next_val) {
							dp[ni][nj][next][n_used] = next_val;
							// if (k == 44 && ni == 6 && nj == 3 && next == 1 && n_used == 0) {
							// 	printf("(%d, %d, %d, %d), %lld | %d -> (%d, %d, %d, %d) = %lld\n", i, j, t, used, curr_val, used_num, ni, nj, next, n_used, next_val);
							// }

							pre[ni][nj][next][n_used] = set_state({used_num, {{i, j}, {t, used}}});
							// error(pre[ni][nj][next][n_used]);
						}
					}
				}
			}
		}
	}

	ll best = INF;
	pair<pii, pii> best_state;

	For (i, k + 1) {
		For (t, 2) {
			For (used, 2) {
				if (dp[i][k - i][t][used] < best) {
					best = dp[i][k - i][t][used];
					best_state = {{i, k - i}, {t, used}};
				}
			}
		}
	}

	// error(best_state, best);

	if (best >= INF) {
		cout << "Impossible";
		return 0;
	}

	vector<int> ans;
	cout << best << "\n";
	// while (get_pre_state(best_state).first != 0) {
	// 	ans.push_back(get_pre_state(best_state).first);
	// 	best_state = get_pre_state(best_state).second;
	// 	// if (k == 44 && n == 70) cout << get_pre_state(best_state).first << "," << (best_state) << "\n";
	// 	// if (best_state.first.first == 0) break;
	// }

	// reverse(ans.begin(), ans.end());
	// for (int x : ans) {
	// 	// if (k == 44 && n == 70) {
	// 	// 	cout << tea_type[x] << "," << x << " "; 
	// 	// }
	// 	// else 
	// 	cout << x << " ";
	// }
}

/*

(0, 1, 0, 0), 0 -> (1, 1, 0, 0) = 5
(0, 1, 0, 1), 2 -> (0, 2, 1, 1) = 11
(1, 0, 0, 0), 1 -> (2, 0, 0, 1) = 5
(1, 0, 0, 1), 3 -> (1, 1, 1, 0) = 7
(1, 1, 0, 0), 1 -> (2, 1, 0, 1) = 11
(1, 1, 0, 1), 2 -> (1, 2, 1, 0) = 17
(1, 1, 0, 0), 1 -> (2, 1, 0, 0) = 13
(1, 1, 0, 1), 2 -> (1, 2, 1, 1) = 19
best_state = 2 1 0 1
best = 11
2 % 


*/