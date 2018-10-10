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

bool check(string s) {
	int cnt[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	for (char c : s) if (c >= 'A' && c <= 'E') cnt[c - 'A']++;

	// cout << "s: " << s << "\n";
	For (i, 5) if (cnt[i] == 0) return false;

	return true;
}

bool solve(const string& s) {
	For (i, s.size()) {
		for (int j = i + 1; j < s.size(); j++) {
			string sc = s;
			sc[i] = sc[i] + (sc[j] - 'A' + 1);
			// error(i, sc);
			sc[j] = '$';
			if (check(sc)) {
				return true;
			}
		}

		for (int j = 0; j < s.size(); j++) {
			for (int k = i + 1; k < s.size(); k++) {
				for (int l = j + 1; l < s.size(); l++) {
					if (i != j && k != l && i != l && j != k) {
						string sc = s;
						sc[i] = sc[i] + sc[k] - 'A' + 1;
						sc[k] = '$';
						sc[j] = sc[j] + sc[l] - 'A' + 1;
						sc[l] = '$';

						if (check(sc)) return true;
					}
				}
			}
		}
	}

	return false;
}

int main() {
    _upgrade;
	int t;
	cin >> t;

	while (t--) {
		string s;
		cin >> s;
		if (solve(s)) cout << "YES\n"; 
		else cout << "NO\n";
	}
}

