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

const int N = 110;
int dp[N * N][N];
unordered_set<int> used[N * N][N];

int nums[N];
int num_cnt[N * N];

int main() {
    _upgrade;

	int n;
	cin >> n;

	int total_sum = 0;
	For (i, n) { 
		cin >> nums[i];
		total_sum += nums[i];

		num_cnt[nums[i]]++;
		dp[nums[i]][1] = 1;
		used[nums[i]][1].insert(nums[i]);
	}

	For (i, n) {
		int c = nums[i];
		ForD (j, total_sum - c + 1) {
			ForD (k, n) {
				if (dp[j][k] == 0) continue;
				// error(c, j, k, dp[j][k]);

				if (dp[j + c][k + 1] == 0 || used[j + c][k + 1].find(c) == used[j + c][k + 1].end()) {
					// if (dp[j + c][k + 1] > 0) {
						// error(c, j, k, dp[j+c][k+1], used[j+c][k+1]);
					// }

					dp[j + c][k + 1]++;
				}
				
				used[j + c][k + 1].insert(c);
				// error(dp[j+c][k+1]);
			}
		}
	}

	// For (i, 25) {
	// 	For (j, 6) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	int best = 1;

	for (int i = 1; i < N; i++) {
		if (num_cnt[i] == 0) continue;

		for (int j = 1; j <= num_cnt[i]; j++) {
			int curr = 0;
			if (dp[i * j][j] == 1) curr += j;

			if (dp[total_sum - i * j][n - j] == 1 &&
			    (total_sum - i * j) % (n - j) == 0 &&
				 num_cnt[(total_sum - i * j) / (n - j)] == (n-j)) {
				curr += n - j;
			}

			// error(i, j);
			best = max(best, curr);
		}
	}

	cout << best << "\n";
}

