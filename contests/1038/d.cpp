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

const int N = 500 * 1000 + 10;
ll nums[N];

int main() {
    _upgrade;
	int n;
	cin >> n;

	For (i, n) {
		cin >> nums[i];
	}

	if (n == 1) {
		cout << nums[0];
		return 0;
	}

	// ll sum = 0;
	int found = -1;
	For (i, n - 1) {
		ll sgn = nums[i] * nums[i + 1];
		// sum += nums[i];

		if (sgn < 0) {
			found = i + 1; 
			break;
		} else if (sgn == 0) {
			if (nums[i] != 0) {
				nums[i] = -nums[i];
				found = i; 
				break;
			} else if (nums[i + 1] != 0) {
				nums[i + 1] = -nums[i + 1];
				found = i + 1;
			}
		}
	}

	ll sum = 0;
	For (i, n)
		sum += abs(nums[i]);

	if (found != -1) {
		cout << sum << "\n";
	} else {
		ll mn = abs(nums[0]);
		For (i, n - 1)
			mn = min(mn, abs(nums[i + 1]));

		cout << sum - 2 * mn;
	}	
}

