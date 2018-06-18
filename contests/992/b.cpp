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

vector<ll> factors(ll l, ll r, ll x) {
	vector<ll> res; 

	for (int i = 1; i * i <= x; i++) {
		if (x % i == 0 and i >= l and i <= r) {
			if (i * i == x)
				res.push_back(i);
			else {
				res.push_back(i);
				res.push_back(x / i);
			}
		}
	}

	return res;
}

int main() {
    // _upgrade;
	ll l, r, x, y;
	scanf("%lld %lld %lld %lld", &l, &r, &x, &y);

	 auto a = factors(l, r, x);
	 set<ll> s;
	 for (auto p : factors(l, r, y))
	 	a.push_back(p);

	for (auto x : a)
		s.insert(x);


	 printf("%lld\n", s.size() * 2);
}

