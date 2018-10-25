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

int sum(ll x) {
	ll res = 0;
	while (x) {
		res += x % 10LL;
		x /= 10LL;
	}

	return (int)res;
}

int solve(ll n) {
	ll max9 = 9;

	if (n < max9) { 
		return n;
	} else {
		while (max9 * 10LL + 9 <= n) max9 = max9 * 10 + 9;
		int s9 = sum(max9);
		int sN9 = sum(n - max9);
		// error(s9, sN9);
		return s9 + sN9;
	}
}

// int brut(ll n) {
// 	int best = 0; 

// 	For (i, (int)n) {
// 		best = max(best, sum(i) + sum(n - i));	
// 	}

// 	return best;
// }

// void test(int X) {
// 	For (i, X) {
// 		int s = solve(i);
// 		int b = brut(i);
// 		if (s != b) {
// 			cout << "ERROR\n";
// 			error(i, s, b);
// 			cout << " ---\n";
// 			return;
// 		}
// 	}
// }

int main() {
    _upgrade;

	// test(100000);

	ll n;
	cin >> n;
	cout << solve(n);
}

