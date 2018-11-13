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

const int N = 3 * 1000 * 1000 + 10;
pll ps[N];
const ll inf = (1LL<<60);

ll sum_p(pll arr[], int n) {
	ll total = 0;
	For (i, n) {
		total += abs(ps[i].first - ps[(i + 1) % n].first) + abs(ps[i].second - ps[(i + 1) % n].second);
	}
}

int main() {
    _upgrade;
	int n; 
	cin >> n;

	pll b = {inf, inf};
	pll t = {inf, -inf};
	pll l = {inf, inf};
	pll r = {-inf, inf};
	
	For (i, n) {
		cin >> ps[i].first >> ps[i].second;

		if (ps[i].first < l.first) l = ps[i];

		if (ps[i].first > r.first) r = ps[i];

		if (ps[i].second > t.second) t = ps[i];

		if (ps[i].second < b.second) b = ps[i];
	}

	

	// error(r.first, r.second, l.first, l.second, b.first, b.second, t.first, t.second);
	// error(total,  (r.first - l.first + t.second - b.second));
	
	// assert(total == 2LL * (r.first - l.first + t.second - b.second));


	pll arr[] = {b, r, t, l};
	ll best3 = 0;

	For (i, 4) {
		vector<pll> p; 
		For (j, 4) {
			if (i == j) continue;
			p.push_back(arr[j]);
		}

		ll curr = 0;
		For (j, 3) {
			curr += abs(p[j].first - p[(j + 1) % 3].first) + abs(p[j].second - p[(j + 1) % 3].second);
		}

		best3 = max(best3, curr);
	}

	cout << best3 << " ";
	For (i, n - 3) {
		cout << total << " ";
	}
}

