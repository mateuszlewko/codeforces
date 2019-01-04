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

const ll M = 998244353;

const int N = 2002;
ll pascal[N + 5][N + 5];

void init_pascal() {
	pascal[0][0] = 1;
	for (int i = 1; i < N; i++) {
		pascal[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			pascal[i][j] = (pascal[i - 1][j - 1] + pascal[i - 1][j]) % M;
		}
	}
}

int main() {
    _upgrade;

	init_pascal();
	ll n, m, k;
	cin >> n >> m >> k;

	ll res = m;
	For (i, k) {
		res = (res * (m - 1)) % M;
	}

	res = (res * pascal[n - 1][n - k - 1]) % M;
	cout << res << "\n";
}

