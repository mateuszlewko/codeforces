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

const int N = 3 * 100 * 1000 + 10;
int cnts[N];
ll sum_pref[N];
ll sum_cnt[2][N];
int many[100];

int main() {
    _upgrade;
	int n;
	cin >> n;

	For(i, n) {
		ll x; 
		cin >> x;
		cnts[i] = __builtin_popcountll(x);
	}

	For (i, n) {
		sum_pref[i + 1] = sum_pref[i] + cnts[i];
	}

	sum_cnt[0][0] = 1;
	For (i, n) {
		For (j, 2) {
			sum_cnt[j][i + 1] = sum_cnt[j][i] + (sum_pref[i + 1] % 2 == j ? 1 : 0);
		}
	}

	// For 

	ll res = 0;
	int ind = 0;
	ll sum = 0;

	// For (i, n) {
	// 	int c = cnts[i];

	// 	For (j, 36) {
	// 		if (many[j] != 0) {
	// 			many[j + c]++;
	// 			many[abs(j - c)]++;
	// 		}
	// 	}
	// 	res += many[0];
	// 	many[c]++;
	// }

	cout << res << "\n";
}

