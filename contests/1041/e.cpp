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
int cnt[N];

int main() {
    _upgrade;
	int n; 
	cin >> n;

	For (i, n - 1) {
		int a, b; 
		cin >> a >> b;
		if (a > b) swap(a, b);
		if (b != n) {
			cout << "NO\n";
			return 0;
		}

		cnt[a]++;
	}

	priority_queue<int> Q;
	vector<int> present;

	for (int i = 1; i < n; i++) {
		if (cnt[i] == 0) {
			Q.push(i);
		} else {
			present.push_back(i);
		}
	}

	vector<int> res; 
	res.push_back(n);

	ForD (i, present.size()) {
		int x = present[i];
		while (cnt[x] > 1) {
			if (Q.empty()) {
				cout << "NO\n";
				return 0;
			}

			int top = Q.top();
			
			if (top > x) {
				cout << "NO\n";
				return 0;
			}

			res.push_back(Q.top());
			Q.pop();
			cnt[x]--;
		}
		res.push_back(x);
	}

	if (Q.size()) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES\n";
	For (i, res.size() - 1) {
		cout << res[i] << " " << res[i + 1] << "\n";
	}
	cout << "\n";
}

