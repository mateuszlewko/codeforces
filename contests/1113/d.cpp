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

bool check(const string &init, int n, const string &test) {
	For (i, n / 2) {
		if (test[i] != test[n - i - 1]) {
			return false;
		}
	}

	return init != test;
}

bool check_all(const string &s, int n) {
	string bef;
	For (i, n - 1) {
		bef.push_back(s[i]);
		string aft = s.substr(i + 1, n - i - 1);

		string o1 = bef + aft;
		string o2 = aft + bef;
		if (check(s, n, o1) || check(s, n, o2)) {
			// error(o1, o2);
			return true;
		}
	}

	return false;
}

int main() {
    _upgrade;

	string s;
	cin >> s;
	int n = (int)s.size();

	bool diff = false;
	For (i, n - 1) {
		if (s[i] != s[i+1]) {
			diff = true;
			break;
		}
	}

	if (!diff) {
		cout << "Impossible\n";
		return 0;
	}

	// error("here1");

	if (check_all(s, n)) {
		cout << "1\n";
		// error("here2");
	} else {
		int cnt[30] = {0};
		For (i, n) cnt[s[i] - 'a']++;
		// error("here3");
		vector<int> nonz_cnt;
		For (i, 30) if (cnt[i] > 0) nonz_cnt.push_back(cnt[i]);
		SORT(nonz_cnt);
		// error("here4");

		if (nonz_cnt.size() == 2 && nonz_cnt[0] == 1) {
			cout << "Impossible\n";
			// error("here5");
			return 0;
		} else {
			cout << "2\n";
			// error("here6");
			return 0;
		}
	}
}

