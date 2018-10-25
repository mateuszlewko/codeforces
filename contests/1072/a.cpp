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
bool mark[N][N];

int main() {
    _upgrade;
	int n, m, k;

	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		for (int j = i * 2; j < n - 2 * i; j++) {
			mark[j][i * 2] = true;
			mark[j][m - i * 2 - 1] = true;
		}

		for (int j = i * 2; j < m - 2 * i; j++) {
			mark[i * 2][j] = true;
			mark[n - i * 2 - 1][j] = true;
		}
	}

	int cnt = 0;
	For (i, n) { 
		For (j, m) { 
			if (mark[i][j]) {
				cnt++;
				// cout << "x";
			} 
			// else cout << ".";
		}
		// cout << "\n";
	}
	cout << cnt << "\n";
}

