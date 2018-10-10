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
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;
		
		map<string, vector<pair<int, int>>> contests;

		For (i, n) {
			string c;
			int b, e;
			int cnt;
			cin >> c >> b >> e >> cnt;

			For (j, cnt) {
				string s;
				cin >> s;
				contests[s].push_back({b, e});
			}
		}

		vector<string> res;
		for (auto it : contests) {
			auto v = it.second;
			SORT(v);
			For (i, v.size() - 1) {
				if (v[i].second >= v[i + 1].first) {
					res.push_back(it.first);
					break;
				}
			}
		}

		SORT(res);
		cout << res.size() << "\n";
		
		for (auto x : res) {
			cout << x << "\n";
		}
	}
}

