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

const ll MOD = 1000 * 1000 * 1000 + 7;

int main() {
    _upgrade;
	int n; 
	cin >> n;

	ll res = 1;

	priority_queue<ll> buy, sell_minus;
	unordered_set<ll> unkown;

	For (i, n) {
		string s;
		ll price; 
		cin >> s >> price;

		error(s, price);

		if (s == "ADD") {
			if (sell_minus.size() && price > -sell_minus.top()) 
				sell_minus.push(-price);
			else if (buy.size() && price < buy.top()) 
				buy.push(price);
			else {
				unkown.insert(price);
			}
		} else {
			if (unkown.find(price) != unkown.end()) {
				// cout << "here1\n";
				res *= 2LL;
				res %= MOD;
			} else {
				// cout << "here2\n";

				if (sell_minus.size() && -sell_minus.top() == price) 
					sell_minus.pop();
				else if (buy.size() && buy.top() == price) 
					buy.pop();
				else {
					cout << "0\n";
					return 0;
				}
			}

			for (auto p : unkown) {
				if (p < price) {
					buy.push(p);
				} else if (p > price) sell_minus.push(-p);
			}

			unkown.clear();
		}
	}

	// error(unkown.size());

	cout << (res * (1LL + (ll)unkown.size())) % MOD << "\n";
}

