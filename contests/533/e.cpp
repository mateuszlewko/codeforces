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

int cnt[2][50];

int main() {
    _upgrade;
	int n;
	string s, t;
	cin >> n >> s >> t;

	if (s.size() != t.size()) {
		cout << "0\n";
		return 0;
	}

	int diffs = 0;
	For (i, s.size()) {
		if (s[i] != t[i]) diffs++;
		
		cnt[0][s[i] - 'a']++;
		cnt[1][t[i] - 'a']++;
	}

	int cntDiff1 = 0;
	int cntDiff2 = 0;
	For (i, 30) {
		if (cnt[0][i] < cnt[1][i]) {
			cntDiff1 += cnt[1][i] - cnt[0][i];
		} else if (cnt[0][i] > cnt[1][i]) {
			cntDiff2 += cnt[0][i] - cnt[1][i];
		}
	}

	if (diffs > 2 || (diffs == 2 && max(cntDiff1, cntDiff2) > 1)) {
		cout << "0\n";
		return 0;
	}
	else if (diffs == 2) {
		cout << "1\n";
	} else if (diffs == 1) {
		cout << "2\n";
	} else {
		return 11;
		// s += "$";
		// ll res = 0;
		// For (i, 26) {
		// 	for (char c : s) {
		// 		if (c != ('a' + i)) res++;
		// 	}
		// }

		// cout << res << "\n";
	}
}

