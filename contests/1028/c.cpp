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

#include <optional>

typedef pair<pii, pii> sqr;

optional<sqr> intersect(const sqr& l, const sqr& r) {
	pii bl = {max(l.first.first, r.first.first), max(l.first.second, r.first.second)};
	pii tr = {min(l.second.first, r.second.first), min(l.second.second, r.second.second)};

	if (bl.first > tr.first || bl.second > tr.second) 
		return nullopt;

	return optional<sqr>{{bl, tr}};
}

const int N = 150 * 1000;
sqr sqrs[N];

optional<sqr> all_inter(sqr curr, int i, int n, bool can_skip) {
	if (i == n) return curr;

	if (auto next = intersect(curr, sqrs[i])) {
		return all_inter(next.value(), i + 1, n, can_skip);
	} else {
		if (can_skip) return all_inter(curr, i + 1, n, false);
		return nullopt; 
	}
}

bool test(int a, int b, int n) {
	if (auto opt = intersect(sqrs[a], sqrs[b])) {
		optional<sqr> res_opt = all_inter(opt.value(), 0, n, true);	
		
		if (res_opt.has_value()) {
			auto res = res_opt.value();

			cout << res.first.first << " " << res.first.second << "\n";
			return true;
		}
	} else return false;

	return false;
}

int main() {
    _upgrade;
	int n; 
	cin >> n;

	For (i, n) {
		cin >> sqrs[i].first.first >> sqrs[i].first.second 
		    >> sqrs[i].second.first >> sqrs[i].second.second;
	}

	if (n == 2) {
		cout << sqrs[0].first.first << " " << sqrs[0].first.second << "\n";
		return 0;
	}

	bool found = test(rand() % n, rand() % n, n);

	while (!found) {
		int a = rand() % n; 
		int b = rand() % n; 

		if (a == b) continue;
		found = test(a, b, n);
	}
}

