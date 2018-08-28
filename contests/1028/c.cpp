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

optional<sqr> intersect(const optional<sqr>& l_opt, const sqr& r) {
	if (!l_opt.has_value()) return nullopt;
	auto l = l_opt.value();

	pii bl = {max(l.first.first, r.first.first), max(l.first.second, r.first.second)};
	pii tr = {min(l.second.first, r.second.first), min(l.second.second, r.second.second)};

	if (bl.first > tr.first || bl.second > tr.second) 
		return nullopt;

	return optional<sqr>{{bl, tr}};
}

const int N = 150 * 1000;
sqr sqrs[N];

optional<sqr> pref[N], suf[N];

void print_val(optional<sqr> s) {
	cout << s.value().first.first << " " << s.value().first.second << "\n";
	exit(0);
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

	pref[0] = optional<sqr>{sqrs[0]};
	For (i, n - 1) { 
		pref[i + 1] = intersect(pref[i], sqrs[i + 1]); 
		// bool has = pref[i + 1].has_value();
		// error(i+1, has);
	}
	
	suf[n - 1] = optional<sqr>{sqrs[n - 1]};
	ForD (i, n - 1) suf[i] = intersect(suf[i + 1], sqrs[i]);

	For (i, n) {
		if (i == 0) {
			if (suf[1].has_value()) print_val(suf[i + 1]);
		}
		else if (i == n - 1) {
			// error(pref[i - 1].has_value());
			if (pref[i - 1].has_value()) print_val(pref[i - 1]);
		}
		else if (suf[i + 1].has_value()) {
			auto res = intersect(pref[i - 1], suf[i + 1].value());
			if (res.has_value()) {
				print_val(res);
			}
		}
	}

	return 33;
}

