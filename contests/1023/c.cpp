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
    // _upgrade;
	int n, k; 
	cin >> n >> k;

	bool not_print[n] = {0};

	string s;
	cin >> s;

	vector<int> opening;
	vector<int> invalid;
	vector<pii> matched;

	For (i, s.size()) {
		if (s[i] == '(') {
			opening.push_back(i);
		} else {
			if (opening.size()) {
				matched.push_back({opening.back(), i});
				opening.pop_back();
			} else {
				invalid.push_back(i);
			}
		}
	}

	while (opening.size()) {
		invalid.push_back(opening.back());
		opening.pop_back();
	}

	int left_rem = n - k;

	for (int ix : invalid) {
		left_rem--;
		not_print[ix] = true;
	}

	For (i, left_rem / 2) {
		not_print[matched[i].first] = true;
		not_print[matched[i].second] = true;
	}

	For (i, s.size()) {
		if (!not_print[i]) {
			cout << s[i];
		}
	}

	cout << "\n";
}

