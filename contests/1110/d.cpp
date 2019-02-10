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
int A[N];
int B[N];
int dp[5][N];

int main() {
    _upgrade;

	int n, m;
	cin >> n >> m;
	
	For (i, n) {
		int x;
		cin >> x;
		A[x]++;
	}

	int cnt = 0;
	For (i, m + 1) {
		B[i] = A[i];
		cnt += (A[i] - 1) / 3;
		A[i] -= ((A[i] - 1) / 3) * 3;
		assert(A[i] >= 0);
		assert(A[i] <= 3);
	}

	For (i, m + 1) {
		for (int j = 0; j <= A[i]; j++) {
			int use = A[i] - j;
			int best = 0;
			if (use == 3) {
				best = max(best, dp[0][i + 1] + )
			}
		}
	}

	// for (int i = 1; i <= m; i++) {
	// 	if (A[i] == 1 && )
	// }
}

