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
vector<int> G[N];

ll sum[N];
ll ans[N];

bool wrong = false;

void go(bool odd, int x, ll curr_sum) {
	if (odd) {
		ll m = 1LL << 60;
		for (int y : G[x]) {
			m = min(sum[y], m);
		}

		if (m < curr_sum) {
			wrong = true;
			return;
		}

		if (m < (1LL<<60)) 
			ans[x] = m - curr_sum;
		else ans[x] = 0;

		for (int y : G[x]) {
			go(false, y, m);
		}
	} else {
		ans[x] = sum[x] - curr_sum;
		
		if (ans[x] < 0) {
			wrong = true;
			return;
		}

		curr_sum = sum[x];
		for (int y : G[x]) go(true, y, curr_sum);
	}
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	For (i, n - 1) {
		int p;
		cin >> p;
		G[p].push_back(i + 2);
	} 

	For (i, n) {
		cin >> sum[i + 1];
	}

	go(false, 1, 0);
	if (wrong) {
		cout << "-1\n";
	} else {
		ll s = 0;
		For (i, n + 2) s += ans[i];
		cout << s << "\n";
	}

}

