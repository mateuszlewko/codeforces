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

const int N = 505;
int deg[N];

int main() {
    _upgrade;

	int n;
	cin >> n;

	vector<int> on_path;
	vector<int> on_path2;
	vector<int> ends;

	int left_sum = 0;

	For (i, n) {
		cin >> deg[i + 1];
		if (deg[i + 1] > 1) {
			on_path.push_back(i + 1);
			on_path2.push_back(i + 1);
			deg[i + 1] -= 2;
			left_sum += deg[i + 1];
		} else ends.push_back(i + 1);
	}


	if (left_sum + 2 < (int)ends.size()) {
		cout << "NO\n";
		return 0;
	}

	int diam = (int)on_path.size() + min(2, (int)ends.size()) - 1;
	// cout << "YES " << diam << "\n";
	vector<pii> result;

	if (ends.size() > 0 && on_path.size() > 0) {
		result.push_back({on_path[0], ends.back()});
		ends.pop_back();
	}

	if (ends.size() > 0 && on_path.size() > 0) {
		result.push_back({on_path.back(), ends.back()});
		ends.pop_back();
	}

	bool wrong = false;

	while (ends.size()) {
		while (on_path.size() && deg[on_path.back()] <= 0) on_path.pop_back();

		if (on_path.empty()) {
			wrong = true;
			break;
		}

		int u = ends.back();
		ends.pop_back();
		int v = on_path.back();

		result.push_back({u, v});
		deg[v]--;
	}

	For (i, int(on_path2.size()) - 1) {
		result.push_back({on_path2[i], on_path2[i + 1]});
	}

	if (wrong) {
		cout << "NO\n";
		return 0;
	}

	cout << "YES " << diam << "\n";
	cout << result.size() << "\n";

	for (auto p : result) {
		cout << p.first << " " << p.second << "\n";
	}
}

