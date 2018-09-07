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

int main() {
    // _upgrade;
	int q;
	cin >> q;

	while (q--) {
		ll a, b, k; 
		scanf("%lld %lld %lld", &a, &b, &k);
		
		a = abs(a);
		b = abs(b);

		if (k == 1 && max(a, b) != 1) {
			puts("-1");
			continue;
		}

		ll res = 0;
		res += min(a, b);
		ll x = max(a - res, b - res);
		k -= res;

		if (k < x) {
			puts("-1");
			continue;
		}

		// ll mv = x - (x % 2);
		// res += mv;
		// k -= mv + (x%2);
		// res += ((k + 1) / 2);

		if (x >= 1) {
			if (x % 2 == 1 && k % 2 == 1) 
				res += k - 1;
			else if (x % 2 == 1 && k % 2 == 0) 
				res += k - 1;
			else if (x % 2 == 0 && k % 2 == 1) 
				res += k - 1;
			else if (x % 2 == 0 && k % 2 == 0) 
				res += k;
			
			printf("%lld\n", res);
		} else {
			res += k - k % 2;
			k = k % 2;
			if (k == 1) {
				printf("%lld\n", res - 1);
			} else printf("%lld\n", res);
		}
		

		// error(mv, k, x);

		// if ((x == 1 && k == 1) || (x == 0 && k == 0) || (x == 0 && k =)) {
		// 	continue;
		// }

		// res += k - (k%2);
		// k -= k - (k%2);

		// if (x == 0 && k == 1) {
		// 	printf("%lld\n", res - 1);
		// } else if ((x == 1 && k == 1) || (x == 0 && k == 0)) {
		// 	printf("%lld\n", res);
		// }

		// error(x, k, res);
		// error("here");
	}
}

