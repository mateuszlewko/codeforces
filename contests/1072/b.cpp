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

const int N = 100 * 1000 + 10;
int nums_a[N];
int nums_b[N];

vector<int> G[N][4];

int main() {
    // _upgrade;
	int n;
	cin >> n;

	For (i, n - 1) cin >> nums_a[i];
	For (i, n - 1) cin >> nums_b[i];

	vector<int> last_valid;
	For (i, 4) last_valid.push_back(i);

	For (i, n - 1) {
		vector<int> new_valid;
		if (last_valid.empty()) {
			cout << "NO\n";
			return 0;
		}

		// for (int v : last_valid) {
		// 	cout << "v: " << v;
		// }
		// cout << "\n---\n";

		for (int v : last_valid) {
			For (j, 4) {
				if ((v & j) == nums_b[i] && (v | j) == nums_a[i]) {
					G[i + 1][j].push_back(v);
					new_valid.push_back(j);
					// error(v, j);
				}
			}
		}
		last_valid = new_valid;
	}

	if (last_valid.empty()) {
		// cout << "empty";
		cout << "NO\n";
		return 0;
	} else {
		cout << "YES\n";
		vector<int> res;
		int curr = 0;
		For(i, 4) {
			if (G[n - 1][i].size()) {
				curr = i;
				res.push_back(i);
				break;
			}
		}

		// For (i, n) {
		// 	For (j, 4) {
		// 		for (auto x : G[i][j]) {
		// 			error(i, j, x);
		// 			cout << "here\n";
		// 		}
		// 	}
		// }


		for (int i = n - 1; i >= 1; i--) {
			curr = G[i][curr][0];
			res.push_back(curr);	
		}

		ForD(i, res.size()) 
			cout << res[i] << " ";
	}

}

