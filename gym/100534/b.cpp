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

string gen(const string& s, int a, int b) {
	string res = "";
	res.push_back(s[a - 1]);

	// error(a);

	while (b <= s.size()) {
		res.push_back(s[b - 1]);
		// error(b);
		int a_c = a;
		a = b;
		b += a_c;
	}

	// cout << res << "|\n";
	return res;
}

int main() {
    _upgrade;
	string s;
	cin >> s;

	if (s.size() <= 1) {
		cout << "0\n";
		return 0;
	}

	vector<string> all;
	for (int i = 1; i < s.size(); i++) {
		for (int j = i + 1; j <= s.size(); j++) {
			all.push_back(gen(s, i, j));
		}
	}

	SORT(all);
	int res = min(1, (int)all.size());
	For (i, all.size() - 1) {
		if (all[i] != all[i + 1])
			res++;
	}

	cout << res << "\n";
}

