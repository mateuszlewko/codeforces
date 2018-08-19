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

int in_middle(const string& s, int n) {
	int best = 1;
	int last = 0;
	For (i, s.size() - 1) {
		if (s[i + 1] == s[i]) {
			best = max(best, i + 1 - last);
			last = i + 1;
		}
	}

	best = max(best, n - last);	
	return best;
}

int beg_end(const string& s, int n) {
	if (s[0] == s[n - 1]) {
		return 0;
	}

	int at_end = 1;
	for (int i = n - 2; i >= 1; i--) {
		if (s[i] == s[i + 1]) break;
		at_end++;
	}

	int at_beg = 1;
	for (int i = 1; i < n - at_end; i++) {
		if (s[i] == s[i - 1]) break;
		at_beg++;
	}

	return at_beg + at_end;
}

int main() {
    _upgrade;

	string s;
	cin >> s;

	int a = in_middle(s, s.size());
	int b = beg_end(s, s.size());

	cout << max(a, b) << "\n";
}

