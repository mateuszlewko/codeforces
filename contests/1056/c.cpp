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

const int N = 2010;
int nums[N];
int other[N];
bool used[N];

int main() {
    _upgrade;

	int n, m;
	cin >> n >> m;

	For (i, 2 * n) {
		other[i] = -1;
		cin >> nums[i];
	}

	vector<pii> ps;

	For (i, m) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		other[a] = b;
		other[b] = a;

		ps.push_back({a, b});
	}

	vector<pair<int, int>> avail;

	For (i, 2 * n) {
		if (other[i] == -1) {
			avail.push_back({nums[i], i});
		}
	}

	SORT(avail);

	int t;
	cin >> t;
	int rounds = 0;

	if (t == 1) {
		while (true) {
			rounds++;

			while (ps.size() && (used[ps.back().first] || used[ps.back().second]))
				ps.pop_back();

			while (avail.size() && used[avail.back().second]) 
				avail.pop_back();

			if (ps.size()) {
				auto p = ps.back();
				ps.pop_back();
				used[p.first] = used[p.second] = true;

				if (nums[p.first] > nums[p.second]) {
					cout << p.first + 1 << endl;
				} else cout << p.second + 1 << endl;
			} else if (avail.size()) {
				auto p = avail.back();
				avail.pop_back();
				cout << p.second + 1 << endl;
			} else {
				return 0;
			}

			while (ps.size() && (used[ps.back().first] || used[ps.back().second]))
				ps.pop_back();
		
			while (avail.size() && used[avail.back().second]) 
				avail.pop_back();

			int opp;
			if (avail.size() || ps.size())
				cin >> opp;
			else {
				assert(rounds == n);
				return 0;
			}

			if (opp == -1) return 11;

			used[opp - 1] = true;
		}
	} else {
		while (true) {
			rounds++;

			while (ps.size() && (used[ps.back().first] || used[ps.back().second]))
				ps.pop_back();
		
			while (avail.size() && used[avail.back().second]) 
				avail.pop_back();

			int opp;
			if (rounds <= n) 
				cin >> opp;
			else return 0;

			if (opp == -1) return 11;
			opp--;

			if (other[opp] == -1) used[opp] = true;

			while (ps.size() && (used[ps.back().first] || used[ps.back().second]))
				ps.pop_back();
		
			while (avail.size() && used[avail.back().second]) 
				avail.pop_back();

			if (other[opp] != -1 && !used[opp]) {
				used[opp] = true;
				used[other[opp]] = true;
				cout << other[opp] + 1 << endl;
			} else if (ps.size()) {
				used[opp] = true;
				auto p = ps.back();
				ps.pop_back();
				// cout << "here" << endl;
				used[p.first] = used[p.second] = true;

				if (nums[p.first] > nums[p.second]) {
					cout << p.first + 1 << endl;
				} else cout << p.second + 1 << endl;
			} else if (avail.size()) {
				used[opp] = true;
				auto p = avail.back();
				used[p.second] = true;
				// cout << "here2" << endl;
				avail.pop_back();
				cout << p.second + 1 << endl;
			} else {
				return 0;
			}
		}
	}
}

