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

bool div(const string& s, int target) {
	int sum = 0;
	int cnt = 0;

	For (i, s.size()) {
		sum += s[i];
		if (sum == target) {
			cnt++;
			sum = 0;
		} else if (sum > target) {
			return false;
		} else if (sum != target && i == s.size() - 1) {
			if (cnt >= 1 && sum == 0) {
				continue;
			} else return false;
		}
	}

	return cnt > 1;
}

int main() {
    _upgrade;
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	For (i, s.size()) {
		s[i] -= '0';
	}

	For (i, s.size() * 9) {
		if (div(s, i)) {
			cout << "YES\n";
			return 0;
		}
	}

	cout << "NO\n";
	return 0;
}

