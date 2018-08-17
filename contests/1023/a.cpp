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
	int n;
	cin >> n >> n;

	string s1, s2;
	cin >> s1 >> s2;

	int ind = 0;

	For (i, s1.size()) {
		if (ind == s2.size()) {
			if (i == s1.size() - 1 && s1[i] == '*') {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}

			return 0;
		}

		if (s1[i] == '*') {
			if (s1.size() - i - 1 > s2.size() - ind) {
				cout << "NO\n";
				return 0;
			}

			ind = s2.size() - (s1.size() - i) + 1; 
		} else {
			if (s1[i] != s2[ind]) {
				cout << "NO\n";
				return 0;
			}
			ind++;
		}
	}

	if (ind != s2.size())
		cout << "NO\n";
	else cout << "YES\n";
}

