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

typedef pair<pii, int> tri;

const int N = 100 * 1000 + 10;
vector<tri> end_at[N];
vector<tri> start_at[N];

const ll inf = 1LL<<61;

ll dp[N][210];

int main() {
    _upgrade;

	int n, m, k;
	cin >> n >> m >> k;

	For (i, k) {
		int s, t, d, w;
		cin >> s >> t >> d >> w;
		tri inter = {{w, d}, i};

		end_at[t].push_back(inter);
		start_at[s].push_back(inter);
	}

	// For (i, N) For (j, 202) dp[i][j] = inf;

	set<tri> curr;

	// For (i, 202) dp[n + 1][i] = 0;

	for (int i = n; i >= 0; i--) {
		for (auto x : end_at[i]) {
			// error(x.second);
			curr.insert(x);
		}

		For (j, m + 1) {

			if (curr.size()) {
				auto greedy = *curr.rbegin();
				if (j == 0) dp[i][j] = dp[greedy.first.second + 1][j] + greedy.first.first;
				else {
					dp[i][j] = min(dp[i + 1][j - 1], dp[greedy.first.second + 1][j] + greedy.first.first);
				}
			} else {
				if (j == 0) dp[i][j] = dp[i + 1][j];
				else {
					dp[i][j] = min(dp[i + 1][j - 1], dp[i + 1][j]);
					// dp[i][j + 1] = min(dp[i][j + 1], dp[i + 1][j]);
				}
			}

			// error(i, j, dp[i][j]);
		}

		for (auto x : start_at[i]) {
			auto it = curr.find(x);
			if (it != curr.end()) curr.erase(it);
		}
	}

	ll best = inf;
	For (i, m + 1) {
		best = min(best, dp[0][i]);
		// error(i, dp[0][i]);
	}

	cout << best << "\n";
}

