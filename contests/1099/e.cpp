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

vector<vector<int>> dp[4];
vector<vector<vector<int>>> pre[4];
vector<vector<int>> A;
vector<vector<char>> result;

char from_num(int x) {
	if (x == 0) return 'A';
	if (x == 1) return 'T';
	if (x == 2) return 'C';
	if (x == 3) return 'G';
	assert(false);
}

void go(int x, int y, int k) {
	if (x <= 0 || y <= 0) return;
	result[x - 1][y - 1] = from_num(k);

	error(x, y, k, dp[k][x][y]);
    
	auto curr_pre = pre[k][x][y];
	if (curr_pre.empty()) return;

	go(x - 1, y, curr_pre[0]);
	go(x, y - 1, curr_pre[1]);
	go(x - 1, y - 1, curr_pre[2]);
}

int main() {
    _upgrade;
	int n, m;
	cin >> n >> m;

	A.resize(n);

	For (i, n) {
		string s;
		cin >> s;
		for (char c : s) {
			if (c == 'A') A[i].push_back(0);
			if (c == 'T') A[i].push_back(1);
			if (c == 'C') A[i].push_back(2);
			if (c == 'G') A[i].push_back(3);
		}
	}

	For (j, 4) 
	{ 
		dp[j].resize(n + 1);
		pre[j].resize(n + 1);
		result.resize(n + 1);

		For (i, n + 1) {
			dp[j][i].resize(m + 1, 0);
			pre[j][i].resize(m + 1);
			result[i].resize(m + 1, '*');
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			For (k, 4) {
				vector<int> other;
				For (l, 4) if (l != k) other.push_back(l);
				int best_ans = 0;
				vector<int> best_pre;

				do {
					if ((pre[other[0]][i - 1][j].empty() || pre[other[1]][i][j - 1].empty()) 
					|| (pre[other[0]][i - 1][j][0] == pre[other[1]][i][j - 1][1] && pre[other[1]][i][j - 1][1] == other[2]))
					{
						int a = dp[other[0]][i - 1][j] + dp[other[1]][i][j - 1] - dp[other[2]][i - 1][j - 1];
						if (A[i - 1][j - 1] == k) a += 1;

						if (a > best_ans) {
							best_ans = a;
							best_pre = other;
						}
					}

				} while (next_permutation(other.begin(), other.end()));

				dp[k][i][j] = best_ans;
				pre[k][i][j] = best_pre;
			}
		}
	}

	int best = 0;
	int best_k = 0;

	For (i, 4) {
		if (dp[i][n][m] > best) {
			best = dp[i][n][m];
			best_k = i;
		}
		error(dp[i][n][m]);
		for (int x : pre[i][n][m]) {
			cout << x << " ";
		}
		cout << endl;
	}

	error(best, best_k);

	go(n, m, best_k);
	For (i, n) {
		For (j, m) {
			cout << result[i][j];
		}
		cout << "\n";
	}
}

