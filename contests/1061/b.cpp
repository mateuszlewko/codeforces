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

unordered_map<ll, int> heights_cnt;

int main() {
    _upgrade;
	ll n, m;
	cin >> n >> m;

	ll total = 0;

	For (i, n) {
		ll x;
		cin >> x;
		total += x;

		heights_cnt[x]++;
	}

	vector<pair<ll, int>> hs; 
	for (auto it : heights_cnt) {
		hs.push_back(it);
	}

	SORT(hs);
	ll need = n;
	int h_n = hs.size();

	int left = hs[h_n - 1].second - 1;
	ll curr_h = hs[h_n - 1].first;

	for (int i = h_n - 2; i >= 0; i--) {
		ll h = hs[i].first;
		int add_cnt = hs[i].second;
		ll h_delta = curr_h - h - 1;

		if (h_delta > left) {
			need += h_delta - left;
			left = 0;
		} else {
			left -= h_delta;
		}

		left += add_cnt - 1;
		curr_h = h;
	}

	if (left < curr_h - 1) {
		need += (curr_h - 1) - left;
	}

	cout << total - need << "\n";
}

