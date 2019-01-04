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

int get_ans(ll x, ll y) {
	cout << "?" << x << " " << y << endl;
	int tmp;
	cin >> tmp;

	if (tmp == 0) {

	}

	return tmp;
}

pair<pair<int, ll>, ll> go(int cmp, ll a, ll b, int i) {
	ll one = 1LL << i;
	ll zero = 0;
	
	int ans = get_ans(zero|a, one|b);

	if (ans == 1) {
		a |= one;
		ans = get_ans(one|a, one|b);
		if (ans == 1) {
			b |= one;
			cmp = 1;
		} else if (cmp == 0) {
			cmp = 0;
			// cmp = -1;
		}
	} else if (ans == 0) {
		cmp = 0;
		a |= one;
	} else if (ans == -1) {
		a |= zero;
		ans = get_ans(one|a, one|b);

		if (ans == 1) {
			cmp = 1;
		} else if (cmp == 0) {
			cmp = 0;
		} else {
			a |= one;
			cmp = -1;
		}
	}

	return {{cmp, a}, b};
} 

int main() {
    // _upgrade;

	int cmp = get_ans(0, 0);

	ll a = 0;
	ll b = 0;

	ForD (i, 30) {
		// a > b
		if (cmp == 1) {
			auto p = go(cmp, a, b, i);
			a = p.first.second;
			b = p.second;
			cmp = p.first.first;
		} else if (cmp == -1) {
			auto p = go(cmp, b, a, i);
			b = p.first.second;
			a = p.second;
			cmp = p.first.first;
		} else {
			
		}
	}
}

