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
	string s;
	cin >> s;
	int k;
	cin >> k;

	int stars = 0;
	int qs = 0;
	int can_remove_extra = 0;
	For (i, (int)s.size()) {
		char c = s[i];

		if (c == '?') qs++;
		if (c == '*') stars++;
	}

	can_remove_extra = stars + qs;

	int n = (int)s.size();
	int min_n = n - stars - qs - can_remove_extra;
	if (min_n > k) {
		cout << "Impossible\n";
		return 0;
	}

	if (stars == 0 && k > min_n + qs) {
		cout << "Impossible\n";
		return 0;
	}

	int ans = 0;

	if (stars > 0) {
		int needed = k - min_n;
		For (i, (int)s.size()) {
			if (s[i] == '*') {
				while (needed > 0) {
					cout << s[i - 1];
					ans++;
					needed--;
				}
			}

			if (s[i] == '?' || s[i] == '*') continue;

			if (i == (int)s.size() - 1 || (s[i + 1] != '*' && s[i + 1] != '?')) {
				cout << s[i];
				ans++;
			}
		}
	} else {
		int needed = k - min_n;
		For (i, (int)s.size()) {
			if (s[i] == '?' && needed > 0) {
				cout << s[i - 1];
				needed--;
			}

			if (s[i] == '?') continue;

			if (i == (int)s.size() - 1 || (s[i + 1] != '*' && s[i + 1] != '?')) 
				cout << s[i];
		}

	}

}

