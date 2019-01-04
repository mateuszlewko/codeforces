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

const int N = 1010;
pii xs[N];
pii cs[N];

bool check(pii target, int n) {
	set<pii> avail;
	For (i, n) {
		avail.insert(xs[i]);
	}

	For (i, n) {
		auto c = cs[i];
		auto it = avail.find({target.first - c.first, target.second - c.second});
		if (it == avail.end()) return false;
		else avail.erase(it);
	}

	return true;
}

int main() {
    _upgrade;

	int n;
	cin >> n;

	For (i, n) cin >> xs[i].first >> xs[i].second;
	For (i, n) cin >> cs[i].first >> cs[i].second;

	For (j, n) {
		pii target = {xs[0].first + cs[j].first, xs[0].second + cs[j].second};
		if (check(target, n)) {
			cout << target.first << " " << target.second << "\n";
			return 0;
		}
	}
}

