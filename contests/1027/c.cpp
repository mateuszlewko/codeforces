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
typedef long double ld;

#pragma endregion 

const int M = 10 * 1000 + 10;

ld calc(int a, int b) {
	ld area = (ll)a * (ll)b;
	return ((ld)(a + b) / area) * (ld)(a + b);
}

int main() {
    _upgrade;
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		unordered_map<int, int> cnt;
		For (i, n) {
			int a; 
			cin >> a;
			cnt[a]++;
		}

		vector<int> sides; 
		for (auto x : cnt) {
			For (i, x.second / 2) {
				sides.push_back(x.first);
			}
		}

		SORT(sides);
		ld best = -1; 
		pii res;

		For (i, sides.size() - 1) {
			ld c = calc(sides[i], sides[i + 1]);

			if (best < 0 || c < best) {
				best = c; 
				res = {sides[i], sides[i + 1]};
			}
		}

		cout << res.first << " " << res.second << " " << res.first << " " 
		     << res.second << "\n";
	}
}

