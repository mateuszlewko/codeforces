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

unordered_set<ll> nums;

void gen(ll len, ll a, int pb, int pc, int b, int c) {
	ll num = a;
	while (len--) {
		a *= 10LL;
		if (len == pb) 
			a += b;
		else if (len == pc)
			a += c;
	}

	nums.insert(a);
}


int main() {
    // _upgrade;

	For (i, 19) {
		For (j, 9) {
			for (int k = 0; k <= i + 1; k++) {
				For (l, 10) {
					for (int h = 0; h <= i + 1; h++) {
						For (g, 10) {
							gen(i, j + 1, k, h, l, g);
						}
					}
				}
			}
		}
	}

	// error(nums.size());
	nums.insert(0);

	// For (i, 1000) nums.insert(i + 1) ;

	int q;
	scanf("%d", &q);

	vector<ll>v(nums.begin(), nums.end());

	// For (i, 1000) {
	// 	if (nums.find(i) == nums.end()) {
	// 		printf("%lld\n", i);
	// 	}
	// }

	SORT(v);

	while (q--) {
		ll a, b;
		cin >> a >> b;
		// error(a, b);
		int res = upper_bound(v.begin(), v.end(), b) - lower_bound(v.begin(), v.end(), a);
		printf("%d\n", res);
	}
}

