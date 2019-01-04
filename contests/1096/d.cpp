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
ll cost[N];
ll dp[10];

int main() {
    _upgrade;
	
	int n;
	cin >> n;

	string s;
	cin >> s;

	For (i, n) cin >> cost[i];

	string match = "hard";

	For (i, n) {
		char c = s[i];
		int pos = 10;
		
		For (j, match.size()) {
			if (match[j] == c) {
				pos = j;
				break;
			} 
		}

		if (pos == 10) {
			continue;
		}

		if (pos == 0) {
			dp[pos] += cost[i];
		}
		else {
			ll mn = 1LL << 62;
			For (j, pos) mn = min(mn, dp[j]);

			dp[pos] += min(mn, cost[i]); 
		}
	}

	ll ans = 1LL << 62;
	For (i, 4) {
		// error(dp[i], i);
		ans = dp[3];//min(ans, dp[i]);
	}

	cout << ans << "\n";
}

