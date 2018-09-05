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

int nums[100];

int main() {
    _upgrade;
	int n, a, b;
	cin >> n >> a >> b;
	

	For (i, n) {
		cin >> nums[i];
	}

	int cost = 0;
	bool broken = false; 

	For (i, n / 2) {
		int j = n - i - 1;
		if (nums[i] != nums[j] && (nums[i] != 2 && nums[j] != 2)) {
      broken= true;
      break;
    } else if (nums[i] == 2 && nums[j] == 2) {
      cost += 2 * min(a, b);
    } else if (nums[i] != nums[j]) {
      if (min(nums[i], nums[j]) == 0) cost += a;
      else cost += b;
    }
	}

  if (n % 2 == 1 && nums[n / 2] == 2) cost += min(a, b);

  if (!broken) cout << cost << "\n";
  else cout << "-1\n";
}

