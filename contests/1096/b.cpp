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

int main() {
    _upgrade;
	ll n;
	cin >> n;

	string s;
	cin >> s;

	ll beg = 1;
	for (int i = 1; i < s.size(); i++) {
		if (s[i] != s[i - 1]) {
			break;
		}
		beg++;
	}

	ll end = 1;
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] != s[i + 1]) {
			break;
		}
		end++;
	}

	// if (beg == n) {
	// 	cout << ((n + 1) * n / 2) % M << "\n";
	// } else if ()
	if (s[0] == s[n - 1]) {
		cout << 1LL * (beg + 1) * (end + 1) % M << "\n";
	} else {
		cout << 1LL * ((beg + 1) + (end + 1) - 1 + M) % M << "\n";
	}
}

