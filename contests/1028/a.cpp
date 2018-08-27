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

const int N = 120;
string rows[N];

int main() {
    _upgrade;
	int n, m;
	cin >> n >> m;

	pii pos = {-1, -1};

	For (i, n) {
		cin >> rows[i];
		if (pos.first == -1) {
			For (j, rows[i].size()) {
				if (rows[i][j] == 'B') {
					pos = {i, j};
					break;
				}
			}
		}
	}

	int cnt = 0;
	for (int j = pos.second; j < m; j++) {
		if (rows[pos.first][j] != 'B') break;
		cnt++;
	}

	cout << pos.first + cnt / 2 + 1 << " " << pos.second + cnt / 2 + 1 << "\n";
}

