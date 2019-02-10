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

const int N = 1000 * 1000 + 10;
int pluses[N];
int minuses[N];

int main() {
    _upgrade;

	int n;
	cin >> n;
	
	For (i, n) {
		string s;
		cin >> s;
		int curr = 0;
		int m = 0;
		For (j, (int)s.size()) {
			if (s[j] == '(') curr++;
			else curr--;

			m = min(m, curr);
		}

		if (m >= 0 && curr >= 0) pluses[curr]++;
		else if (curr < 0 && m >= curr) minuses[-curr]++;
	}

	int res = 0;
	For (i, N) {
		if (i == 0) {
			res += pluses[i] / 2;
		} else {
			int mm = min(minuses[i], pluses[i]);
			res += mm;
		}
	}

	cout << res << "\n";
}

