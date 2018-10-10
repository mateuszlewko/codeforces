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

void dfs(const string& x, unordered_map<string, vector<string>>& deps, unordered_set<string>& vis) {
	if (vis.find(x) != vis.end()) return;
	vis.insert(x);

	for (auto y : deps[x]) {
		dfs(y, deps, vis);
	}
}

int main() {
    _upgrade;
	int t;
	cin >> t;

	while (t--) {
		int total, use;
		cin >> total >> use;

		unordered_map<string, int> str_ix;
		unordered_map<string, vector<string>> deps;

		For (i, total) {
			string name;
			int cnt;
			cin >> name >> cnt;

			str_ix[name] = i;
			For (j, cnt) {
				string d;
				cin >> d;
				deps[name].push_back(d);
			}
		}

		unordered_set<string> vis;
		For (i, use) {
			string s; 
			cin >> s;
			dfs(s, deps, vis);
		}

		vector<pair<int, string>> res;
		for (auto s : vis) {
			res.push_back({str_ix[s], s});
		}

		SORT(res);
		for (auto x : res) {
			cout << x.second << "\n";
		}
	}
}

