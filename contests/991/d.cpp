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

const int N = 105;
bool busy[N][2];
string lines[2];
int dp[N][4];

int xright[] = {2, 3, 3, 1};
int xleft[] = {3, 1, 2, 3};

int main() {
    _upgrade;
	
	cin >> lines[0] >> lines[1];
	
	int n = (int)lines[0].size();
	For (i, n) 
		For (j, 2) 
			busy[i][j] = (lines[j][i] == 'X');


	For (i, n) {
		For (j, 4) {
			For (k, 4) {
				int b0 = busy[i][0] | (busy[i][1] << 1);
				int b1 = busy[i + 1][0] | (busy[i + 1][1] << 1);
				int b2 = busy[i + 2][0] | (busy[i + 2][1] << 1);

				dp[i + 1][xright[k] | b1] = max(dp[i + 1][xright[k] | b1], dp[i][j]);
				dp[i + 2][b2] = max(dp[i + 2][b2], dp[i][j]);

				if ((b0 & xleft[k]) != 0) continue;

				if ((j & xleft[k]) == 0 && ((b1 & xright[k]) == 0)) {
					// printf("A putting on i: %d, j: %d, type: %d\n", i, j, k);
					dp[i + 1][xright[k] | b1] = max(dp[i + 1][xright[k] | b1], dp[i][j] + 1);
				}
				
				if ((j & xleft[k]) == 0 && ((b1 & xright[k]) == 0) && (b2 == 0)) {
					// printf("B putting on i: %d, j: %d, type: %d\n", i, j, k);
					dp[i + 2][b2] = max(dp[i + 2][b2], dp[i][j] + 1);
				}
			}
		}
	}

	int best = 0;
	For (i, n) {
		For (j, 4) {
			best = max(best, dp[i][j]);
			// printf("%d ", dp[i][j]);
		}

		// puts("");
	}

	cout << best << "\n";
}

