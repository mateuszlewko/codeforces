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

const int N = 2 * 100 * 1000 + 10;
int cnt[N];

int main() {
    _upgrade;

	int n, k;
	cin >> n >> k;

	int maxH = 0;
	int minH = N;

	For (i, n) {
		int h;
		cin >> h;
		maxH = max(maxH, h);
		minH = min(minH, h);
		cnt[h]++;
	}

	int res = 0;
	ll curr_sum = 0;
	int curr_cnt = 0;

	for (int i = maxH; i >= minH; i--) {
		if (curr_sum + curr_cnt > (ll)k) {
			res++;
			curr_sum = 0;
		}

		curr_sum += curr_cnt;
		curr_cnt += cnt[i];
	}

	if (curr_sum > 0) res++;
	// error(curr_sum, curr_cnt);

	cout << res << "\n";
}

