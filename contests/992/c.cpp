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

const ll MOD = 1000 * 1000 * 1000 + 7;

ll fast_pow(ll n, ll k) {
	if (k == 0) 
		return 1LL;
	
	ll res = fast_pow(n, k >> 1);
	res = (res * res) % MOD;

	if (k & 1) res = (res * n) % MOD;

	return res;
}

int main() {
    // _upgrade;
	ll x, k; 
	scanf("%lld %lld", &x, &k);

	x %= MOD;

	if (x == 0) {
		puts("0");
		return 0;
	}

	ll b = (fast_pow(2, k + 1) * x) % MOD;
	ll a = (fast_pow(2, k) + MOD - 1) % MOD;

	printf("%lld\n", (b - a + MOD) % MOD);
}

