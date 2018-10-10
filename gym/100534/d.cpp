#pragma region Template 
#include <bits/stdc++.h> 

using namespace std;

#define For(i, n) for (int i = 0; i < (n); i++)
#define ForD(i, n) for (int i = (n) - 1; i >= 0; i--)
#define SORT(x) sort(begin(x), end(x))
#define REP(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))

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

#define _upgrade do { ios::sync_with_stdio(0); cin.tie(0); } while (0)

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

const int N = 1010;
bool coins[N][N];

const ll MOD = 1000000007;
ll res[2][N][N];
ll ways[2][N][N];
int n;

void calc_right_down() {
	ways[0][0][0] = 1;

	For (i, n) {
		For (j, n) {
			ll up = i > 0 ? res[0][i - 1][j] : 0;
			ll left = j > 0 ? res[0][i][j - 1] : 0;
			res[0][i][j] = max(up, left) + coins[i][j];

			ll wup = i > 0 ? ways[0][i - 1][j] : 0;
			ll wleft = j > 0 ? ways[0][i][j - 1] : 0;

			if (up == left) {
				ways[0][i][j] += (wup + wleft) % MOD;
			} else if (up > left) {
				ways[0][i][j] += wup;
			} else {
				ways[0][i][j] += wleft;
			}
			ways[0][i][j] %= MOD;
		}
	}
}

void calc_left_up() {
	ways[1][n - 1][n - 1] = 1;

	ForD (i, n) {
		ForD (j, n) {
			ll up = i < n - 1 ? res[1][i + 1][j] : 0;
			ll left = j < n - 1 ? res[1][i][j + 1] : 0;
			res[1][i][j] = max(up, left) + coins[i][j];

			ll wup = i < n - 1 ? ways[1][i + 1][j] : 0;
			ll wleft = j < n - 1 ? ways[1][i][j + 1] : 0;

			if (up == left ) {
				ways[1][i][j] += (wup + wleft) % MOD;
			} else if (up > left) {
				ways[1][i][j] += wup;
			} else {
				ways[1][i][j] += wleft;
			}
			ways[1][i][j] %= MOD;
		}
	}
}

int main() {
    _upgrade;
	cin >> n;

	For (i, n) {
		string s;
		cin >> s;

		For (j, s.size()) {
			coins[i][j] = s[j] == 'C';
		}
	}

	// int temp;
	// cin >> temp;
	calc_right_down();
	calc_left_up();

	// For (z, 2) {
	// 	For (i, n) {
	// 		For (j, n) {
	// 			cout << res[z][i][j] << " ";
	// 		}

	// 		cout << "\n";
	// 	}
	// 	cout << "\n";
	// 	For (i, n) {
	// 		For (j, n) {
	// 			cout << ways[z][i][j] << " ";
	// 		}

	// 		cout << "\n";
	// 	}
	// 	cout << "\n";
	// }
	// cout << "\n";


	int q;
	cin >> q;
	while (q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;

		ll horiz[n + 10];
		ll horiz_ways[n + 10];
		ll vert[n + 10];
		ll vert_ways[n + 10];
		For (i, n + 10) horiz[i] = vert[i] = 0;
		For (i, n + 10) horiz_ways[i] = vert_ways[i] = 0;

		if (r1 > 0) {
			for (int i = n - 1; i > c2; i--) {
				// if (ways[0][r1 - 1][i] == 0 || ways[1][r1][i] == 0) continue;

				horiz[i] = res[0][r1 - 1][i] + res[1][r1][i];
				horiz_ways[i] = (ways[0][r1 - 1][i] * ways[1][r1][i]) % MOD;

				// if (ways[0][r1 - 1][i] == 1 || ways[1][r1][i] == 1) 
				// 	horiz_ways[i] = (horiz_ways[i] - 1 + MOD) % MOD;
				// horiz_ways[i] += ()
			}
		}

		if (c1 > 0) {
			for (int i = n - 1; i > r2; i--) {
				// if (ways[0][i][c1 - 1] == 0 || ways[1][i][c1] == 0) continue;

				vert[i] = res[0][i][c1 - 1] + res[1][i][c1];
				vert_ways[i] = (ways[0][i][c1 - 1] * ways[1][i][c1]) % MOD;

				// if (ways[0][i][c1 - 1] == 1 || ways[1][i][c1] == 1)
				// 	vert_ways[i] = (vert_ways[i] - 1 + MOD) % MOD;
			}
		}

		// For (i, n) {
		// 	cout << vert[i] << " ";
		// }
		// cout << "\n";
		// For (i, n) {
		// 	cout << vert_ways[i] << " ";
		// }
		// cout << "\n";
		// For (i, n) {
		// 	cout << horiz[i] << " ";
		// }
		// cout << "\n";
		// For (i, n) {
		// 	cout << horiz_ways[i] << " ";
		// }
		// cout << "\n";
		// cout << "\n";

		ll best = 0;
		ll best_ways = 0;

		For (i, n) {
			if (horiz[i] > best) {
				best = horiz[i];
				best_ways = horiz_ways[i];
			} else if (horiz_ways[i] > 0 && horiz[i] == best) {
				// error(best, best_ways, horiz_ways[i]);
				best_ways += horiz_ways[i];
				// if (i > c2 && horiz[i - 1] == horiz[i]) {
				// 	best_ways += coins[r1 - 1][i];
				// }
				best_ways %= MOD;
			}
		}

		For (i, n) {
			if (vert[i] > best) {
				best = vert[i];
				best_ways = vert_ways[i];
			} else if (vert_ways[i] > 0 && vert[i] == best) {
				// error(best, best_ways, vert_ways[i]);
				best_ways += vert_ways[i];
				// if (i > r2 && vert[i - 1] == vert[i]) {
				// 	best_ways += coins[i][c1 - 1];
				// }
				best_ways %= MOD;
			}
		}

		cout << best << " " << best_ways % MOD << "\n";
	}
}

