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

const int N = 1000 * 1000 + 10;
int nums[N];
int diffs[N];

ll dp[2][N];

int sign(int x) {
	if (x == 0) return 0;
	return x < 0 ? -1 : 1;
}

int main() {
    // _upgrade;

	int n;
	scanf("%d", &n);

	For (i, n) { 
		scanf("%d", &nums[i]);
		// if (i >= 1 && nums[i] == nums[i - 1]) {
		// 	i--;
		// 	n--;
		// }
	}
	For (i, n - 1) {
		diffs[i] = nums[i + 1] - nums[i];
	}

	dp[1][0] = abs(diffs[0]);

	for (int i = 1; i < n - 1; i++) {
		dp[0][i] = max(dp[0][i - 1], dp[1][i - 1]);
		
		if (sign(diffs[i]) == sign(diffs[i - 1]) || sign(diffs[i]) == 0)
			dp[1][i] = dp[0][i] + abs(diffs[i]); 
		else {
			dp[1][i] = dp[0][i - 1] + abs(diffs[i]);
		}
	}

	ll res = 0;
	For (i, 2) {
		For (j, n - 1)
			res = max(res, dp[i][j]);
	}

	printf("%lld\n", res);
}


