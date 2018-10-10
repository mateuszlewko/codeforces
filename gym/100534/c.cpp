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
    _upgrade;

	ll s;
	cin >> s;

	if (s == 2) {
		cout << "Impossible\n";
		return 0;
	}

	ll n = 1;
	while ((n - 2) * (n - 1) + n - 1 < s) n++;

	ll got = (n - 2) * (n - 1) + n - 1;
	vector<pii> extra;

	int i = 2;
	int j = 3;
	// error(got);
	while (got > s) {
		if (j > n) {
			i++;
			j = i + 1;
		}

		if (i >= n) {
			cout << "Impossible\n";
			return 0;
		}

		extra.push_back({i, j});
		got--;
		j++;
	}
	// error(got);

	// cout << s << "\n";

	cout << n << " " << extra.size() + n - 1 << "\n";
	For (k, n - 1) {
		cout << "1 " << k + 2 << "\n";
	}
	for (auto p : extra) {
		cout << p.first << " " << p.second << "\n";
	}
}

