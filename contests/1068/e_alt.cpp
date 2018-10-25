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
int deg[N];
vector<int> G[N];

int center = -1;
vector<int> verts;
void find_center(int x, int k, int pre) {
	verts.push_back(x);

	if ((int)verts.size() == 2 * k + 1) {
		center = verts[k];
		return;
	}
	
	for (int y : G[x]) {
		if (y != pre) find_center(y, k, x);
	}

	verts.pop_back();
}

bool is_hedge(int x, int k, int pre) {
	if (k == 0) {
		return G[x].size() == 1 && G[x][0] == pre;
	}

	bool all = true;
	for (int y : G[x]) {
		if (y != pre) all &= is_hedge(y, k - 1, x);
	}

	// if (G[x].size() <= 3) error(x, G[x].size());
	return all && ((pre == -1 && G[x].size() >= 3) || G[x].size() > 3);
}

int main() {
    _upgrade;
	int n;
	int k;

	cin >> n >> k;

	For (i, n - 1) {
		int a, b;
		cin >> a >> b;

		G[a].push_back(b);
		G[b].push_back(a);

		deg[a]++;
		deg[b]++;
	}

	for (int i = 1; i <= n; i++) {
		if (deg[i] == 1) {
			find_center(i, k, -1);
			break;
		}
	}

	// error(center);

	if (center != -1 && is_hedge(center, k, -1)) cout << "Yes\n";
	else cout << "No\n";
}

