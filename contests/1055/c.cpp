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

const int LIMIT = 1 * 1000 * 1000;

vector<ll> rems (ll a, ll b) {
	vector<ll> res;
	unordered_set<ll> vis;

	ll k = 1;
	while (true) {
		ll rem = (a * k) % b;
		if (vis.find(rem) != end(vis) || vis.size() > LIMIT) return res; 

		res.push_back(rem);
		vis.insert(rem);
		k++;
	}
}

ll solve(ll la, ll ra, ll ta, ll lb, ll rb, ll tb) {
	// error(la, ra, lb, rb);
	if (ta > tb) {
		swap(ta, tb);
		swap(ra, rb);
		swap(la, lb);
		// error(la, ra, lb, rb);
	}

	lb -= la;
	rb -= la;
	ra -= la;
	la -= la;

	// error(la, ra, lb, rb);

	if (lb < 0) {
		ll mult = ((abs(lb) / tb) + 1);
		// error(mult);

		lb += tb * mult;
		rb += tb * mult;
	}
	// error(la, ra, lb, rb);

	ll res = 0;
	ll before = (lb / ta) * ta;
	
	ll len_a = ra - la + 1;
	ll len_b = rb - lb + 1;
	
	res = max(res, min(len_a - (lb - before), len_b));
	ll after = before + ta;
	res = max(res, min(len_b - (after - lb), len_a));

	ll offset = lb % ta;
	auto rs = rems(tb, ta);

	if (rs.size() >= LIMIT) {
		return max(res, min(len_a, len_b));
	}

	for (auto& x : rs) {
		ll proper = (x + ta - offset) % ta;
		res = max(res, min(len_b - proper, len_a));
	}

	return res;
}

int main() {
    _upgrade;
	ll la, ra, ta;
	cin >> la >> ra >> ta;
	ll lb, rb, tb;
	cin >> lb >> rb >> tb;

	ll res = solve(la, ra, ta, lb, rb, tb);
	if (ta < tb) {
		res = max(res, solve(la, ra, ta * ((tb / ta) + 1), lb, rb, tb));
	} else {
		res = max(res, solve(la, ra, ta, lb, rb, tb * ((ta / tb) + 1) ));
	}

	cout << res << "\n";
}

