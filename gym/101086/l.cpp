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
int sum_pref[N];

bool is_prime[] = {
	0,
	0,
	1,
	1,
	0,
	1,
	0,
	1,
	0,
	0,
	0,
	1,
	0,
	1,
	0,
	0,
	0,
	1,
	0
};

int main() {
    _upgrade;
	int t;

	For (i, N - 1) {
		sum_pref[i + 1] = (is_prime[__builtin_popcount(i + 1)] != 0) + sum_pref[i];
	} 

	cin >> t;

	while (t--) {
		int l, r;
		cin >> l >> r;
		cout << sum_pref[r] - sum_pref[max(0, l - 1)] << "\n";
	}
}

