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
#pragma endregion 

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int N = 200 * 1000 + 200;
int end_ix[N];
int beg_ix[N];
int nums[N];

vector<int> enter[N];
vector<int> exit_[N];

int can_place = -1;

int main() {
    _upgrade;
	int n, q;
	cin >> n >> q;

	For (i, N) {
		beg_ix[i] = end_ix[i] = -1;
	}

	For (i, n) {
		cin >> nums[i];

		if (nums[i] == 0) continue;

		if (beg_ix[nums[i]] != -1) {
			end_ix[nums[i]] = i + 1;

			enter[beg_ix[nums[i]]].push_back(nums[i]);
			exit_[i + 1].push_back(nums[i]);
		}
		else beg_ix[nums[i]] = i;
	}

	map<int, int> Q;
	For (i, n) {
		for (int x : exit_[i]) { 
			Q[x] -= 1;
			if (Q[x] == 0) Q.erase(x);
		}
		for (int x : enter[i]) Q[x] = Q[x] + 1;

		int mx = Q.empty() ? 1 : (*Q.rbegin()).first;
		// error(i, mx);

		if (nums[i] > q) {
			cout << "NO\n";
			return 0;
		}

		if (nums[i] == 0) {
			nums[i] = mx;
			can_place = i;
		} else if (nums[i] < mx) {
			cout << "NO\n";
			return 0;
		}
	}

	bool is_max = false;
	For (i, n) if (nums[i] == q) { is_max = true; break; }

	if (!is_max && can_place == -1) {
		cout << "NO\n";
		return 0;
	} else if (!is_max) {
		nums[can_place] = q;
	}

	cout << "YES\n";
	For (i, n) cout << nums[i] << " ";
}

