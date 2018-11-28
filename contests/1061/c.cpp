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

const ll mod = 1000 * 1000 * 1000 + 7;
const int N = 1000 * 1000 + 100;
ll dp[N];

vector<int> factors(int x) {
	vector<int> v;
	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0) {
			v.push_back(i);
			if (i * i != x) {
				v.push_back(x / i);
			}
		}
	}

	SORT(v);
	reverse(v.begin(),v.end());
	return v;
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	dp[0] = 1;

	For (i, n) {
		int x;
		cin >> x;

		auto fs = factors(x);

		for (int f : fs) {
			dp[f] += dp[f - 1];
			dp[f] %= mod;
		}
	}

	ll total = 0;
	For (i, n + 1) {
		total += dp[i];
		total %= mod;
	}

	cout << (total + mod - 1) % mod << "\n";
}

