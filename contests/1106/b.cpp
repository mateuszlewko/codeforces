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
int cost[N];
int cnt[N];

int main() {
    _upgrade;

	int n, m;
	cin >> n >> m;

	set<pair<int, int>> cheap;

	ll total = 0;

	For (i, n) {
		cin >> cnt[i + 1];
		total += cnt[i + 1];
	}

	For (i, n) {
		cin >> cost[i + 1];
	}

	for (int i = 1; i <= n; i++) {
		cheap.insert({cost[i], i});
	}

	For (i, m) {
		int kind, num; 
		cin >> kind >> num;

		ll pay = 0;
		// if (num > total) {
		// 	cout << "0\n";
		// 	continue;
		// }

		int take = min(cnt[kind], num);
		cnt[kind] -= take;

		if (cnt[kind] == 0) {
			auto it = cheap.find({cost[kind], kind});
			if (it != cheap.end()) cheap.erase(it);
		}

		pay += (ll)take * cost[kind];
		num -= take;
		total -= take;

		while (num > 0 && cheap.size()) {
			auto c = *cheap.begin();
			int take2 = min(cnt[c.second], num);
			pay += (ll)cost[c.second] * take2;
			
			num -= take2;
			cnt[c.second] -= take2;
			total -= take2;

			if (cnt[c.second] == 0) cheap.erase(c);
		}

		if (num == 0) cout << pay << "\n";
		else cout << "0\n";
	}

}

