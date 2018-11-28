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
vector<pair<ll, int>> type[N];

vector<ll> height_sums[N];

int max_h[N];

int main() {
    _upgrade;

	int n, m;
	cin >> n >> m;

	For (i, n) {
		ll l, r;
		cin >> l >> r;
		type[l].push_back({r, i + 1});
	}

	For (i, m) {
		int t = i + 1;
		SORT(type[t]);
		reverse(type[t].begin(), type[t].end());

		ll sum = 0;
		For (j, type[t].size()) {
			if (type[t][j].first + sum > 0)	{
				sum += type[t][j].first;
				height_sums[j + 1].push_back(sum);
				max_h[t] = j + 1;
			} else break;
		}
	}

	ll best = 0;
	int which_h = 0;

	For (i, n) {
		int t = i + 1;
		ll sum = 0;

		for (auto s : height_sums[t]) sum += s;

		if (best < sum) {
			best = sum;
			which_h = t;
		}
	}

	cout << best << "\n";
}

