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

const int N = 100 * 1000 + 10;
const int M = 200;

ll dp[N][M + 20][2];
int nums[N];

const ll mod = 998244353;

int main() {
    _upgrade;

	int n;
	cin >> n;

	For (i, n) {
		int x;
		cin >> x;

		if (i == 0) {
			if (x == -1) {
				for (int j = 1; j <= M; j++) dp[i][j][1] = 1;
			} else dp[i][x][1] = 1;
		} else {
			ll sum_pref[M + 20][2];
			sum_pref[0][0] = 0;
			sum_pref[0][1] = 0;
			
			for (int j = 1; j <= M; j++) {
				For (k, 2) sum_pref[j][k] = (sum_pref[j - 1][k] + dp[i - 1][j][k]) % mod;
			}

			for (int j = 1; j <= M; j++) {
				if (x != -1) j = x;

				dp[i][j][1] = (sum_pref[j - 1][1] + sum_pref[j - 1][0]) % mod;
				dp[i][j][0] = (dp[i - 1][j][1] + sum_pref[M][0] - sum_pref[j - 1][0] + mod) % mod;

				if (x != -1) break;	
			}
		}
	}

	ll res = 0;
	for (int i = 1; i <= M; i++) {
		res = (res + dp[n - 1][i][0]) % mod;
	}

	cout << res << "\n";
}

