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

ll make_move(ll ascore, ll bscore, bool which, priority_queue<pll> & my, priority_queue<pll> & other) {
	if (my.empty() && other.empty()) return ascore - bscore;

	if (which == false) {
		if (my.empty() || (other.size() && other.top().first > my.top().first)) {
			other.pop();
			return make_move(ascore, bscore, !which, other, my);
		} else {
			ascore += my.top().first;
			my.pop();
			return make_move(ascore, bscore, !which, other, my);
		}
	} else {
		if (my.empty() || (other.size() && other.top().first > my.top().first)) {
			other.pop();
			return make_move(ascore, bscore, !which, other, my);
		} else {
			bscore += my.top().first;
			my.pop();
			return make_move(ascore, bscore, !which, other, my);
		}
	}
}

int main() {
    _upgrade;
	int n; 
	cin >> n;

	priority_queue<pll> A, B; 

	For (i, n) {
		int a;
		cin >> a;
		A.push({a, i});
	}

	For (i, n) {
		int a;
		cin >> a;
		B.push({a, i});
	}

	ll res = make_move(0, 0, false, A, B);
	cout << res << "\n";
}

