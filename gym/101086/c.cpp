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
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#pragma endregion 

const int N = 100 * 1000 + 10;

int ans[N];

int main() {
    _upgrade;
	
	int t;
	cin >> t;

	while (t--) {
		int n;
		cin >> n;

		For (i, n) { ans[i] = 1<<30; }

		vector<pair<string, int>> vs;

		For (i, n) {
			string s; 
			cin >> s;
			vs.push_back({s, i});
		}

		SORT(vs);
		// For (i, vs.size()) {
		// 	ord_to_ix[i] = vs[i].second;
		// 	ix_to_ord[vs[i].second] = i;
		// }
		
		unordered_map<ull, int> len;
		unordered_map<ull, vector<int>> cnts;

		for (auto s : vs) {
			ull h = 0;

			For (j, s.first.size() + 1) {
				len[h] = j;

				ans[s.second] = min(ans[s.second], (int)cnts[h].size() + j);
				cnts[h].push_back(s.second);

				h *= 29;
				h += s.first[j] - 'a' + 1;
			}
		}

		for (auto xs : cnts) {
			For (i, xs.second.size()) {
				ans[xs.second[i]] = min(ans[xs.second[i]], len[xs.first] + (int)xs.second.size() - i);
			}
		}

		For (i, n) {
			cout << ans[i] + 1 << " ";
		}

		cout << "\n";
		// for (auto s : vs) {
		// 	For (j, s.first.size()) {
		// 		if (j + 1 > ans[s.second]) break;


		// 		ans[s.second] = min(ans[s.second], (int)cnts[s.first.substr(0, j)].size() + j);
		// 		cnts[s.first.substr(0, j)].push_back(s.second);
		// 	}
		// }
	}
}

