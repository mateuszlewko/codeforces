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
int A[12][N];
int pos[12];
int num_pos[12][N];

int main() {
    _upgrade;
	int n, m;
	cin >> n >> m;

	For (i, m) {
		For (j, n) { 
			cin >> A[i][j];
			num_pos[i][A[i][j]] = j;
		}
	}

	if (m == 1) {
		cout << (ll)n * (ll)(n + 1) / 2LL << "\n";
		return 0;
	} 

	int len = 1;
	for (int i = 1; i < m; i++) {
		pos[i] = num_pos[i][A[0][0]];
	}

	ll res = 1;

	for (int i = 1; i < n; i++) {
		bool any_wrong = false;
		for (int j = 1; j < m; j++) {
			if (pos[j] + len >= n || A[j][pos[j] + len] != A[0][i]) {
				any_wrong = true;
				break;
			}
		}

		// error(i, any_wrong);
		if (any_wrong) {
			len = 1;
			for (int j = 1; j < m; j++) {
				pos[j] = num_pos[j][A[0][i]];
				// error(j, pos[j]);
			}
		} else {
			len++;
		}

		res += len;
	}

	cout << res << "\n";
}

