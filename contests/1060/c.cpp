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

auto sums(int n) {
	vector<ll> pref;
	pref.push_back(0);

	For (i, n) {
		int x;
		cin >> x;
		pref.push_back(pref.back() + x);
	}

	vector<pair<ll, int>> res;
	for (int i = 0; i < pref.size(); i++) {
		for (int j = i + 1; j < pref.size(); j++) {
			// error(pref[j]-pref[i], i, j);
			res.push_back({pref[j] - pref[i], j - i});
		}
	}

	return res;
}

int main() {
    _upgrade;
	int n, m; 
	cin >> n >> m;

	auto l = sums(n);
	auto r = sums(m);

	ll x;
	cin >> x;

	ll best = 0;
	SORT(r);

	ForD(i, (int)r.size() - 1) {
		if (r[i + 1].first == r[i].first)
			r[i].second = r[i + 1].second;
	}

	For (i, (int)r.size() - 1) {
		r[i + 1].second = max(r[i + 1].second, r[i].second);
	}

	for (auto s : l) {
		// error(s.first, s.second);

		size_t pos = upper_bound(begin(r), end(r), make_pair(x / s.first, n + m)) - begin(r);
		if (pos == 0) continue;
		pos--;
		if (s.first * r[pos].first > x) continue;
		
		best = max(best, (ll)r[pos].second * s.second);
	}

	cout << best << "\n";
}

