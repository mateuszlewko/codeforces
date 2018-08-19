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


const int N = 150 * 1000 + 10;
int nums[2][N];
int dp[2][N];

vector<int> factors(int x) {
	vector<int> res;

	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			if (i != 1)
				res.push_back(i);
			if (x / i != 1)
				res.push_back(x / i);
		}
	}

	return res;
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	For (i, n) For (j, 2) cin >> nums[j][i];

	auto vs = factors(nums[0][0]);
	for (auto x : factors(nums[1][0])) {
		vs.push_back(x);
	}

	SORT(vs);
	int any = -1;
	for (int x : vs) {
		bool all = true; 

		for (int i = 1; i < n; i++) {
			if (nums[0][i] % x != 0 && nums[1][i] % x != 0) {
				all = false;
				break;
			}
		}
		 
		if (all) {
			any = x;
			break;
		}
	}

	cout << any << "\n";
	// For (i, 2) dp[i][0] = nums[i][0];

	// for (int i = 1; i < n; i++) {
	// 	For (j, 2) {
	// 		int a = __gcd(dp[0][i - 1], nums[j][i]);
	// 		int b = __gcd(dp[1][i - 1], nums[j][i]);
	// 		dp[j][i] = max(a, b);
	// 	}
	// }

	// int res = max(dp[0][n - 1], dp[1][n - 1]);
	// if (res == 1)
	// 	cout << "-1\n";
	// else cout << res << "\n";
}

