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

pair<int, pair<vector<int>, vector<int>>> get_res(int n, int m) {
	vector<int> a, b;
	int sum_a = 0;
	int ind = 1;
	
	while (sum_a + ind <= n) {
		sum_a += ind;
		a.push_back(ind);
		ind++;
	}

	int extra = 0;

	if (sum_a < n) {
		int extra_sum = 0;
		int orig_size = a.size();
		ForD (i, a.size()) {
			extra_sum++;
			if (sum_a + extra_sum == n) {
				for (int j = a.size() - 1; j >= i; j--) {
					extra = a.back();
					a.pop_back();
				}
				
				for (int j = i; j < orig_size; j++) {
					a.push_back(j + 2);
				}
				sum_a += extra_sum;
				ind++;
				break;
			}
		}
	}

	// error(extra, ind);

	int sum_b = 0;
	if (extra > 0 && extra <= m) {
		b.push_back(extra);
		sum_b += extra;
	}

	// error(sum_b);
	// cout << "\n-----\n";

	while (sum_b + ind <= m) {
		sum_b += ind;
		b.push_back(ind);
		ind++;
	}

	return {a.size() + b.size(), {a, b}};
}

int main() {
    _upgrade;
	int n, m;
	cin >> n >> m;

	auto res1 = get_res(n, m);
	auto res2 = get_res(m, n);

	// reverse

	auto res = res1.first > res2.first ? res1 : res2;
	if (res2.first >= res1.first) {
		swap(res.second.first, res.second.second);
	}

	cout << res.second.first.size() << "\n";
	for (auto x : res.second.first) {
		cout << x << " ";
	}
	cout << "\n";

	cout << res.second.second.size() << "\n";
	for (auto x : res.second.second) {
		cout << x << " ";
	}
	cout << "\n";
}

