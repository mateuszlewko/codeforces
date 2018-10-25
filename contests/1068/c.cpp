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

const int N = 110;
vector<int> columns[N];

bool vis[N];

int main() {
    _upgrade;

	int n, m;
	cin >> n >> m;

	int last_col = 1;

	For (i, m) {
		int a, b;
		cin >> a >> b;
		int c = a;
		a = min(a, b);
		b = max(c, b);

		// error(a, b, last_col);

		columns[a].push_back(last_col);
		columns[b].push_back(last_col);
		vis[a] = vis[b] = true;
		last_col++;
	}

	for (int i = 1; i <= n; i++) {
		if (!vis[i]) {
			columns[i].push_back(last_col++);
		}
	}

	int total = 0;
	for (int i = 1; i <= n; i++) {
		cout << columns[i].size() << "\n";
		total += columns[i].size();

		if (columns[i].size() == 0) {
			assert(false);
		}

		for (int c : columns[i]) {
			cout << i << " " << c << "\n";
		}
	}

	if (total > 5000) assert(false);
}

