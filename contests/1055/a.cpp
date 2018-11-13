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

const int N = 1010;
bool up[N];
bool down[N];

vector<int> G[N];

bool vis[N];
void dfs(int x) {
	if (vis[x]) return;
	vis[x] = true;

	for (int y : G[x]) dfs(y);
}

int main() {
    _upgrade;

	int n;
	int s;
	cin >> n >> s;
	s--;

	For (i, n) cin >> up[i];
	For (i, n) cin >> down[i];

	// cout << "down\n";
	// For (i, n) 
	// 	cout << down[i] << " ";
	// cout << endl;

	For (i, n) {
		if (!up[i]) continue;

		for (int j = i + 1; j < n; j++) {
			if (!up[j]) continue;
			G[i].push_back(j);
		}
	}

	ForD (i, n) {
		if (!down[i]) continue;

		for (int j = i - 1; j >= 0; j--) {
			if (!down[j]) continue;
			// error(i, j);
			G[i].push_back(j);
		}
	}

	dfs(0);
	// For (i, n) cout << vis[i] << " ";
	// cout << endl;
	if (vis[s]) {
		cout << "YES\n";
	} else cout << "NO\n";
}

