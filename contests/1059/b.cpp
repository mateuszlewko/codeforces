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
int check[N][N];
vector<pii> rect;

int n, m;

inline bool valid(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return false;
	return true;
}

bool check_p(const pii & p, const pii & offset) {
	for (pii x : rect) {
		int a = p.first + x.first - offset.first;
		int b = p.second + x.second - offset.second;
		if (!valid(a, b) || !check[a][b]) {
			return false;
		}
	}

	return true;
}

int main() {
    _upgrade;
	cin >> n >> m;
	vector<pii> ps; 

	For (i, n) {
		string s;
		cin >> s;
		For (j, s.size()) {
			if (s[j] == '#') {
				ps.push_back({i, j});
				check[i][j] = true;
			}
		}
	}

	For (i, 3) 
		For (j, 3) {
			if (i != 1 || j != 1) {
				rect.push_back({i, j});
			}
		}

	random_shuffle(ps.begin(), ps.end());

	for (pii p : ps) {
		bool any = false;
		for (pii& offset : rect) {
			if (check_p(p, offset)) {
				any = true;
				break;
			}
		}

		if (!any) {
			cout << "NO\n";
			return 0;
		}
	}

	cout << "YES\n";
}

