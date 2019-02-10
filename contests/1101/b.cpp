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

	int first_pos = -1;
	bool was_open = false;

	For (i, (int)s.size()) {
		if (s[i] == '[') was_open = true;

		if (was_open && s[i] == ':') {
			first_pos = i + 1;
			break;
		}
	}

	int last_pos = -1;
	bool was_close = false;

	ForD (i, (int)s.size()) {
		if (s[i] == ']') was_close = true;

		if (was_close && s[i] == ':') {
			last_pos = i;
			break;
		}
	}

	// error(first_pos, last_pos);

	if (first_pos == -1 || last_pos == -1 || last_pos < first_pos) {
		cout << "-1\n";
	} else {
		int extra = 0;
		for (int i = first_pos; i < last_pos; i++) {
			if (s[i] == '|') extra++;
		}

		cout << 4 + extra << "\n";
	}
}

